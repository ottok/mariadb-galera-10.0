
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ABORT_SYM = 258,
     ACCESSIBLE_SYM = 259,
     ACTION = 260,
     ADD = 261,
     ADMIN_SYM = 262,
     ADDDATE_SYM = 263,
     AFTER_SYM = 264,
     AGAINST = 265,
     AGGREGATE_SYM = 266,
     ALGORITHM_SYM = 267,
     ALL = 268,
     ALTER = 269,
     ALWAYS_SYM = 270,
     ANALYZE_SYM = 271,
     AND_AND_SYM = 272,
     AND_SYM = 273,
     ANY_SYM = 274,
     AS = 275,
     ASC = 276,
     ASCII_SYM = 277,
     ASENSITIVE_SYM = 278,
     AT_SYM = 279,
     AUTHORS_SYM = 280,
     AUTOEXTEND_SIZE_SYM = 281,
     AUTO_INC = 282,
     AUTO_SYM = 283,
     AVG_ROW_LENGTH = 284,
     AVG_SYM = 285,
     BACKUP_SYM = 286,
     BEFORE_SYM = 287,
     BEGIN_SYM = 288,
     BETWEEN_SYM = 289,
     BIGINT = 290,
     BINARY = 291,
     BINLOG_SYM = 292,
     BIN_NUM = 293,
     BIT_AND = 294,
     BIT_OR = 295,
     BIT_SYM = 296,
     BIT_XOR = 297,
     BLOB_SYM = 298,
     BLOCK_SYM = 299,
     BOOLEAN_SYM = 300,
     BOOL_SYM = 301,
     BOTH = 302,
     BTREE_SYM = 303,
     BY = 304,
     BYTE_SYM = 305,
     CACHE_SYM = 306,
     CALL_SYM = 307,
     CASCADE = 308,
     CASCADED = 309,
     CASE_SYM = 310,
     CAST_SYM = 311,
     CATALOG_NAME_SYM = 312,
     CHAIN_SYM = 313,
     CHANGE = 314,
     CHANGED = 315,
     CHARSET = 316,
     CHAR_SYM = 317,
     CHECKPOINT_SYM = 318,
     CHECKSUM_SYM = 319,
     CHECK_SYM = 320,
     CIPHER_SYM = 321,
     CLASS_ORIGIN_SYM = 322,
     CLIENT_SYM = 323,
     CLIENT_STATS_SYM = 324,
     CLOSE_SYM = 325,
     COALESCE = 326,
     CODE_SYM = 327,
     COLLATE_SYM = 328,
     COLLATION_SYM = 329,
     COLUMNS = 330,
     COLUMN_ADD_SYM = 331,
     COLUMN_CHECK_SYM = 332,
     COLUMN_CREATE_SYM = 333,
     COLUMN_DELETE_SYM = 334,
     COLUMN_GET_SYM = 335,
     COLUMN_SYM = 336,
     COLUMN_NAME_SYM = 337,
     COMMENT_SYM = 338,
     COMMITTED_SYM = 339,
     COMMIT_SYM = 340,
     COMPACT_SYM = 341,
     COMPLETION_SYM = 342,
     COMPRESSED_SYM = 343,
     CONCURRENT = 344,
     CONDITION_SYM = 345,
     CONNECTION_SYM = 346,
     CONSISTENT_SYM = 347,
     CONSTRAINT = 348,
     CONSTRAINT_CATALOG_SYM = 349,
     CONSTRAINT_NAME_SYM = 350,
     CONSTRAINT_SCHEMA_SYM = 351,
     CONTAINS_SYM = 352,
     CONTEXT_SYM = 353,
     CONTINUE_SYM = 354,
     CONTRIBUTORS_SYM = 355,
     CONVERT_SYM = 356,
     COUNT_SYM = 357,
     CPU_SYM = 358,
     CREATE = 359,
     CROSS = 360,
     CUBE_SYM = 361,
     CURDATE = 362,
     CURRENT_SYM = 363,
     CURRENT_USER = 364,
     CURRENT_ROLE = 365,
     CURRENT_POS_SYM = 366,
     CURSOR_SYM = 367,
     CURSOR_NAME_SYM = 368,
     CURTIME = 369,
     DATABASE = 370,
     DATABASES = 371,
     DATAFILE_SYM = 372,
     DATA_SYM = 373,
     DATETIME = 374,
     DATE_ADD_INTERVAL = 375,
     DATE_SUB_INTERVAL = 376,
     DATE_SYM = 377,
     DAY_HOUR_SYM = 378,
     DAY_MICROSECOND_SYM = 379,
     DAY_MINUTE_SYM = 380,
     DAY_SECOND_SYM = 381,
     DAY_SYM = 382,
     DEALLOCATE_SYM = 383,
     DECIMAL_NUM = 384,
     DECIMAL_SYM = 385,
     DECLARE_SYM = 386,
     DEFAULT = 387,
     DEFINER_SYM = 388,
     DELAYED_SYM = 389,
     DELAY_KEY_WRITE_SYM = 390,
     DELETE_SYM = 391,
     DESC = 392,
     DESCRIBE = 393,
     DES_KEY_FILE = 394,
     DETERMINISTIC_SYM = 395,
     DIAGNOSTICS_SYM = 396,
     DIRECTORY_SYM = 397,
     DISABLE_SYM = 398,
     DISCARD = 399,
     DISK_SYM = 400,
     DISTINCT = 401,
     DIV_SYM = 402,
     DOUBLE_SYM = 403,
     DO_SYM = 404,
     DROP = 405,
     DUAL_SYM = 406,
     DUMPFILE = 407,
     DUPLICATE_SYM = 408,
     DYNAMIC_SYM = 409,
     EACH_SYM = 410,
     ELSE = 411,
     ELSEIF_SYM = 412,
     ENABLE_SYM = 413,
     ENCLOSED = 414,
     END = 415,
     ENDS_SYM = 416,
     END_OF_INPUT = 417,
     ENGINES_SYM = 418,
     ENGINE_SYM = 419,
     ENUM = 420,
     EQ = 421,
     EQUAL_SYM = 422,
     ERROR_SYM = 423,
     ERRORS = 424,
     ESCAPED = 425,
     ESCAPE_SYM = 426,
     EVENTS_SYM = 427,
     EVENT_SYM = 428,
     EVERY_SYM = 429,
     EXCHANGE_SYM = 430,
     EXAMINED_SYM = 431,
     EXECUTE_SYM = 432,
     EXISTS = 433,
     EXIT_SYM = 434,
     EXPANSION_SYM = 435,
     EXTENDED_SYM = 436,
     EXTENT_SIZE_SYM = 437,
     EXTRACT_SYM = 438,
     FALSE_SYM = 439,
     FAST_SYM = 440,
     FAULTS_SYM = 441,
     FETCH_SYM = 442,
     FILE_SYM = 443,
     FIRST_SYM = 444,
     FIXED_SYM = 445,
     FLOAT_NUM = 446,
     FLOAT_SYM = 447,
     FLUSH_SYM = 448,
     FORCE_SYM = 449,
     FOREIGN = 450,
     FOR_SYM = 451,
     FOUND_SYM = 452,
     FROM = 453,
     FULL = 454,
     FULLTEXT_SYM = 455,
     FUNCTION_SYM = 456,
     GE = 457,
     GENERAL = 458,
     GENERATED_SYM = 459,
     GEOMETRYCOLLECTION = 460,
     GEOMETRY_SYM = 461,
     GET_FORMAT = 462,
     GET_SYM = 463,
     GLOBAL_SYM = 464,
     GRANT = 465,
     GRANTS = 466,
     GROUP_SYM = 467,
     GROUP_CONCAT_SYM = 468,
     GT_SYM = 469,
     HANDLER_SYM = 470,
     HARD_SYM = 471,
     HASH_SYM = 472,
     HAVING = 473,
     HELP_SYM = 474,
     HEX_NUM = 475,
     HEX_STRING = 476,
     HIGH_PRIORITY = 477,
     HOST_SYM = 478,
     HOSTS_SYM = 479,
     HOUR_MICROSECOND_SYM = 480,
     HOUR_MINUTE_SYM = 481,
     HOUR_SECOND_SYM = 482,
     HOUR_SYM = 483,
     ID_SYM = 484,
     IDENT = 485,
     IDENTIFIED_SYM = 486,
     IDENT_QUOTED = 487,
     IF = 488,
     IGNORE_SYM = 489,
     IGNORE_SERVER_IDS_SYM = 490,
     IMPORT = 491,
     INDEXES = 492,
     INDEX_SYM = 493,
     INDEX_STATS_SYM = 494,
     INFILE = 495,
     INITIAL_SIZE_SYM = 496,
     INNER_SYM = 497,
     INOUT_SYM = 498,
     INSENSITIVE_SYM = 499,
     INSERT = 500,
     INSERT_METHOD = 501,
     INSTALL_SYM = 502,
     INTERVAL_SYM = 503,
     INTO = 504,
     INT_SYM = 505,
     INVOKER_SYM = 506,
     IN_SYM = 507,
     IO_SYM = 508,
     IPC_SYM = 509,
     IS = 510,
     ISOLATION = 511,
     ISSUER_SYM = 512,
     ITERATE_SYM = 513,
     JOIN_SYM = 514,
     KEYS = 515,
     KEY_BLOCK_SIZE = 516,
     KEY_SYM = 517,
     KILL_SYM = 518,
     LANGUAGE_SYM = 519,
     LAST_SYM = 520,
     LAST_VALUE = 521,
     LE = 522,
     LEADING = 523,
     LEAVES = 524,
     LEAVE_SYM = 525,
     LEFT = 526,
     LESS_SYM = 527,
     LEVEL_SYM = 528,
     LEX_HOSTNAME = 529,
     LIKE = 530,
     LIMIT = 531,
     LINEAR_SYM = 532,
     LINES = 533,
     LINESTRING = 534,
     LIST_SYM = 535,
     LOAD = 536,
     LOCAL_SYM = 537,
     LOCATOR_SYM = 538,
     LOCKS_SYM = 539,
     LOCK_SYM = 540,
     LOGFILE_SYM = 541,
     LOGS_SYM = 542,
     LONGBLOB = 543,
     LONGTEXT = 544,
     LONG_NUM = 545,
     LONG_SYM = 546,
     LOOP_SYM = 547,
     LOW_PRIORITY = 548,
     LT = 549,
     MASTER_CONNECT_RETRY_SYM = 550,
     MASTER_GTID_POS_SYM = 551,
     MASTER_HOST_SYM = 552,
     MASTER_LOG_FILE_SYM = 553,
     MASTER_LOG_POS_SYM = 554,
     MASTER_PASSWORD_SYM = 555,
     MASTER_PORT_SYM = 556,
     MASTER_SERVER_ID_SYM = 557,
     MASTER_SSL_CAPATH_SYM = 558,
     MASTER_SSL_CA_SYM = 559,
     MASTER_SSL_CERT_SYM = 560,
     MASTER_SSL_CIPHER_SYM = 561,
     MASTER_SSL_CRL_SYM = 562,
     MASTER_SSL_CRLPATH_SYM = 563,
     MASTER_SSL_KEY_SYM = 564,
     MASTER_SSL_SYM = 565,
     MASTER_SSL_VERIFY_SERVER_CERT_SYM = 566,
     MASTER_SYM = 567,
     MASTER_USER_SYM = 568,
     MASTER_USE_GTID_SYM = 569,
     MASTER_HEARTBEAT_PERIOD_SYM = 570,
     MATCH = 571,
     MAX_CONNECTIONS_PER_HOUR = 572,
     MAX_QUERIES_PER_HOUR = 573,
     MAX_ROWS = 574,
     MAX_SIZE_SYM = 575,
     MAX_SYM = 576,
     MAX_UPDATES_PER_HOUR = 577,
     MAX_USER_CONNECTIONS_SYM = 578,
     MAX_VALUE_SYM = 579,
     MEDIUMBLOB = 580,
     MEDIUMINT = 581,
     MEDIUMTEXT = 582,
     MEDIUM_SYM = 583,
     MEMORY_SYM = 584,
     MERGE_SYM = 585,
     MESSAGE_TEXT_SYM = 586,
     MICROSECOND_SYM = 587,
     MIGRATE_SYM = 588,
     MINUTE_MICROSECOND_SYM = 589,
     MINUTE_SECOND_SYM = 590,
     MINUTE_SYM = 591,
     MIN_ROWS = 592,
     MIN_SYM = 593,
     MODE_SYM = 594,
     MODIFIES_SYM = 595,
     MODIFY_SYM = 596,
     MOD_SYM = 597,
     MONTH_SYM = 598,
     MULTILINESTRING = 599,
     MULTIPOINT = 600,
     MULTIPOLYGON = 601,
     MUTEX_SYM = 602,
     MYSQL_ERRNO_SYM = 603,
     NAMES_SYM = 604,
     NAME_SYM = 605,
     NATIONAL_SYM = 606,
     NATURAL = 607,
     NCHAR_STRING = 608,
     NCHAR_SYM = 609,
     NDBCLUSTER_SYM = 610,
     NE = 611,
     NEG = 612,
     NEW_SYM = 613,
     NEXT_SYM = 614,
     NODEGROUP_SYM = 615,
     NONE_SYM = 616,
     NOT2_SYM = 617,
     NOT_SYM = 618,
     NOW_SYM = 619,
     NO_SYM = 620,
     NO_WAIT_SYM = 621,
     NO_WRITE_TO_BINLOG = 622,
     NULL_SYM = 623,
     NUM = 624,
     NUMBER_SYM = 625,
     NUMERIC_SYM = 626,
     NVARCHAR_SYM = 627,
     OFFSET_SYM = 628,
     OLD_PASSWORD = 629,
     ON = 630,
     ONE_SYM = 631,
     ONLY_SYM = 632,
     ONLINE_SYM = 633,
     OPEN_SYM = 634,
     OPTIMIZE = 635,
     OPTIONS_SYM = 636,
     OPTION = 637,
     OPTIONALLY = 638,
     OR2_SYM = 639,
     ORDER_SYM = 640,
     OR_OR_SYM = 641,
     OR_SYM = 642,
     OUTER = 643,
     OUTFILE = 644,
     OUT_SYM = 645,
     OWNER_SYM = 646,
     PACK_KEYS_SYM = 647,
     PAGE_SYM = 648,
     PAGE_CHECKSUM_SYM = 649,
     PARAM_MARKER = 650,
     PARSER_SYM = 651,
     PARSE_VCOL_EXPR_SYM = 652,
     PARTIAL = 653,
     PARTITION_SYM = 654,
     PARTITIONS_SYM = 655,
     PARTITIONING_SYM = 656,
     PASSWORD = 657,
     PERSISTENT_SYM = 658,
     PHASE_SYM = 659,
     PLUGINS_SYM = 660,
     PLUGIN_SYM = 661,
     POINT_SYM = 662,
     POLYGON = 663,
     PORT_SYM = 664,
     POSITION_SYM = 665,
     PRECISION = 666,
     PREPARE_SYM = 667,
     PRESERVE_SYM = 668,
     PREV_SYM = 669,
     PRIMARY_SYM = 670,
     PRIVILEGES = 671,
     PROCEDURE_SYM = 672,
     PROCESS = 673,
     PROCESSLIST_SYM = 674,
     PROFILE_SYM = 675,
     PROFILES_SYM = 676,
     PROXY_SYM = 677,
     PURGE = 678,
     QUARTER_SYM = 679,
     QUERY_SYM = 680,
     QUICK = 681,
     RANGE_SYM = 682,
     READS_SYM = 683,
     READ_ONLY_SYM = 684,
     READ_SYM = 685,
     READ_WRITE_SYM = 686,
     REAL = 687,
     REBUILD_SYM = 688,
     RECOVER_SYM = 689,
     REDOFILE_SYM = 690,
     REDO_BUFFER_SIZE_SYM = 691,
     REDUNDANT_SYM = 692,
     REFERENCES = 693,
     REGEXP = 694,
     RELAY = 695,
     RELAYLOG_SYM = 696,
     RELAY_LOG_FILE_SYM = 697,
     RELAY_LOG_POS_SYM = 698,
     RELAY_THREAD = 699,
     RELEASE_SYM = 700,
     RELOAD = 701,
     REMOVE_SYM = 702,
     RENAME = 703,
     REORGANIZE_SYM = 704,
     REPAIR = 705,
     REPEATABLE_SYM = 706,
     REPEAT_SYM = 707,
     REPLACE = 708,
     REPLICATION = 709,
     REQUIRE_SYM = 710,
     RESET_SYM = 711,
     RESIGNAL_SYM = 712,
     RESOURCES = 713,
     RESTORE_SYM = 714,
     RESTRICT = 715,
     RESUME_SYM = 716,
     RETURNED_SQLSTATE_SYM = 717,
     RETURNING_SYM = 718,
     RETURNS_SYM = 719,
     RETURN_SYM = 720,
     REVERSE_SYM = 721,
     REVOKE = 722,
     RIGHT = 723,
     ROLE_SYM = 724,
     ROLLBACK_SYM = 725,
     ROLLUP_SYM = 726,
     ROUTINE_SYM = 727,
     ROWS_SYM = 728,
     ROW_FORMAT_SYM = 729,
     ROW_SYM = 730,
     ROW_COUNT_SYM = 731,
     RTREE_SYM = 732,
     SAVEPOINT_SYM = 733,
     SCHEDULE_SYM = 734,
     SCHEMA_NAME_SYM = 735,
     SECOND_MICROSECOND_SYM = 736,
     SECOND_SYM = 737,
     SECURITY_SYM = 738,
     SELECT_SYM = 739,
     SENSITIVE_SYM = 740,
     SEPARATOR_SYM = 741,
     SERIALIZABLE_SYM = 742,
     SERIAL_SYM = 743,
     SESSION_SYM = 744,
     SERVER_SYM = 745,
     SERVER_OPTIONS = 746,
     SET = 747,
     SET_VAR = 748,
     SHARE_SYM = 749,
     SHIFT_LEFT = 750,
     SHIFT_RIGHT = 751,
     SHOW = 752,
     SHUTDOWN = 753,
     SIGNAL_SYM = 754,
     SIGNED_SYM = 755,
     SIMPLE_SYM = 756,
     SLAVE = 757,
     SLAVES = 758,
     SLAVE_POS_SYM = 759,
     SLOW = 760,
     SMALLINT = 761,
     SNAPSHOT_SYM = 762,
     SOCKET_SYM = 763,
     SOFT_SYM = 764,
     SONAME_SYM = 765,
     SOUNDS_SYM = 766,
     SOURCE_SYM = 767,
     SPATIAL_SYM = 768,
     SPECIFIC_SYM = 769,
     SQLEXCEPTION_SYM = 770,
     SQLSTATE_SYM = 771,
     SQLWARNING_SYM = 772,
     SQL_BIG_RESULT = 773,
     SQL_BUFFER_RESULT = 774,
     SQL_CACHE_SYM = 775,
     SQL_CALC_FOUND_ROWS = 776,
     SQL_NO_CACHE_SYM = 777,
     SQL_SMALL_RESULT = 778,
     SQL_SYM = 779,
     SQL_THREAD = 780,
     SSL_SYM = 781,
     STARTING = 782,
     STARTS_SYM = 783,
     START_SYM = 784,
     STATS_AUTO_RECALC_SYM = 785,
     STATS_PERSISTENT_SYM = 786,
     STATS_SAMPLE_PAGES_SYM = 787,
     STATUS_SYM = 788,
     STDDEV_SAMP_SYM = 789,
     STD_SYM = 790,
     STOP_SYM = 791,
     STORAGE_SYM = 792,
     STRAIGHT_JOIN = 793,
     STRING_SYM = 794,
     SUBCLASS_ORIGIN_SYM = 795,
     SUBDATE_SYM = 796,
     SUBJECT_SYM = 797,
     SUBPARTITIONS_SYM = 798,
     SUBPARTITION_SYM = 799,
     SUBSTRING = 800,
     SUM_SYM = 801,
     SUPER_SYM = 802,
     SUSPEND_SYM = 803,
     SWAPS_SYM = 804,
     SWITCHES_SYM = 805,
     SYSDATE = 806,
     TABLES = 807,
     TABLESPACE = 808,
     TABLE_REF_PRIORITY = 809,
     TABLE_STATS_SYM = 810,
     TABLE_SYM = 811,
     TABLE_CHECKSUM_SYM = 812,
     TABLE_NAME_SYM = 813,
     TEMPORARY = 814,
     TEMPTABLE_SYM = 815,
     TERMINATED = 816,
     TEXT_STRING = 817,
     TEXT_SYM = 818,
     THAN_SYM = 819,
     THEN_SYM = 820,
     TIMESTAMP = 821,
     TIMESTAMP_ADD = 822,
     TIMESTAMP_DIFF = 823,
     TIME_SYM = 824,
     TINYBLOB = 825,
     TINYINT = 826,
     TINYTEXT = 827,
     TO_SYM = 828,
     TRAILING = 829,
     TRANSACTION_SYM = 830,
     TRANSACTIONAL_SYM = 831,
     TRIGGERS_SYM = 832,
     TRIGGER_SYM = 833,
     TRIM = 834,
     TRUE_SYM = 835,
     TRUNCATE_SYM = 836,
     TYPES_SYM = 837,
     TYPE_SYM = 838,
     UDF_RETURNS_SYM = 839,
     ULONGLONG_NUM = 840,
     UNCOMMITTED_SYM = 841,
     UNDEFINED_SYM = 842,
     UNDERSCORE_CHARSET = 843,
     UNDOFILE_SYM = 844,
     UNDO_BUFFER_SIZE_SYM = 845,
     UNDO_SYM = 846,
     UNICODE_SYM = 847,
     UNINSTALL_SYM = 848,
     UNION_SYM = 849,
     UNIQUE_SYM = 850,
     UNKNOWN_SYM = 851,
     UNLOCK_SYM = 852,
     UNSIGNED = 853,
     UNTIL_SYM = 854,
     UPDATE_SYM = 855,
     UPGRADE_SYM = 856,
     USAGE = 857,
     USER = 858,
     USER_STATS_SYM = 859,
     USE_FRM = 860,
     USE_SYM = 861,
     USING = 862,
     UTC_DATE_SYM = 863,
     UTC_TIMESTAMP_SYM = 864,
     UTC_TIME_SYM = 865,
     VALUES = 866,
     VALUE_SYM = 867,
     VARBINARY = 868,
     VARCHAR = 869,
     VARIABLES = 870,
     VARIANCE_SYM = 871,
     VARYING = 872,
     VAR_SAMP_SYM = 873,
     VIA_SYM = 874,
     VIEW_SYM = 875,
     VIRTUAL_SYM = 876,
     WAIT_SYM = 877,
     WARNINGS = 878,
     WEEK_SYM = 879,
     WEIGHT_STRING_SYM = 880,
     WHEN_SYM = 881,
     WHERE = 882,
     WHILE_SYM = 883,
     WITH = 884,
     WITH_CUBE_SYM = 885,
     WITH_ROLLUP_SYM = 886,
     WORK_SYM = 887,
     WRAPPER_SYM = 888,
     WRITE_SYM = 889,
     X509_SYM = 890,
     XA_SYM = 891,
     XML_SYM = 892,
     XOR = 893,
     YEAR_MONTH_SYM = 894,
     YEAR_SYM = 895,
     ZEROFILL = 896,
     IMPOSSIBLE_ACTION = 897
   };
