#ifndef CONTRIBUTORS_INCLUDED
#define CONTRIBUTORS_INCLUDED

/* Copyright (c) 2006 MySQL AB, 2009 Sun Microsystems, Inc.
   Use is subject to license terms.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA */

/* Structure of the name list */

struct show_table_contributors_st {
  const char *name;
  const char *location;
  const char *comment;
};

/*
  Output from "SHOW CONTRIBUTORS"

  Get permission before editing.

  Names should be encoded using UTF-8.
*/

struct show_table_contributors_st show_table_contributors[]= {
  /* MariaDB foundation members, in contribution size order */
  {"Booking.com", "http://www.booking.com", "Founding member of the MariaDB foundation"},
  {"SkySQL Ab", "http://www.skysql.com", "Founding member of the MariaDB foundation"},
  {"Parallels", "http://www.parallels.com/products/plesk", "Founding member of the MariaDB foundation"},

  /* Smaller sponsors, newer per year */
  {"Jelastic.com", "Russia", "Sponsor of the MariaDB foundation"},
  {"Planetta.net", "Finland", "Sponsor of the MariaDB foundation"},
  {"Open query", "Australia", "Sponsor of the MariaDB foundation"},

  /* Individual contributors, names in historical order, newer first */
  {"Ronald Bradford", "Brisbane, Australia", "EFF contribution for UC2006 Auction"},
  {"Sheeri Kritzer", "Boston, Mass. USA", "EFF contribution for UC2006 Auction"},
  {"Mark Shuttleworth", "London, UK.", "EFF contribution for UC2006 Auction"},
  {NULL, NULL, NULL}
};

#endif /* CONTRIBUTORS_INCLUDED */
