/* Copyright (C) Olivier Bertrand 2004 - 2012

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

/***********************************************************************/
/*  Author Olivier BERTRAND  bertrandop@gmail.com         2004-2012    */
/*                                                                     */
/* WHAT THIS PROGRAM DOES:                                             */
/* -----------------------                                             */
/*  This program are the CONNECT general purpose semantic routines.    */
/***********************************************************************/
#ifdef USE_PRAGMA_IMPLEMENTATION
#pragma implementation        // gcc: Class implementation
#endif

/***********************************************************************/
/*  Include application header files                                   */
/*                                                                     */
/*  global.h     is header containing all global declarations.         */
/*  plgdbsem.h   is header containing the DB applic. declarations.     */
/***********************************************************************/
#define DONT_DEFINE_VOID
#include "handler.h"
#undef  OFFSET

#include "global.h"
#include "plgdbsem.h"
#include "xobject.h"
#include "connect.h"
#include "tabcol.h"
#include "catalog.h"
#include "ha_connect.h"
#include "mycat.h"

#define my_strupr(p) my_caseup_str(default_charset_info, (p));
#define my_strlwr(p) my_casedn_str(default_charset_info, (p));
#define my_stricmp(a, b) my_strcasecmp(default_charset_info, (a), (b))

/***********************************************************************/
/*  DB static variables.                                               */
/***********************************************************************/
extern int xtrace;

/***********************************************************************/
/*  Routines called internally by semantic routines.                   */
/***********************************************************************/
void  CntEndDB(PGLOBAL);
RCODE EvalColumns(PGLOBAL g, PTDB tdbp);

/***********************************************************************/
/*  MySQL routines called externally by semantic routines.             */
/***********************************************************************/
int rename_file_ext(const char *from, const char *to,const char *ext);

/***********************************************************************/
/*  CntExit: CONNECT termination routine.                              */
/***********************************************************************/
PGLOBAL CntExit(PGLOBAL g)
  {
  if (g) {
    CntEndDB(g);

    if (g->Activityp)
      delete g->Activityp;

    PlugExit(g);
    g= NULL;
    } // endif g

  return g;
  } // end of CntExit

/***********************************************************************/
/*  CntEndDB: DB termination semantic routine.                         */
/***********************************************************************/
void CntEndDB(PGLOBAL g)
  {
  PDBUSER dbuserp= PlgGetUser(g);

  if (dbuserp) {
    if (dbuserp->Catalog)
      delete dbuserp->Catalog;

    free(dbuserp);
    } // endif dbuserp

  } // end of CntEndDB

/***********************************************************************/
/*  CntCheckDB: Initialize a DB application session.                   */
/*  Note: because MySQL does not call a storage handler when a user    */
/*  executes a use db command, a check must be done before an SQL      */
/*  command is executed to check whether we are still working on the   */
/*  current database, and if not to load the newly used database.      */
/***********************************************************************/
bool CntCheckDB(PGLOBAL g, PHC handler, const char *pathname)
  {
  bool    rc= false;
  PDBUSER dbuserp= PlgGetUser(g);

  if (xtrace) {
    printf("CntCheckDB: dbuserp=%p\n", dbuserp);
    } // endif xtrace

  if (!dbuserp || !handler)
    return true;

  if (xtrace)
    printf("cat=%p oldhandler=%p newhandler=%p\n", dbuserp->Catalog,
    (dbuserp->Catalog) ? ((MYCAT*)dbuserp->Catalog)->GetHandler() : NULL,
           handler);

  if (dbuserp->Catalog) {
//  ((MYCAT *)dbuserp->Catalog)->SetHandler(handler);   done later
    ((MYCAT *)dbuserp->Catalog)->SetDataPath(g, pathname);
    return false;                       // Nothing else to do
    } // endif Catalog

  // Copy new database name in dbuser block
  strncpy(dbuserp->Name, "???", sizeof(dbuserp->Name) - 1);

  dbuserp->Vtdbno= 0;                      // Init of TDB numbers

  /*********************************************************************/
  /*  Now allocate and initialize the Database Catalog.                */
  /*********************************************************************/
  dbuserp->Step= MSG(READY);

  if (!(dbuserp->Catalog= new MYCAT(handler)))
    return true;

  ((MYCAT *)dbuserp->Catalog)->SetDataPath(g, pathname);
  dbuserp->UseTemp= TMP_YES;   // Must use temporary file

  /*********************************************************************/
  /*  All is correct.                                                  */
  /*********************************************************************/
  sprintf(g->Message, MSG(DATABASE_LOADED), "???");

  if (xtrace)
    printf("msg=%s\n", g->Message);

  return rc;
  } // end of CntCheckDB