#endif
/* Tokens.  */
#define ABORT_SYM 258
#define ACCESSIBLE_SYM 259
#define ACTION 260
#define ADD 261
#define ADMIN_SYM 262
#define ADDDATE_SYM 263
#define AFTER_SYM 264
#define AGAINST 265
#define AGGREGATE_SYM 266
#define ALGORITHM_SYM 267
#define ALL 268
#define ALTER 269
#define ALWAYS_SYM 270
#define ANALYZE_SYM 271
#define AND_AND_SYM 272
#define AND_SYM 273
#define ANY_SYM 274
#define AS 275
#define ASC 276
#define ASCII_SYM 277
#define ASENSITIVE_SYM 278
#define AT_SYM 279
#define AUTHORS_SYM 280
#define AUTOEXTEND_SIZE_SYM 281
#define AUTO_INC 282
#define AUTO_SYM 283
#define AVG_ROW_LENGTH 284
#define AVG_SYM 285
#define BACKUP_SYM 286
#define BEFORE_SYM 287
#define BEGIN_SYM 288
#define BETWEEN_SYM 289
#define BIGINT 290
#define BINARY 291
#define BINLOG_SYM 292
#define BIN_NUM 293
#define BIT_AND 294
#define BIT_OR 295
#define BIT_SYM 296
#define BIT_XOR 297
#define BLOB_SYM 298
#define BLOCK_SYM 299
#define BOOLEAN_SYM 300
#define BOOL_SYM 301
#define BOTH 302
#define BTREE_SYM 303
#define BY 304
#define BYTE_SYM 305
#define CACHE_SYM 306
#define CALL_SYM 307
#define CASCADE 308
#define CASCADED 309
#define CASE_SYM 310
#define CAST_SYM 311
#define CATALOG_NAME_SYM 312
#define CHAIN_SYM 313
#define CHANGE 314
#define CHANGED 315
#define CHARSET 316
#define CHAR_SYM 317
#define CHECKPOINT_SYM 318
#define CHECKSUM_SYM 319
#define CHECK_SYM 320
#define CIPHER_SYM 321
#define CLASS_ORIGIN_SYM 322
#define CLIENT_SYM 323
#define CLIENT_STATS_SYM 324
#define CLOSE_SYM 325
#define COALESCE 326
#define CODE_SYM 327
#define COLLATE_SYM 328
#define COLLATION_SYM 329
#define COLUMNS 330
#define COLUMN_ADD_SYM 331
#define COLUMN_CHECK_SYM 332
#define COLUMN_CREATE_SYM 333
#define COLUMN_DELETE_SYM 334
#define COLUMN_GET_SYM 335
#define COLUMN_SYM 336
#define COLUMN_NAME_SYM 337
#define COMMENT_SYM 338
#define COMMITTED_SYM 339
#define COMMIT_SYM 340
#define COMPACT_SYM 341
#define COMPLETION_SYM 342
#define COMPRESSED_SYM 343
#define CONCURRENT 344
#define CONDITION_SYM 345
#define CONNECTION_SYM 346
#define CONSISTENT_SYM 347
#define CONSTRAINT 348
#define CONSTRAINT_CATALOG_SYM 349
#define CONSTRAINT_NAME_SYM 350
#define CONSTRAINT_SCHEMA_SYM 351
#define CONTAINS_SYM 352
#define CONTEXT_SYM 353
#define CONTINUE_SYM 354
#define CONTRIBUTORS_SYM 355
#define CONVERT_SYM 356
#define COUNT_SYM 357
#define CPU_SYM 358
#define CREATE 359
#define CROSS 360
#define CUBE_SYM 361
#define CURDATE 362
#define CURRENT_SYM 363
#define CURRENT_USER 364
#define CURRENT_ROLE 365
#define CURRENT_POS_SYM 366
#define CURSOR_SYM 367
#define CURSOR_NAME_SYM 368
#define CURTIME 369
#define DATABASE 370
#define DATABASES 371
#define DATAFILE_SYM 372
#define DATA_SYM 373
#define DATETIME 374
#define DATE_ADD_INTERVAL 375
#define DATE_SUB_INTERVAL 376
#define DATE_SYM 377
#define DAY_HOUR_SYM 378
#define DAY_MICROSECOND_SYM 379
#define DAY_MINUTE_SYM 380
#define DAY_SECOND_SYM 381
#define DAY_SYM 382
#define DEALLOCATE_SYM 383
#define DECIMAL_NUM 384
#define DECIMAL_SYM 385
#define DECLARE_SYM 386
#define DEFAULT 387
#define DEFINER_SYM 388
#define DELAYED_SYM 389
#define DELAY_KEY_WRITE_SYM 390
#define DELETE_SYM 391
#define DESC 392
#define DESCRIBE 393
#define DES_KEY_FILE 394
#define DETERMINISTIC_SYM 395
#define DIAGNOSTICS_SYM 396
#define DIRECTORY_SYM 397
#define DISABLE_SYM 398
#define DISCARD 399
#define DISK_SYM 400
#define DISTINCT 401
#define DIV_SYM 402
#define DOUBLE_SYM 403
#define DO_SYM 404
#define DROP 405
#define DUAL_SYM 406
#define DUMPFILE 407
#define DUPLICATE_SYM 408
#define DYNAMIC_SYM 409
#define EACH_SYM 410
#define ELSE 411
#define ELSEIF_SYM 412
#define ENABLE_SYM 413
#define ENCLOSED 414
#define END 415
#define ENDS_SYM 416
#define END_OF_INPUT 417
#define ENGINES_SYM 418
#define ENGINE_SYM 419
#define ENUM 420
#define EQ 421
#define EQUAL_SYM 422
#define ERROR_SYM 423
#define ERRORS 424
#define ESCAPED 425
#define ESCAPE_SYM 426
#define EVENTS_SYM 427
#define EVENT_SYM 428
#define EVERY_SYM 429
#define EXCHANGE_SYM 430
#define EXAMINED_SYM 431
#define EXECUTE_SYM 432
#define EXISTS 433
#define EXIT_SYM 434
#define EXPANSION_SYM 435
#define EXTENDED_SYM 436
#define EXTENT_SIZE_SYM 437
#define EXTRACT_SYM 438
#define FALSE_SYM 439
#define FAST_SYM 440
#define FAULTS_SYM 441
#define FETCH_SYM 442
#define FILE_SYM 443
#define FIRST_SYM 444
#define FIXED_SYM 445
#define FLOAT_NUM 446
#define FLOAT_SYM 447
#define FLUSH_SYM 448
#define FORCE_SYM 449
#define FOREIGN 450
#define FOR_SYM 451
#define FOUND_SYM 452
#define FROM 453
#define FULL 454
#define FULLTEXT_SYM 455
#define FUNCTION_SYM 456
#define GE 457
#define GENERAL 458
#define GENERATED_SYM 459
#define GEOMETRYCOLLECTION 460
#define GEOMETRY_SYM 461
#define GET_FORMAT 462
#define GET_SYM 463
#define GLOBAL_SYM 464
#define GRANT 465
#define GRANTS 466
#define GROUP_SYM 467
#define GROUP_CONCAT_SYM 468
#define GT_SYM 469
#define HANDLER_SYM 470
#define HARD_SYM 471
#define HASH_SYM 472
#define HAVING 473
#define HELP_SYM 474
#define HEX_NUM 475
#define HEX_STRING 476
#define HIGH_PRIORITY 477
#define HOST_SYM 478
#define HOSTS_SYM 479
#define HOUR_MICROSECOND_SYM 480
#define HOUR_MINUTE_SYM 481
#define HOUR_SECOND_SYM 482
#define HOUR_SYM 483
#define ID_SYM 484
#define IDENT 485
#define IDENTIFIED_SYM 486
#define IDENT_QUOTED 487
#define IF 488
#define IGNORE_SYM 489
#define IGNORE_SERVER_IDS_SYM 490
#define IMPORT 491
#define INDEXES 492
#define INDEX_SYM 493
#define INDEX_STATS_SYM 494
#define INFILE 495
#define INITIAL_SIZE_SYM 496
#define INNER_SYM 497
#define INOUT_SYM 498
#define INSENSITIVE_SYM 499
#define INSERT 500
#define INSERT_METHOD 501
#define INSTALL_SYM 502
#define INTERVAL_SYM 503
#define INTO 504
#define INT_SYM 505
#define INVOKER_SYM 506
#define IN_SYM 507
#define IO_SYM 508
#define IPC_SYM 509
#define IS 510
#define ISOLATION 511
#define ISSUER_SYM 512
#define ITERATE_SYM 513
#define JOIN_SYM 514
#define KEYS 515
#define KEY_BLOCK_SIZE 516
#define KEY_SYM 517
#define KILL_SYM 518
#define LANGUAGE_SYM 519
#define LAST_SYM 520
#define LAST_VALUE 521
#define LE 522
#define LEADING 523
#define LEAVES 524
#define LEAVE_SYM 525
#define LEFT 526
#define LESS_SYM 527
#define LEVEL_SYM 528
#define LEX_HOSTNAME 529
#define LIKE 530
#define LIMIT 531
#define LINEAR_SYM 532
#define LINES 533
#define LINESTRING 534
#define LIST_SYM 535
#define LOAD 536
#define LOCAL_SYM 537
#define LOCATOR_SYM 538
#define LOCKS_SYM 539
#define LOCK_SYM 540
#define LOGFILE_SYM 541
#define LOGS_SYM 542
#define LONGBLOB 543
#define LONGTEXT 544
#define LONG_NUM 545
#define LONG_SYM 546
#define LOOP_SYM 547
#define LOW_PRIORITY 548
#define LT 549
#define MASTER_CONNECT_RETRY_SYM 550
#define MASTER_GTID_POS_SYM 551
#define MASTER_HOST_SYM 552
#define MASTER_LOG_FILE_SYM 553
#define MASTER_LOG_POS_SYM 554
#define MASTER_PASSWORD_SYM 555
#define MASTER_PORT_SYM 556
#define MASTER_SERVER_ID_SYM 557
#define MASTER_SSL_CAPATH_SYM 558
#define MASTER_SSL_CA_SYM 559
#define MASTER_SSL_CERT_SYM 560
#define MASTER_SSL_CIPHER_SYM 561
#define MASTER_SSL_CRL_SYM 562
#define MASTER_SSL_CRLPATH_SYM 563
#define MASTER_SSL_KEY_SYM 564
#define MASTER_SSL_SYM 565
#define MASTER_SSL_VERIFY_SERVER_CERT_SYM 566
#define MASTER_SYM 567
#define MASTER_USER_SYM 568
#define MASTER_USE_GTID_SYM 569
#define MASTER_HEARTBEAT_PERIOD_SYM 570
#define MATCH 571
#define MAX_CONNECTIONS_PER_HOUR 572
#define MAX_QUERIES_PER_HOUR 573
#define MAX_ROWS 574
#define MAX_SIZE_SYM 575
#define MAX_SYM 576
#define MAX_UPDATES_PER_HOUR 577
#define MAX_USER_CONNECTIONS_SYM 578
#define MAX_VALUE_SYM 579
#define MEDIUMBLOB 580
#define MEDIUMINT 581
#define MEDIUMTEXT 582
#define MEDIUM_SYM 583
#define MEMORY_SYM 584
#define MERGE_SYM 585
#define MESSAGE_TEXT_SYM 586
#define MICROSECOND_SYM 587
#define MIGRATE_SYM 588
#define MINUTE_MICROSECOND_SYM 589
#define MINUTE_SECOND_SYM 590
#define MINUTE_SYM 591
#define MIN_ROWS 592
#define MIN_SYM 593
#define MODE_SYM 594
#define MODIFIES_SYM 595
#define MODIFY_SYM 596
#define MOD_SYM 597
#define MONTH_SYM 598
#define MULTILINESTRING 599
#define MULTIPOINT 600
#define MULTIPOLYGON 601
#define MUTEX_SYM 602
#define MYSQL_ERRNO_SYM 603
#define NAMES_SYM 604
#define NAME_SYM 605
#define NATIONAL_SYM 606
#define NATURAL 607
#define NCHAR_STRING 608
#define NCHAR_SYM 609
#define NDBCLUSTER_SYM 610
#define NE 611
#define NEG 612
#define NEW_SYM 613
#define NEXT_SYM 614
#define NODEGROUP_SYM 615
#define NONE_SYM 616
#define NOT2_SYM 617
#define NOT_SYM 618
#define NOW_SYM 619
#define NO_SYM 620
#define NO_WAIT_SYM 621
#define NO_WRITE_TO_BINLOG 622
#define NULL_SYM 623
#define NUM 624
#define NUMBER_SYM 625
#define NUMERIC_SYM 626
#define NVARCHAR_SYM 627
#define OFFSET_SYM 628
#define OLD_PASSWORD 629
#define ON 630
#define ONE_SYM 631
#define ONLY_SYM 632
#define ONLINE_SYM 633
#define OPEN_SYM 634
#define OPTIMIZE 635
#define OPTIONS_SYM 636
#define OPTION 637
#define OPTIONALLY 638
#define OR2_SYM 639
#define ORDER_SYM 640
#define OR_OR_SYM 641
#define OR_SYM 642
#define OUTER 643
#define OUTFILE 644
#define OUT_SYM 645
#define OWNER_SYM 646
#define PACK_KEYS_SYM 647
#define PAGE_SYM 648
#define PAGE_CHECKSUM_SYM 649
#define PARAM_MARKER 650
#define PARSER_SYM 651
#define PARSE_VCOL_EXPR_SYM 652
#define PARTIAL 653
#define PARTITION_SYM 654
#define PARTITIONS_SYM 655
#define PARTITIONING_SYM 656
#define PASSWORD 657
#define PERSISTENT_SYM 658
#define PHASE_SYM 659
#define PLUGINS_SYM 660
#define PLUGIN_SYM 661
#define POINT_SYM 662
#define POLYGON 663
#define PORT_SYM 664
#define POSITION_SYM 665
#define PRECISION 666
#define PREPARE_SYM 667
#define PRESERVE_SYM 668
#define PREV_SYM 669
#define PRIMARY_SYM 670
#define PRIVILEGES 671
#define PROCEDURE_SYM 672
#define PROCESS 673
#define PROCESSLIST_SYM 674
#define PROFILE_SYM 675
#define PROFILES_SYM 676
#define PROXY_SYM 677
#define PURGE 678
#define QUARTER_SYM 679
#define QUERY_SYM 680
#define QUICK 681
#define RANGE_SYM 682
#define READS_SYM 683
#define READ_ONLY_SYM 684
#define READ_SYM 685
#define READ_WRITE_SYM 686
#define REAL 687
#define REBUILD_SYM 688
#define RECOVER_SYM 689
#define REDOFILE_SYM 690
#define REDO_BUFFER_SIZE_SYM 691
#define REDUNDANT_SYM 692
#define REFERENCES 693
#define REGEXP 694
#define RELAY 695
#define RELAYLOG_SYM 696
#define RELAY_LOG_FILE_SYM 697
#define RELAY_LOG_POS_SYM 698
#define RELAY_THREAD 699
#define RELEASE_SYM 700
#define RELOAD 701
#define REMOVE_SYM 702
#define RENAME 703
#define REORGANIZE_SYM 704
#define REPAIR 705
#define REPEATABLE_SYM 706
#define REPEAT_SYM 707
#define REPLACE 708
#define REPLICATION 709
#define REQUIRE_SYM 710
#define RESET_SYM 711
#define RESIGNAL_SYM 712
#define RESOURCES 713
#define RESTORE_SYM 714
#define RESTRICT 715
#define RESUME_SYM 716
#define RETURNED_SQLSTATE_SYM 717
#define RETURNING_SYM 718
#define RETURNS_SYM 719
#define RETURN_SYM 720
#define REVERSE_SYM 721
#define REVOKE 722
#define RIGHT 723
#define ROLE_SYM 724
#define ROLLBACK_SYM 725
#define ROLLUP_SYM 726
#define ROUTINE_SYM 727
#define ROWS_SYM 728
#define ROW_FORMAT_SYM 729
#define ROW_SYM 730
#define ROW_COUNT_SYM 731
#define RTREE_SYM 732
#define SAVEPOINT_SYM 733
#define SCHEDULE_SYM 734
#define SCHEMA_NAME_SYM 735
#define SECOND_MICROSECOND_SYM 736
#define SECOND_SYM 737
#define SECURITY_SYM 738
#define SELECT_SYM 739
#define SENSITIVE_SYM 740
#define SEPARATOR_SYM 741
#define SERIALIZABLE_SYM 742
#define SERIAL_SYM 743
#define SESSION_SYM 744
#define SERVER_SYM 745
#define SERVER_OPTIONS 746
#define SET 747
#define SET_VAR 748
#define SHARE_SYM 749
#define SHIFT_LEFT 750
#define SHIFT_RIGHT 751
#define SHOW 752
#define SHUTDOWN 753
#define SIGNAL_SYM 754
#define SIGNED_SYM 755
#define SIMPLE_SYM 756
#define SLAVE 757
#define SLAVES 758
#define SLAVE_POS_SYM 759
#define SLOW 760
#define SMALLINT 761
#define SNAPSHOT_SYM 762
#define SOCKET_SYM 763
#define SOFT_SYM 764
#define SONAME_SYM 765
#define SOUNDS_SYM 766
#define SOURCE_SYM 767
#define SPATIAL_SYM 768
#define SPECIFIC_SYM 769
#define SQLEXCEPTION_SYM 770
#define SQLSTATE_SYM 771
#define SQLWARNING_SYM 772
#define SQL_BIG_RESULT 773
#define SQL_BUFFER_RESULT 774
#define SQL_CACHE_SYM 775
#define SQL_CALC_FOUND_ROWS 776
#define SQL_NO_CACHE_SYM 777
#define SQL_SMALL_RESULT 778
#define SQL_SYM 779
#define SQL_THREAD 780
#define SSL_SYM 781
#define STARTING 782
#define STARTS_SYM 783
#define START_SYM 784
#define STATS_AUTO_RECALC_SYM 785
#define STATS_PERSISTENT_SYM 786
#define STATS_SAMPLE_PAGES_SYM 787
#define STATUS_SYM 788
#define STDDEV_SAMP_SYM 789
#define STD_SYM 790
#define STOP_SYM 791
#define STORAGE_SYM 792
#define STRAIGHT_JOIN 793
#define STRING_SYM 794
#define SUBCLASS_ORIGIN_SYM 795
#define SUBDATE_SYM 796
#define SUBJECT_SYM 797
#define SUBPARTITIONS_SYM 798
#define SUBPARTITION_SYM 799
#define SUBSTRING 800
#define SUM_SYM 801
#define SUPER_SYM 802
#define SUSPEND_SYM 803
#define SWAPS_SYM 804
#define SWITCHES_SYM 805
#define SYSDATE 806
#define TABLES 807
#define TABLESPACE 808
#define TABLE_REF_PRIORITY 809
#define TABLE_STATS_SYM 810
#define TABLE_SYM 811
#define TABLE_CHECKSUM_SYM 812
#define TABLE_NAME_SYM 813
#define TEMPORARY 814
#define TEMPTABLE_SYM 815
#define TERMINATED 816
#define TEXT_STRING 817
#define TEXT_SYM 818
#define THAN_SYM 819
#define THEN_SYM 820
#define TIMESTAMP 821
#define TIMESTAMP_ADD 822
#define TIMESTAMP_DIFF 823
#define TIME_SYM 824
#define TINYBLOB 825
#define TINYINT 826
#define TINYTEXT 827
#define TO_SYM 828
#define TRAILING 829
#define TRANSACTION_SYM 830
#define TRANSACTIONAL_SYM 831
#define TRIGGERS_SYM 832
#define TRIGGER_SYM 833
#define TRIM 834
#define TRUE_SYM 835
#define TRUNCATE_SYM 836
#define TYPES_SYM 837
#define TYPE_SYM 838
#define UDF_RETURNS_SYM 839
#define ULONGLONG_NUM 840
#define UNCOMMITTED_SYM 841
#define UNDEFINED_SYM 842
#define UNDERSCORE_CHARSET 843
#define UNDOFILE_SYM 844
#define UNDO_BUFFER_SIZE_SYM 845
#define UNDO_SYM 846
#define UNICODE_SYM 847
#define UNINSTALL_SYM 848
#define UNION_SYM 849
#define UNIQUE_SYM 850
#define UNKNOWN_SYM 851
#define UNLOCK_SYM 852
#define UNSIGNED 853
#define UNTIL_SYM 854
#define UPDATE_SYM 855
#define UPGRADE_SYM 856
#define USAGE 857
#define USER 858
#define USER_STATS_SYM 859
#define USE_FRM 860
#define USE_SYM 861
#define USING 862
#define UTC_DATE_SYM 863
#define UTC_TIMESTAMP_SYM 864
#define UTC_TIME_SYM 865
#define VALUES 866
#define VALUE_SYM 867
#define VARBINARY 868
#define VARCHAR 869
#define VARIABLES 870
#define VARIANCE_SYM 871
#define VARYING 872
#define VAR_SAMP_SYM 873
#define VIA_SYM 874
#define VIEW_SYM 875
#define VIRTUAL_SYM 876
#define WAIT_SYM 877
#define WARNINGS 878
#define WEEK_SYM 879
#define WEIGHT_STRING_SYM 880
#define WHEN_SYM 881
#define WHERE 882
#define WHILE_SYM 883
#define WITH 884
#define WITH_CUBE_SYM 885
#define WITH_ROLLUP_SYM 886
#define WORK_SYM 887
#define WRAPPER_SYM 888
#define WRITE_SYM 889
#define X509_SYM 890
#define XA_SYM 891
#define XML_SYM 892
#define XOR 893
#define YEAR_MONTH_SYM 894
#define YEAR_SYM 895
#define ZEROFILL 896
#define IMPOSSIBLE_ACTION 897




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 890 "/home/buildbot/buildbot/build/sql/sql_yacc.yy"

  int  num;
  ulong ulong_num;
  ulonglong ulonglong_number;
  longlong longlong_number;
  LEX_STRING lex_str;
  LEX_STRING *lex_str_ptr;
  LEX_SYMBOL symbol;
  Table_ident *table;
  char *simple_string;
  Item *item;
  Item_num *item_num;
  List<Item> *item_list;
  List<String> *string_list;
  String *string;
  Key_part_spec *key_part;
  TABLE_LIST *table_list;
  udf_func *udf;
  LEX_USER *lex_user;
  struct sys_var_with_base variable;
  enum enum_var_type var_type;
  Key::Keytype key_type;
  enum ha_key_alg key_alg;
  handlerton *db_type;
  enum row_type row_type;
  enum ha_rkey_function ha_rkey_mode;
  enum enum_tx_isolation tx_isolation;
  enum Cast_target cast_type;
  enum Item_udftype udf_type;
  enum ha_choice choice;
  CHARSET_INFO *charset;
  thr_lock_type lock_type;
  interval_type interval, interval_time_st;
  timestamp_type date_time_type;
  st_select_lex *select_lex;
  chooser_compare_func_creator boolfunc2creator;
  class sp_condition_value *spcondvalue;
  struct { int vars, conds, hndlrs, curs; } spblock;
  sp_name *spname;
  LEX *lex;
  sp_head *sphead;
  struct p_elem_val *p_elem_value;
  enum index_hint_type index_hint;
  enum enum_filetype filetype;
  enum Foreign_key::fk_option m_fk_option;
  enum enum_yes_no_unknown m_yes_no_unk;
  Diag_condition_item_name diag_condition_item_name;
  Diagnostics_information::Which_area diag_area;
  Diagnostics_information *diag_info;
  Statement_information_item *stmt_info_item;
  Statement_information_item::Name stmt_info_item_name;
  List<Statement_information_item> *stmt_info_list;
  Condition_information_item *cond_info_item;
  Condition_information_item::Name cond_info_item_name;
  List<Condition_information_item> *cond_info_list;
  DYNCALL_CREATE_DEF *dyncol_def;
  List<DYNCALL_CREATE_DEF> *dyncol_def_list;
  bool is_not_empty;



/* Line 1676 of yacc.c  */
#line 1398 "/home/buildbot/buildbot/build/mkdist/sql/sql_yacc.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif




