
/*  A Bison parser, made from grammar.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TYPE	257
#define	VAR	258
#define	FUNCNAME	259
#define	NUMBER	260
#define	MEMBER	261
#define	MEMBERFUNC	262
#define	IMPORT	263
#define	STARTSTATEBLOCK	264
#define	ENDSTATEBLOCK	265
#define	IF	266
#define	ELSE	267
#define	FOR	268
#define	WHILE	269
#define	BREAK	270
#define	OBJECT	271
#define	RETURN	272
#define	TIME	273
#define	SPLINETYPE	274
#define	COMPARISON	275
#define	UMINUS	276
#define	STRING	277
#define	QSTRING	278
#define	POW	279
#define	CAST	280

#line 1 "grammar.y"

/* 
 *  This is the grammar for PEDAL. 
 */
#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		175
#define	YYFLAG		-32768
#define	YYNTBASE	46

#define YYTRANSLATE(x) ((unsigned)(x) <= 280 ? yytranslate[x] : 72)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    45,     2,     2,     2,     2,     2,     2,    43,
    44,    28,    27,    42,    26,    31,    29,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    34,    35,    38,
    25,    39,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    40,     2,    41,    30,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    36,     2,    37,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    32,    33
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     6,     8,    10,    12,    14,    20,    26,    31,
    33,    35,    37,    39,    41,    43,    47,    50,    52,    53,
    55,    59,    63,    67,    69,    72,    77,    81,    87,    92,
    93,    96,    97,   101,   103,   104,   109,   113,   116,   117,
   120,   122,   127,   131,   140,   146,   154,   164,   170,   172,
   176,   180,   184,   187,   192,   196,   198,   200,   202,   206,
   209,   212,   216,   220,   224,   228,   232,   236,   240,   244,
   248,   253,   260,   265,   270,   272,   274,   276,   278,   282,
   284,   286
};

static const short yyrhs[] = {    47,
     0,    47,    35,    48,     0,    48,     0,    51,     0,    50,
     0,    49,     0,    17,    23,    36,    62,    37,     0,     3,
    56,    23,    59,    52,     0,     3,    23,    59,    52,     0,
    54,     0,    64,     0,    65,     0,    66,     0,    52,     0,
    69,     0,    38,    69,    39,     0,    18,    69,     0,    55,
     0,     0,     1,     0,    10,    53,    11,     0,    36,    53,
    37,     0,    53,    35,    51,     0,    51,     0,     9,    24,
     0,     3,    56,    23,    58,     0,     3,    23,    58,     0,
    56,    40,     6,    57,    41,     0,    40,     6,    57,    41,
     0,     0,    25,    69,     0,     0,    59,    42,    60,     0,
    60,     0,     0,     3,    56,    23,    61,     0,     3,    23,
    61,     0,    25,    69,     0,     0,    62,    63,     0,    63,
     0,     3,    56,    23,    35,     0,     3,    23,    35,     0,
     3,    23,    43,    59,    44,    36,    53,    37,     0,    12,
    43,    67,    44,    52,     0,    12,    43,    67,    44,    52,
    13,    52,     0,    14,    43,    69,    35,    67,    35,    69,
    44,    52,     0,    15,    43,    67,    44,    52,     0,    69,
     0,    69,    21,    69,     0,    69,    38,    69,     0,    69,
    39,    69,     0,    45,    69,     0,    68,    40,    69,    41,
     0,    68,    34,     7,     0,     7,     0,     4,     0,    68,
     0,    68,    25,    69,     0,    26,    69,     0,    27,    69,
     0,    69,    27,    69,     0,    69,    26,    69,     0,    69,
    28,    69,     0,    69,    29,    69,     0,    69,    32,    69,
     0,    69,    31,    69,     0,    69,    30,    69,     0,    43,
    69,    44,     0,    40,    70,    41,     0,     5,    43,    70,
    44,     0,    68,    34,     8,    43,    70,    44,     0,     8,
    43,    70,    44,     0,    43,     3,    44,    69,     0,     6,
     0,    19,     0,    24,     0,    23,     0,    70,    42,    71,
     0,    71,     0,    69,     0,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    26,    30,    32,    35,    37,    38,    41,    45,    47,    50,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    64,    66,    69,    71,    74,    78,    80,    83,    85,    88,
    91,    93,    97,    99,   100,   103,   105,   108,   110,   113,
   115,   118,   120,   121,   124,   126,   129,   133,   137,   139,
   140,   141,   142,   145,   147,   148,   149,   152,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   176,   178,
   181,   183
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","TYPE","VAR",
"FUNCNAME","NUMBER","MEMBER","MEMBERFUNC","IMPORT","STARTSTATEBLOCK","ENDSTATEBLOCK",
"IF","ELSE","FOR","WHILE","BREAK","OBJECT","RETURN","TIME","SPLINETYPE","COMPARISON",
"UMINUS","STRING","QSTRING","'='","'-'","'+'","'*'","'/'","'^'","'.'","POW",
"CAST","':'","';'","'{'","'}'","'<'","'>'","'['","']'","','","'('","')'","'!'",
"program","statement_list","statement","object_declaration","function_declaration",
"control_statement","block_statement","control_statement_list","import","variable_declaration",
"arrayspec","splinespec","initspec","param_list","param","default_spec","field_list",
"field","if_statement","for_statement","while_statement","condition","lvalue",
"expression","explist","exp", NULL
};
#endif

static const short yyr1[] = {     0,
    46,    47,    47,    48,    48,    48,    49,    50,    50,    51,
    51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
    52,    52,    53,    53,    54,    55,    55,    56,    56,    57,
    58,    58,    59,    59,    59,    60,    60,    61,    61,    62,
    62,    63,    63,    63,    64,    64,    65,    66,    67,    67,
    67,    67,    67,    68,    68,    68,    68,    69,    69,    69,
    69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
    69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
    71,    71
};

static const short yyr2[] = {     0,
     1,     3,     1,     1,     1,     1,     5,     5,     4,     1,
     1,     1,     1,     1,     1,     3,     2,     1,     0,     1,
     3,     3,     3,     1,     2,     4,     3,     5,     4,     0,
     2,     0,     3,     1,     0,     4,     3,     2,     0,     2,
     1,     4,     3,     8,     5,     7,     9,     5,     1,     3,
     3,     3,     2,     4,     3,     1,     1,     1,     3,     2,
     2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     4,     6,     4,     4,     1,     1,     1,     1,     3,     1,
     1,     0
};

static const short yydefact[] = {     0,
    20,     0,    57,     0,    75,    56,     0,     0,     0,     0,
     0,     0,     0,     0,    76,    78,    77,     0,     0,     0,
     0,    82,     0,     1,     3,     6,     5,     4,    14,    10,
    18,    11,    12,    13,    58,    15,    35,     0,     0,    82,
    82,    25,     0,    24,     0,     0,     0,     0,     0,    17,
    60,    61,     0,     0,    81,     0,    80,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    27,     0,    34,    30,    35,     0,     0,     0,
    32,     0,    21,     0,     0,     0,    49,     0,     0,     0,
    22,    16,    70,    82,     0,    69,     2,    59,    55,     0,
     0,    63,    62,    64,    65,    68,    67,    66,    39,     0,
    31,     0,     9,     0,    26,     0,    30,    71,    73,    32,
    23,    53,     0,     0,     0,     0,     0,     0,     0,     0,
    41,    79,    74,    82,    54,     0,    37,    39,    33,    29,
     8,     0,    45,    50,    51,    52,     0,    48,     0,     0,
     7,    40,     0,    38,    36,    28,     0,     0,    43,    35,
     0,    72,    46,     0,     0,    42,     0,     0,    47,     0,
     0,    44,     0,     0,     0
};

static const short yydefgoto[] = {   173,
    24,    25,    26,    27,    44,    29,    45,    30,    31,    39,
   114,    73,    74,    75,   137,   130,   131,    32,    33,    34,
    86,    35,    36,    56,    57
};

static const short yypact[] = {   125,
-32768,    -4,-32768,   -23,-32768,-32768,    -5,     6,   207,    50,
    54,    61,    84,   298,-32768,-32768,-32768,   298,   298,   248,
   298,   298,   273,    14,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    55,   168,    12,   114,    -1,   298,
   298,-32768,     1,-32768,    10,    79,   298,    79,    91,   168,
-32768,-32768,    29,   127,   168,    27,-32768,    97,   319,   125,
   298,    93,   298,   298,   298,   298,   298,   298,   298,   298,
     2,   298,-32768,     4,-32768,-32768,    12,   140,    66,    73,
   122,     3,-32768,   166,   298,   118,   305,   209,   120,   176,
-32768,-32768,-32768,   298,   298,-32768,-32768,   168,-32768,   139,
   345,    45,    45,   155,   155,   155,   155,-32768,   158,    38,
   168,   188,-32768,   164,-32768,     4,-32768,-32768,-32768,   122,
-32768,   168,     8,   298,   298,   298,    79,     8,    39,    26,
-32768,-32768,-32768,   298,-32768,   298,-32768,   158,-32768,-32768,
-32768,   179,   194,   168,   168,   168,   189,-32768,   -12,    48,
-32768,-32768,    74,   168,-32768,-32768,     8,   298,-32768,   188,
   192,-32768,-32768,   326,    94,-32768,     8,   187,-32768,   248,
   151,-32768,   228,   229,-32768
};

static const short yypgoto[] = {-32768,
-32768,   172,-32768,-32768,     7,   -58,   -20,-32768,-32768,   -39,
   129,   -60,   -66,   136,   121,-32768,   131,-32768,-32768,-32768,
   -35,-32768,   -13,   -38,   170
};


#define	YYLAST		386


static const short yytable[] = {    53,
    50,    79,    80,    82,    51,    52,    28,    54,    55,    59,
   116,   -32,    89,     9,    71,   113,   115,     9,    37,    40,
    83,    77,   159,    81,   109,   120,    55,    55,   129,    42,
   160,   110,    87,    88,    87,    38,    72,    41,    78,    20,
    38,    38,    78,    20,    84,   112,   -32,    98,    60,   101,
   102,   103,   104,   105,   106,   107,   108,   141,   111,   115,
   138,   149,   151,    84,   143,    91,    28,    93,    94,   148,
   161,   122,    66,    67,    68,    69,    70,    78,    38,    61,
    55,   133,     3,     4,     5,     6,     7,    78,    62,   150,
   121,   147,    46,   165,    63,   153,    47,    15,   163,    99,
   100,    16,    17,    48,    18,    19,    49,    94,   169,   118,
   144,   145,   146,    87,    94,    94,   119,   162,    22,    76,
    55,    23,   154,    85,   -19,     1,    90,     2,     3,     4,
     5,     6,     7,     8,     9,   112,    10,   168,    11,    12,
    95,    13,    14,    15,   164,   117,    72,    16,    17,   171,
    18,    19,    64,    65,    66,    67,    68,    69,    70,   -19,
    20,   123,    21,   128,    22,    92,     1,    23,    43,     3,
     4,     5,     6,     7,     8,     9,   -19,    10,   129,    11,
    12,   134,   136,    14,    15,    84,    70,   172,    16,    17,
    71,    18,    19,    64,    65,    66,    67,    68,    69,    70,
   -19,    20,   -19,    21,   140,    22,   157,     1,    23,    43,
     3,     4,     5,     6,     7,     8,     9,   -19,    10,   156,
    11,    12,   170,   158,    14,    15,   166,   174,   175,    16,
    17,    97,    18,    19,    64,    65,    66,    67,    68,    69,
    70,   -19,    20,   127,    21,   142,    22,   139,     1,    23,
    43,     3,     4,     5,     6,     7,     8,     9,   155,    10,
   152,    11,    12,   132,     0,    14,    15,     0,     0,     0,
    16,    17,     0,    18,    19,    58,     3,     4,     5,     6,
     7,     0,   -19,    20,   -19,    21,     0,    22,     0,     0,
    23,    15,     0,     0,     0,    16,    17,     0,    18,    19,
     0,     3,     4,     5,     6,     7,     0,     0,     0,     0,
     0,     0,    22,     0,     0,    23,    15,     0,     0,     0,
    16,    17,     0,    18,    19,   124,     0,     0,     0,     0,
    64,    65,    66,    67,    68,    69,    70,    22,     0,     0,
    23,     0,   125,   126,    64,    65,    66,    67,    68,    69,
    70,    64,    65,    66,    67,    68,    69,    70,     0,     0,
     0,     0,    96,     0,     0,     0,     0,     0,     0,   167,
    64,    65,    66,    67,    68,    69,    70,     0,     0,     0,
     0,     0,     0,     0,     0,   135
};