/***********************************************************************/
/*  CntInfo: Get table info.                                           */
/*  Returns valid: true if this is a table info.                       */
/***********************************************************************/
bool CntInfo(PGLOBAL g, PTDB tp, PXF info)
  {
  bool    b;
  PTDBDOS tdbp= (PTDBDOS)tp;

  if (tdbp) {
    b= tdbp->GetFtype() != RECFM_NAF;
    info->data_file_length= (b) ? (ulonglong)tdbp->GetFileLength(g) : 0;
    info->records= (unsigned)tdbp->GetMaxSize(g);
//  info->mean_rec_length= tdbp->GetLrecl();
    info->mean_rec_length= 0;
    info->data_file_name= (b) ? tdbp->GetFile(g) : NULL;
    return true;
  } else {
    info->data_file_length= 0;
    info->records= 0;
    info->mean_rec_length= 0;
    info->data_file_name= NULL;
    return false;
  } // endif tdbp

  } // end of CntInfo

/***********************************************************************/
/*  GetTDB: Get the table description block of a CONNECT table.        */
/***********************************************************************/
PTDB CntGetTDB(PGLOBAL g, LPCSTR name, MODE mode, PHC h)
  {
  int      rc;
  PTDB    tdbp;
  PTABLE  tabp;
  PDBUSER dup= PlgGetUser(g);
  PCATLG  cat= (dup) ? dup->Catalog : NULL;     // Safe over longjmp

  if (xtrace)
    printf("CntGetTDB: name=%s mode=%d cat=%p\n", name, mode, cat);

  if (!cat)
    return NULL;

  // Save stack and allocation environment and prepare error return
  if (g->jump_level == MAX_JUMP) {
    strcpy(g->Message, MSG(TOO_MANY_JUMPS));
    return NULL;
    } // endif jump_level

  if ((rc= setjmp(g->jumper[++g->jump_level])) != 0) {
    tdbp= NULL;
    goto err;
    } // endif rc

  // Get table object from the catalog
  tabp= new(g) XTAB(name);

  if (xtrace)
    printf("CntGetTDB: tabp=%p\n", tabp);

  // Perhaps this should be made thread safe
  ((MYCAT*)cat)->SetHandler(h);

  if (!(tdbp= cat->GetTable(g, tabp, mode)))
    printf("CntGetTDB: %s\n", g->Message);

 err:
  if (xtrace)
    printf("Returning tdbp=%p mode=%d\n", tdbp, mode);

  g->jump_level--;
  return tdbp;
  } // end of CntGetTDB

/***********************************************************************/
/*  OPENTAB: Open a Table.                                             */
/***********************************************************************/
bool CntOpenTable(PGLOBAL g, PTDB tdbp, MODE mode, char *c1, char *c2,
                                        bool del, PHC h)
  {
  char   *p;
  int     i, n;
  PCOL    colp;
//PCOLUMN cp;
  PDBUSER dup= PlgGetUser(g);

  if (xtrace)
    printf("CntOpenTable: tdbp=%p mode=%d\n", tdbp, mode);

  if (!tdbp) {
    strcpy(g->Message, "Null tdbp");
    printf("CntOpenTable: %s\n", g->Message);
    return true;
    } // endif tdbp

//tdbp->SetMode(mode);      done in ha_connect::GetTDB

  if (!c1) {
    if (mode == MODE_INSERT)
      // Allocate all column blocks for that table
      tdbp->ColDB(g, NULL, 0);

  } else for (p= c1; *p; p+= n) {
    // Allocate only used column blocks
    if (xtrace)
      printf("Allocating column %s\n", p);

//    if (*p == '*') {
//      // This is a special column
//      cp= new(g) COLUMN(p + 1);
//      cp->SetTo_Table(tdbp->GetTable());
//      colp= ((PTDBASE)tdbp)->InsertSpcBlk(g, cp);
//    } else
      colp= tdbp->ColDB(g, p, 0);

    if (!colp) {
      sprintf(g->Message, "Column %s not found in %s", p, tdbp->GetName());
      return true;
      } // endif colp

    n= strlen(p) + 1;
    } // endfor p

  for (i= 0, colp= tdbp->GetColumns(); colp; i++, colp= colp->GetNext()) {
    if (colp->InitValue(g))
      return true;

    if (mode == MODE_INSERT)
      // Allow type conversion
      if (colp->SetBuffer(g, colp->GetValue(), true, false))
        return true;

    colp->AddColUse(U_P);           // For PLG tables
    } // endfor colp

  /*********************************************************************/
  /*  In Update mode, the updated column blocks must be distinct from  */
  /*  the read column blocks. So make a copy of the TDB and allocate   */
  /*  its column blocks in mode write (required by XML tables).        */
  /*********************************************************************/
  if (mode == MODE_UPDATE) {
    PTDBASE utp;

    if (!(utp= (PTDBASE)tdbp->Duplicate(g))) {
      sprintf(g->Message, MSG(INV_UPDT_TABLE), tdbp->GetName());
      return true;
      } // endif tp

    if (!c2)
      // Allocate all column blocks for that table
      utp->ColDB(g, NULL, 0);
    else for (p= c2; *p; p+= n) {
      // Allocate only used column blocks
      colp= utp->ColDB(g, p, 0);
      n= strlen(p) + 1;
      } // endfor p

    for (i= 0, colp= utp->GetColumns(); colp; i++, colp= colp->GetNext()) {
      if (colp->InitValue(g))
        return true;

      if (colp->SetBuffer(g, colp->GetValue(), true, false))
        return true;

      } // endfor colp

    // Attach the updated columns list to the main table
    ((PTDBASE)tdbp)->SetSetCols(utp->GetColumns());
  } else if (tdbp && mode == MODE_INSERT)
    ((PTDBASE)tdbp)->SetSetCols(tdbp->GetColumns());

  // Now do open the physical table
  if (xtrace)
    printf("Opening table %s in mode %d tdbp=%p\n",
           tdbp->GetName(), mode, tdbp);

//tdbp->SetMode(mode);

  if (del && ((PTDBASE)tdbp)->GetFtype() != RECFM_NAF) {  
    // To avoid erasing the table when doing a partial delete
    // make a fake Next
    PDOSDEF ddp= new(g) DOSDEF;
    PTDB tp= new(g) TDBDOS(ddp, NULL);
    tdbp->SetNext(tp);
    dup->Check &= ~CHK_DELETE;
    } // endif del


  if (xtrace)
    printf("About to open the table: tdbp=%p\n", tdbp);

  if (mode != MODE_ANY) {
    if (tdbp->OpenDB(g)) {
      printf("%s\n", g->Message);
      return true;
    } else
      tdbp->SetNext(NULL);

  } // endif mode

  return false;
  } // end of CntOpenTable

/***********************************************************************/
/*  Rewind a table by reopening it.                                    */
/***********************************************************************/
bool CntRewindTable(PGLOBAL g, PTDB tdbp)
{
  if (!tdbp)
    return true;

  tdbp->OpenDB(g);
  return false;
} // end of CntRewindTable

/***********************************************************************/
/*  Evaluate all columns after a record is read.                       */
/***********************************************************************/
RCODE  EvalColumns(PGLOBAL g, PTDB tdbp)
  {
  RCODE rc= RC_OK;
  PCOL  colp;

  // Save stack and allocation environment and prepare error return
  if (g->jump_level == MAX_JUMP) {
    if (xtrace) {
      strcpy(g->Message, MSG(TOO_MANY_JUMPS));
      printf("EvalColumns: %s\n", g->Message);
      } // endif

    return RC_FX;
    } // endif jump_level

  if (setjmp(g->jumper[++g->jump_level]) != 0) {
    if (xtrace)
      printf("Error reading columns: %s\n", g->Message);

    rc= RC_FX;
    goto err;
    } // endif rc

  for (colp= tdbp->GetColumns(); rc == RC_OK && colp;
       colp= colp->GetNext()) {
      colp->Reset();

      // Virtual columns are computed by MariaDB
      if (!colp->GetColUse(U_VIRTUAL))
        if (colp->Eval(g))
          rc= RC_FX;

      } // endfor colp

 err:
  g->jump_level--;
  return rc;
  } // end of EvalColumns

/***********************************************************************/
/*  ReadNext: Read next record sequentially.                           */
/***********************************************************************/
RCODE  CntReadNext(PGLOBAL g, PTDB tdbp)
  {
  RCODE rc;

  if (!tdbp)
    return RC_FX;
  else if (((PTDBASE)tdbp)->GetKindex()) {
    // Reading sequencially an indexed table. This happens after the
    // handler function records_in_range was called and MySQL decides
    // to quit using the index (!!!) Drop the index.
    for (PCOL colp= tdbp->GetColumns(); colp; colp= colp->GetNext())
      colp->SetKcol(NULL);

    ((PTDBASE)tdbp)->SetKindex(NULL);
    } // endif index

  while ((rc= (RCODE)tdbp->ReadDB(g)) == RC_NF) ;
  
  return (rc != RC_OK) ? rc : EvalColumns(g, tdbp);
  } // end of CntReadNext

/***********************************************************************/
/*  WriteRow: Insert a new row into a table.                           */
/***********************************************************************/
RCODE  CntWriteRow(PGLOBAL g, PTDB tdbp)
  {
  RCODE    rc;
  PCOL    colp;
  PTDBASE tp= (PTDBASE)tdbp;

  if (!tdbp)
    return RC_FX;

  // Save stack and allocation environment and prepare error return
  if (g->jump_level == MAX_JUMP) {
    strcpy(g->Message, MSG(TOO_MANY_JUMPS));
    return RC_FX;
    } // endif jump_level

  if (setjmp(g->jumper[++g->jump_level]) != 0) {
    printf("%s\n", g->Message);
    rc= RC_FX;
    goto err;
    } // endif rc

  // Store column values in table write buffer(s)
  for (colp= tp->GetSetCols(); colp; colp= colp->GetNext())
    if (!colp->GetColUse(U_VIRTUAL))
      colp->WriteColumn(g);

//  if (tdbp->GetMode() == MODE_INSERT)
//    tbxp->SetModified(true);

  // Return result code from write operation
  rc= (RCODE)tdbp->WriteDB(g);

 err:
  g->jump_level--;
  return rc;
  } // end of CntWriteRow

/***********************************************************************/
/*  UpdateRow: Update a row into a table.                              */
/***********************************************************************/
RCODE  CntUpdateRow(PGLOBAL g, PTDB tdbp)
  {
  if (!tdbp || tdbp->GetMode() != MODE_UPDATE)
    return RC_FX;

  // Return result code from write operation
  return CntWriteRow(g, tdbp);
  } // end of CntUpdateRow

/***********************************************************************/
/*  DeleteRow: Delete a row from a table.                              */
/***********************************************************************/
RCODE  CntDeleteRow(PGLOBAL g, PTDB tdbp, bool all)
  {
  RCODE rc;

  if (!tdbp || tdbp->GetMode() != MODE_DELETE)
    return RC_FX;
  else if (tdbp->IsReadOnly())
    return RC_NF;

  if (((PTDBASE)tdbp)->GetDef()->Indexable() && all)
    ((PTDBDOS)tdbp)->Cardinal= 0;
 
  // Return result code from delete operation
  // Note: if all, this call will be done when closing the table
  rc= (RCODE)tdbp->DeleteDB(g, (all) ? RC_FX : RC_OK);
  return rc;
  } // end of CntDeleteRow

/***********************************************************************/
/*  CLOSETAB: Close a table.                                           */
/***********************************************************************/
int CntCloseTable(PGLOBAL g, PTDB tdbp)
  {
  int     rc= RC_OK;
  TDBDOX *tbxp= NULL;

  if (!tdbp || tdbp->GetUse() != USE_OPEN)
    return rc;                           // Nothing to do

  if (xtrace)
    printf("CntCloseTable: tdbp=%p mode=%d\n", tdbp, tdbp->GetMode());

  if (tdbp->GetMode() == MODE_DELETE && tdbp->GetUse() == USE_OPEN)
    rc= tdbp->DeleteDB(g, RC_EF);        // Specific A.M. delete routine

  //  Prepare error return
  if (g->jump_level == MAX_JUMP) {
    strcpy(g->Message, MSG(TOO_MANY_JUMPS));
    rc= RC_FX;
    goto err;
    } // endif

  if ((rc = setjmp(g->jumper[++g->jump_level])) != 0) {
    g->jump_level--;
    goto err;
    } // endif

  //  This will close the table file(s) and also finalize write
  //  operations such as Insert, Update, or Delete.
  tdbp->CloseDB(g);

  g->jump_level--;

  if (xtrace > 1)
    printf("Table %s closed\n", tdbp->GetName());

//if (!((PTDBDOX)tdbp)->GetModified())
//  return 0;

  if (tdbp->GetMode() == MODE_READ || tdbp->GetMode() == MODE_ANY) 
    return 0;

  if (xtrace > 1)
    printf("About to reset opt\n");

  // Make all the eventual indexes
  tbxp= (TDBDOX*)tdbp;
  tbxp->SetKindex(NULL);
  tbxp->To_Key_Col= NULL;
  rc= tbxp->ResetTableOpt(g, ((PTDBASE)tdbp)->GetDef()->Indexable());

 err:
  if (xtrace > 1)
    printf("Done rc=%d\n", rc);

  return (rc == RC_OK || rc == RC_INFO) ? 0 : rc;
  } // end of CntCloseTable