static const short yycheck[] = {    20,
    14,    40,    41,    43,    18,    19,     0,    21,    22,    23,
    77,     0,    48,    10,     3,    74,    77,    10,    23,    43,
    11,    23,    35,    23,    23,    23,    40,    41,     3,    24,
    43,    71,    46,    47,    48,    40,    25,    43,    40,    36,
    40,    40,    40,    36,    35,    42,    35,    61,    35,    63,
    64,    65,    66,    67,    68,    69,    70,   116,    72,   120,
    23,    23,    37,    35,   123,    37,    60,    41,    42,   128,
    23,    85,    28,    29,    30,    31,    32,    40,    40,    25,
    94,    95,     4,     5,     6,     7,     8,    40,    34,   129,
    84,   127,    43,   160,    40,   134,    43,    19,   157,     7,
     8,    23,    24,    43,    26,    27,    23,    42,   167,    44,
   124,   125,   126,   127,    42,    42,    44,    44,    40,     6,
   134,    43,   136,    45,     0,     1,    36,     3,     4,     5,
     6,     7,     8,     9,    10,    42,    12,    44,    14,    15,
    44,    17,    18,    19,   158,     6,    25,    23,    24,   170,
    26,    27,    26,    27,    28,    29,    30,    31,    32,    35,
    36,    44,    38,    44,    40,    39,     1,    43,     3,     4,
     5,     6,     7,     8,     9,    10,    11,    12,     3,    14,
    15,    43,    25,    18,    19,    35,    32,    37,    23,    24,
     3,    26,    27,    26,    27,    28,    29,    30,    31,    32,
    35,    36,    37,    38,    41,    40,    13,     1,    43,     3,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    41,
    14,    15,    36,    35,    18,    19,    35,     0,     0,    23,
    24,    60,    26,    27,    26,    27,    28,    29,    30,    31,
    32,    35,    36,    35,    38,   117,    40,   112,     1,    43,
     3,     4,     5,     6,     7,     8,     9,    10,   138,    12,
   130,    14,    15,    94,    -1,    18,    19,    -1,    -1,    -1,
    23,    24,    -1,    26,    27,     3,     4,     5,     6,     7,
     8,    -1,    35,    36,    37,    38,    -1,    40,    -1,    -1,
    43,    19,    -1,    -1,    -1,    23,    24,    -1,    26,    27,
    -1,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
    -1,    -1,    40,    -1,    -1,    43,    19,    -1,    -1,    -1,
    23,    24,    -1,    26,    27,    21,    -1,    -1,    -1,    -1,
    26,    27,    28,    29,    30,    31,    32,    40,    -1,    -1,
    43,    -1,    38,    39,    26,    27,    28,    29,    30,    31,
    32,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    44,
    26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    41
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/lib/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/lib/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/lib/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 186 "grammar.y"