/***********************************************************************/
/*  Load and initialize the use of an index.                           */
/*  This is the condition(s) for doing indexing.                       */
/*  Note: FIX table are not reset here to Nrec= 1.                     */
/***********************************************************************/
int CntIndexInit(PGLOBAL g, PTDB ptdb, int id)
  {
  int     k;
  PCOL    colp;
  PVAL    valp;
  PKXBASE xp;
  PXLOAD  pxp;
  PIXDEF  xdp;
  XKPDEF *kdp;
  PTDBDOX tdbp;
  PCOLDEF cdp;
  DOXDEF *dfp;

  if (!ptdb)
    return -1;
  else if (!((PTDBASE)ptdb)->GetDef()->Indexable()) {
    sprintf(g->Message, "CntIndexInit: Table %s is not indexable", ptdb->GetName());
    return 0;
  } else
    tdbp= (PTDBDOX)ptdb;

  dfp= (DOXDEF*)tdbp->To_Def;

//if (!(k= colp->GetKey()))
//  if (colp->GetOpt() >= 2) {
//    strcpy(g->Message, "Not a valid indexed column");
//    return -1;
//  } else
      // This is a pseudo indexed sorted block optimized column
//    return 0;

  if (tdbp->To_Kindex)
    if (((XXBASE*)tdbp->To_Kindex)->GetID() == id) {
      tdbp->To_Kindex->Reset();                // Same index
      return (tdbp->To_Kindex->IsMul()) ? 2 : 1;
    } else {
      tdbp->To_Kindex->Close();
      tdbp->To_Kindex= NULL;
    } // endif colp

  for (xdp= dfp->To_Indx; xdp; xdp= xdp->GetNext())
    if (xdp->GetID() == id)
      break;

  if (!xdp) {
    sprintf(g->Message, "Wrong index ID %d", id);
    return 0;
    } // endif xdp

  // Allocate the key columns definition block
  tdbp->Knum= xdp->GetNparts();
  tdbp->To_Key_Col= (PCOL*)PlugSubAlloc(g, NULL, tdbp->Knum * sizeof(PCOL));

  // Get the key column description list
  for (k= 0, kdp= (XKPDEF*)xdp->GetToKeyParts(); kdp; kdp= (XKPDEF*)kdp->Next)
    if (!(colp= tdbp->ColDB(g, kdp->Name, 0)) || colp->InitValue(g)) {
      sprintf(g->Message, "Wrong column %s", kdp->Name);
      return 0;
    } else
      tdbp->To_Key_Col[k++]= colp;

#if defined(_DEBUG)
  if (k != tdbp->Knum) {
    sprintf(g->Message, "Key part number mismatch for %s",
                        xdp->GetName());
    return 0;
    } // endif k
#endif   // _DEBUG

  // Allocate the pseudo constants that will contain the key values
  tdbp->To_Link= (PXOB*)PlugSubAlloc(g, NULL, tdbp->Knum * sizeof(PXOB));

  for (k= 0, kdp= (XKPDEF*)xdp->GetToKeyParts(); 
       kdp; k++, kdp= (XKPDEF*)kdp->Next) {
    cdp= tdbp->Key(k)->GetCdp();
    valp= AllocateValue(g, cdp->GetType(), cdp->GetLength()); 
    tdbp->To_Link[k]= new(g) CONSTANT(valp);
    } // endfor k

  // Make the index on xdp
  if (!xdp->IsAuto()) {     
    if (dfp->Huge)
      pxp= new(g) XHUGE;
    else
      pxp= new(g) XFILE;

    if (tdbp->Knum == 1)            // Single index
      xp= new(g) XINDXS(tdbp, xdp, pxp, tdbp->To_Key_Col, tdbp->To_Link);
    else                       // Multi-Column index
      xp= new(g) XINDEX(tdbp, xdp, pxp, tdbp->To_Key_Col, tdbp->To_Link);

  } else                      // Column contains same values as ROWID
    xp= new(g) XXROW(tdbp);

  if (xp->Init(g))
    return 0;

  tdbp->To_Kindex= xp;
  return (xp->IsMul()) ? 2 : 1;
  } // end of CntIndexInit

/***********************************************************************/
/*  IndexRead: fetch a record having the index value.                  */
/***********************************************************************/
RCODE CntIndexRead(PGLOBAL g, PTDB ptdb, OPVAL op,
                   const void *key, int len)
  {
  char   *kp= (char*)key;
  int     n;
  short   lg;
  bool    rcb;
  RCODE   rc;
  PVAL    valp;
  PCOL    colp;
  XXBASE *xbp;
  PTDBDOX tdbp;

  if (!ptdb)
    return RC_FX;
  if (!((PTDBASE)ptdb)->GetDef()->Indexable()) {
    sprintf(g->Message, "CntIndexRead: Table %s is not indexable", ptdb->GetName());
    return RC_FX;
  } else
    tdbp= (PTDBDOX)ptdb;

  // Set reference values and index operator
  if (!tdbp->To_Link || !tdbp->To_Kindex) {
    sprintf(g->Message, "Index not initialized for table %s", tdbp->Name);
    return RC_FX;
  } else
    xbp= (XXBASE*)tdbp->To_Kindex;

  if (key) {
    for (n= 0; n < tdbp->Knum; n++) {
      colp= (PCOL)tdbp->To_Key_Col[n];
    
      if (colp->GetColUse(U_NULLS))
        kp++;                   // Skip null byte
    
      valp= tdbp->To_Link[n]->GetValue();

      if (!valp->IsTypeNum()) {
        if (colp->GetColUse(U_VAR)) {
          lg= *(short*)kp;
          kp+= sizeof(short);
          rcb= valp->SetValue_char(kp, (int)lg);
        } else
          rcb= valp->SetValue_char(kp, valp->GetClen());

        if (rcb) {
          if (tdbp->RowNumber(g))
            sprintf(g->Message, "Out of range value for column %s at row %d",
                    colp->GetName(), tdbp->RowNumber(g));
          else
            sprintf(g->Message, "Out of range value for column %s",
                    colp->GetName());

          PushWarning(g, tdbp);
          } // endif b

      } else
        valp->SetBinValue((void*)kp);

      kp+= valp->GetClen();
    
      if (len == kp - (char*)key) {
        n++;
        break;
      } else if (len < kp - (char*)key) {
        strcpy(g->Message, "Key buffer is too small");
        return RC_FX;
      } // endif len

      } // endfor n

    xbp->SetNval(n);
    } // endif key

  xbp->SetOp(op);
  xbp->SetNth(0);

  if ((rc= (RCODE)tdbp->ReadDB(g)) == RC_OK)
    rc= EvalColumns(g, tdbp);

  return rc;
  } // end of CntIndexRead

/***********************************************************************/
/*  Return the number of rows matching given values.                   */
/***********************************************************************/
int CntIndexRange(PGLOBAL g, PTDB ptdb, const uchar* *key, uint *len,
                   bool *incl, key_part_map *kmap)
  {
  const uchar *p, *kp;
  int     i, n, k[2];
  short   lg;
  bool    b, rcb;
  PVAL    valp;
  PCOL    colp;
  PTDBDOX tdbp;
  XXBASE *xbp;

  if (!ptdb)
    return -1;
  else if (!((PTDBASE)ptdb)->GetDef()->Indexable()) {
    sprintf(g->Message, "CntIndexRange: Table %s is not indexable", ptdb->GetName());
    DBUG_PRINT("Range", ("%s", g->Message));
    return -1;
  } else
    tdbp= (PTDBDOX)ptdb;

  if (!tdbp->To_Link || !tdbp->To_Kindex) {
    sprintf(g->Message, "Index not initialized for table %s", tdbp->Name);
    DBUG_PRINT("Range", ("%s", g->Message));
    return -1;
  } else
    xbp= (XXBASE*)tdbp->To_Kindex;

  for (b= false, i= 0; i < 2; i++) {
    p= kp= key[i];
                                                                         
    if (kp) {
      for (n= 0; n < tdbp->Knum; n++) {
        if (kmap[i] & (key_part_map)(1 << n)) {
          if (b == true)
            // Cannot do indexing with missing intermediate key
            return -1;      

          colp= (PCOL)tdbp->To_Key_Col[n];
    
          if (colp->GetColUse(U_NULLS))
            p++;                   // Skip null byte  ???
    
          valp= tdbp->To_Link[n]->GetValue();

          if (!valp->IsTypeNum()) {
            if (colp->GetColUse(U_VAR)) {
              lg= *(short*)p;
              p+= sizeof(short);
              rcb= valp->SetValue_char((char*)p, (int)lg);
            } else
              rcb= valp->SetValue_char((char*)p, valp->GetClen());

          if (rcb) {
            if (tdbp->RowNumber(g))
              sprintf(g->Message, 
                      "Out of range value for column %s at row %d",
                      colp->GetName(), tdbp->RowNumber(g));
            else
              sprintf(g->Message, "Out of range value for column %s",
                      colp->GetName());

            PushWarning(g, tdbp);
            } // endif b

          } else
            valp->SetBinValue((void*)p);

          if (xtrace) {
            char bf[32];
            printf("i=%d n=%d key=%s\n", i, n, valp->GetCharString(bf));
            } // endif xtrace

          p+= valp->GetClen();
    
          if (len[i] == (unsigned)(p - kp)) {
            n++;
            break;
          } else if (len[i] < (unsigned)(p - kp)) {
            strcpy(g->Message, "Key buffer is too small");
            return -1;
          } // endif len

        } else
          b= true;

        } // endfor n

      xbp->SetNval(n);

      if (xtrace)
        printf("xbp=%p Nval=%d i=%d incl=%d\n", xbp, n, i, incl[i]);

      k[i]= xbp->Range(g, i + 1, incl[i]);
    } else
      k[i]= (i) ? xbp->GetNum_K() : 0;

    } // endfor i

  if (xtrace)
    printf("k1=%d k0=%d\n", k[1], k[0]);

  return k[1] - k[0];
  } // end of CntIndexRange
