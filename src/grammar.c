/* A Bison parser, made from grammar.y
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

# define	TYPE	257
# define	VAR	258
# define	FUNCNAME	259
# define	NUMBER	260
# define	MEMBER	261
# define	MEMBERFUNC	262
# define	IMPORT	263
# define	STARTSTATEBLOCK	264
# define	ENDSTATEBLOCK	265
# define	IF	266
# define	ELSE	267
# define	FOR	268
# define	WHILE	269
# define	BREAK	270
# define	OBJECT	271
# define	RETURN	272
# define	TIME	273
# define	BASISFUNC	274
# define	COMPARISON	275
# define	UMINUS	276
# define	STRING	277
# define	QSTRING	278
# define	CIRCUMFLEX	279
# define	POW	280
# define	CAST	281

#line 1 "grammar.y"

/* 
 *  This is the grammar for PEDAL. 
 */
#ifndef YYSTYPE
# define YYSTYPE int
# define YYSTYPE_IS_TRIVIAL 1
#endif
#ifndef YYDEBUG
# define YYDEBUG 0
#endif



#define	YYFINAL		186
#define	YYFLAG		-32768
#define	YYNTBASE	48

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 281 ? yytranslate[x] : 76)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,     2,     2,    41,     2,     2,
      42,    43,    29,    28,    44,    27,    32,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    36,
      39,    26,    40,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      33,    34
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     2,     6,     8,    10,    12,    14,    20,    26,
      31,    33,    35,    37,    39,    41,    43,    47,    50,    52,
      53,    55,    59,    67,    71,    73,    77,    79,    83,    85,
      88,    93,    97,   103,   108,   109,   112,   113,   117,   119,
     120,   125,   129,   131,   134,   135,   138,   140,   145,   149,
     158,   164,   172,   182,   188,   190,   194,   198,   202,   205,
     210,   214,   216,   218,   221,   224,   226,   230,   234,   238,
     242,   246,   250,   254,   258,   262,   266,   271,   278,   283,
     288,   290,   292,   294,   298,   300,   302
};
static const short yyrhs[] =
{
      49,     0,    49,    36,    50,     0,    50,     0,    53,     0,
      52,     0,    51,     0,    17,    23,    37,    66,    38,     0,
       3,    60,    23,    63,    54,     0,     3,    23,    63,    54,
       0,    58,     0,    68,     0,    69,     0,    70,     0,    54,
       0,    73,     0,    39,    73,    40,     0,    18,    73,     0,
      59,     0,     0,     1,     0,    10,    57,    11,     0,    41,
      42,    55,    43,    37,    57,    11,     0,    37,    57,    38,
       0,    56,     0,    55,    44,    56,     0,    23,     0,    57,
      36,    53,     0,    53,     0,     9,    24,     0,     3,    60,
      23,    62,     0,     3,    23,    62,     0,    60,    45,     6,
      61,    46,     0,    45,     6,    61,    46,     0,     0,    26,
      73,     0,     0,    63,    44,    64,     0,    64,     0,     0,
       3,    60,    23,    65,     0,     3,    23,    65,     0,    25,
       0,    26,    73,     0,     0,    66,    67,     0,    67,     0,
       3,    60,    23,    36,     0,     3,    23,    36,     0,     3,
      23,    42,    63,    43,    37,    57,    38,     0,    12,    42,
      71,    43,    54,     0,    12,    42,    71,    43,    54,    13,
      54,     0,    14,    42,    73,    36,    71,    36,    73,    43,
      54,     0,    15,    42,    71,    43,    54,     0,    73,     0,
      73,    21,    73,     0,    73,    39,    73,     0,    73,    40,
      73,     0,    47,    73,     0,    72,    45,    73,    46,     0,
      72,    35,     7,     0,     7,     0,     4,     0,    27,    73,
       0,    28,    73,     0,    72,     0,    72,    26,    73,     0,
      73,    28,    73,     0,    73,    27,    73,     0,    73,    29,
      73,     0,    73,    30,    73,     0,    73,    33,    73,     0,
      73,    32,    73,     0,    73,    31,    73,     0,    42,    73,
      43,     0,    45,    74,    46,     0,     5,    42,    74,    43,
       0,    72,    35,     8,    42,    74,    43,     0,     8,    42,
      74,    43,     0,    42,     3,    43,    73,     0,     6,     0,
      19,     0,    24,     0,    74,    44,    75,     0,    75,     0,
      73,     0,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,    26,    30,    32,    35,    37,    38,    41,    45,    47,
      50,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    64,    66,    67,    70,    72,    75,    79,    81,    84,
      88,    90,    93,    95,    98,   101,   103,   107,   109,   110,
     113,   115,   116,   119,   121,   124,   126,   129,   131,   132,
     135,   137,   140,   144,   148,   150,   151,   152,   153,   156,
     158,   159,   160,   163,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   186,   188,   191,   193
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "TYPE", "VAR", "FUNCNAME", "NUMBER", 
  "MEMBER", "MEMBERFUNC", "IMPORT", "STARTSTATEBLOCK", "ENDSTATEBLOCK", 
  "IF", "ELSE", "FOR", "WHILE", "BREAK", "OBJECT", "RETURN", "TIME", 
  "BASISFUNC", "COMPARISON", "UMINUS", "STRING", "QSTRING", "CIRCUMFLEX", 
  "'='", "'-'", "'+'", "'*'", "'/'", "'^'", "'.'", "POW", "CAST", "':'", 
  "';'", "'{'", "'}'", "'<'", "'>'", "'%'", "'('", "')'", "','", "'['", 
  "']'", "'!'", "program", "statement_list", "statement", 
  "object_declaration", "function_declaration", "control_statement", 
  "block_statement", "stateclass_list", "state", "control_statement_list", 
  "import", "variable_declaration", "arrayspec", "basisspec", "initspec", 
  "param_list", "param", "default_spec", "field_list", "field", 
  "if_statement", "for_statement", "while_statement", "condition", 
  "lvalue", "expression", "explist", "exp", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,    48,    49,    49,    50,    50,    50,    51,    52,    52,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    54,    55,    55,    56,    57,    57,    58,
      59,    59,    60,    60,    61,    62,    62,    63,    63,    63,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    67,
      68,    68,    69,    70,    71,    71,    71,    71,    71,    72,
      72,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     1,     3,     1,     1,     1,     1,     5,     5,     4,
       1,     1,     1,     1,     1,     1,     3,     2,     1,     0,
       1,     3,     7,     3,     1,     3,     1,     3,     1,     2,
       4,     3,     5,     4,     0,     2,     0,     3,     1,     0,
       4,     3,     1,     2,     0,     2,     1,     4,     3,     8,
       5,     7,     9,     5,     1,     3,     3,     3,     2,     4,
       3,     1,     1,     2,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     6,     4,     4,
       1,     1,     1,     3,     1,     1,     0
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
       0,    20,     0,    62,     0,    80,    61,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    82,     0,     0,     0,
       0,     0,     0,    86,     1,     3,     6,     5,     4,    14,
      10,    18,    11,    12,    13,    65,    15,    39,     0,     0,
      86,    86,    29,     0,    28,     0,     0,     0,     0,     0,
      17,    63,    64,     0,     0,     0,     0,     0,    85,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,    31,     0,    38,    34,    39,
       0,     0,     0,    36,     0,    21,     0,     0,     0,    54,
       0,     0,     0,    23,    16,    26,     0,    24,     0,    74,
      86,    75,     2,    66,    60,     0,     0,    68,    67,    69,
      70,    73,    72,    71,    44,     0,    35,     0,     9,     0,
      30,     0,    34,    76,    78,    36,    27,    58,     0,     0,
       0,     0,     0,     0,     0,     0,    46,     0,     0,    79,
      83,    86,    59,     0,    41,    44,    37,    33,     8,     0,
      50,    55,    56,    57,     0,    53,     0,     0,     7,    45,
       0,    25,     0,    43,    40,    32,     0,     0,    48,    39,
       0,     0,    77,    51,     0,     0,    47,    22,     0,     0,
      52,     0,     0,    49,     0,     0,     0
};

static const short yydefgoto[] =
{
     184,    24,    25,    26,    27,    44,    29,    96,    97,    45,
      30,    31,    39,   119,    75,    76,    77,   144,   135,   136,
      32,    33,    34,    88,    35,    36,    59,    60
};

static const short yypact[] =
{
     160,-32768,    -3,-32768,   -23,-32768,-32768,   -16,    12,   246,
      27,    29,    46,    16,   131,-32768,-32768,   131,   131,   289,
     131,    60,   316,   131,    47,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,   107,   205,    40,   101,     0,
     131,   131,-32768,    15,-32768,     5,    87,   131,    87,   114,
     205,-32768,-32768,   -14,   116,   108,   110,   335,   205,   -15,
  -32768,   160,   131,    74,   131,   131,   131,   131,   131,   131,
     131,   131,    39,-32768,   131,-32768,    36,-32768,-32768,    40,
     151,    61,    66,   145,    41,-32768,   203,   131,   142,   320,
     162,   143,   197,-32768,-32768,-32768,    69,-32768,   131,-32768,
     131,-32768,-32768,   205,-32768,   161,    94,   247,   247,   183,
     183,   183,   183,-32768,   193,    44,   205,    65,-32768,   174,
  -32768,    36,-32768,-32768,-32768,   145,-32768,   205,     7,   131,
     131,   131,    87,     7,    55,     9,-32768,   186,   108,-32768,
  -32768,   131,-32768,   131,-32768,   193,-32768,-32768,-32768,   178,
     212,   205,   205,   205,   190,-32768,   -21,    56,-32768,-32768,
     246,-32768,   137,   205,-32768,-32768,     7,   131,-32768,    65,
     192,    14,-32768,-32768,   342,   139,-32768,-32768,     7,   206,
  -32768,   289,    -6,-32768,   229,   259,-32768
};

static const short yypgoto[] =
{
  -32768,-32768,   185,-32768,-32768,    11,   -58,-32768,   124,   -19,
  -32768,-32768,   -35,   141,   -66,   -73,   149,   122,-32768,   133,
  -32768,-32768,-32768,   -34,-32768,   -13,   -38,   169
};


#define	YYLAST		385


static const short yytable[] =
{
      53,    50,    81,    82,    51,    52,   121,    54,    84,    57,
      58,    28,   134,   120,    91,   168,    85,     9,   118,    40,
      37,   169,    86,    79,    93,   177,    41,    58,    58,   100,
      86,   101,   183,    89,    90,    89,    42,   115,    83,    49,
     -36,    86,    38,    72,    19,    80,     9,   158,    21,   103,
      86,   106,   107,   108,   109,   110,   111,   112,   113,   120,
      38,   116,   114,   148,   125,    73,    74,   145,    72,    46,
     150,    47,    28,    19,   127,   155,   -36,    21,   156,   170,
     117,   104,   105,    61,    38,   139,    80,    58,    48,    80,
      73,     3,     4,     5,     6,     7,   175,   126,   154,   157,
      38,    80,    55,   162,   123,   100,    15,    78,   173,   124,
     100,    16,   137,   138,    17,    18,   151,   152,   153,    89,
     180,    65,    66,    67,    68,    69,    70,    71,    58,    22,
     163,    95,    23,    62,    87,     3,     4,     5,     6,     7,
     142,   171,    63,    65,    66,    67,    68,    69,    70,    71,
      15,    92,    64,    98,   174,    16,    94,   122,    17,    18,
     -19,     1,   182,     2,     3,     4,     5,     6,     7,     8,
       9,    74,    10,    22,    11,    12,    23,    13,    14,    15,
     172,   100,   179,   117,    16,   128,   133,    17,    18,    65,
      66,    67,    68,    69,    70,    71,   -19,    19,   132,    20,
     134,    21,    22,   141,     1,    23,    43,     3,     4,     5,
       6,     7,     8,     9,   -19,    10,    71,    11,    12,   143,
     147,    14,    15,   160,   165,   166,   167,    16,   176,   185,
      17,    18,    65,    66,    67,    68,    69,    70,    71,   -19,
      19,   -19,    20,   181,    21,    22,   102,     1,    23,    43,
       3,     4,     5,     6,     7,     8,     9,   -19,    10,   186,
      11,    12,   161,   149,    14,    15,   146,   164,   159,   140,
      16,     0,     0,    17,    18,     0,    67,    68,    69,    70,
      71,     0,   -19,    19,     0,    20,     0,    21,    22,     0,
       1,    23,    43,     3,     4,     5,     6,     7,     8,     9,
       0,    10,     0,    11,    12,     0,     0,    14,    15,     0,
       0,     0,     0,    16,     0,     0,    17,    18,     0,    56,
       3,     4,     5,     6,     7,   -19,    19,   -19,    20,     0,
      21,    22,     0,     0,    23,    15,     0,     0,     0,     0,
      16,   129,     0,    17,    18,     0,     0,    65,    66,    67,
      68,    69,    70,    71,     0,     0,     0,     0,    22,   130,
     131,    23,    65,    66,    67,    68,    69,    70,    71,    65,
      66,    67,    68,    69,    70,    71,     0,     0,    99,     0,
       0,     0,     0,     0,     0,   178
};

static const short yycheck[] =
{
      19,    14,    40,    41,    17,    18,    79,    20,    43,    22,
      23,     0,     3,    79,    48,    36,    11,    10,    76,    42,
      23,    42,    36,    23,    38,    11,    42,    40,    41,    44,
      36,    46,    38,    46,    47,    48,    24,    72,    23,    23,
       0,    36,    45,     3,    37,    45,    10,    38,    41,    62,
      36,    64,    65,    66,    67,    68,    69,    70,    71,   125,
      45,    74,    23,   121,    23,    25,    26,    23,     3,    42,
     128,    42,    61,    37,    87,   133,    36,    41,    23,    23,
      44,     7,     8,    36,    45,    98,    45,   100,    42,    45,
      25,     4,     5,     6,     7,     8,   169,    86,   132,   134,
      45,    45,    42,   141,    43,    44,    19,     6,   166,    43,
      44,    24,    43,    44,    27,    28,   129,   130,   131,   132,
     178,    27,    28,    29,    30,    31,    32,    33,   141,    42,
     143,    23,    45,    26,    47,     4,     5,     6,     7,     8,
      46,   160,    35,    27,    28,    29,    30,    31,    32,    33,
      19,    37,    45,    43,   167,    24,    40,     6,    27,    28,
       0,     1,   181,     3,     4,     5,     6,     7,     8,     9,
      10,    26,    12,    42,    14,    15,    45,    17,    18,    19,
      43,    44,    43,    44,    24,    43,    43,    27,    28,    27,
      28,    29,    30,    31,    32,    33,    36,    37,    36,    39,
       3,    41,    42,    42,     1,    45,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    33,    14,    15,    26,
      46,    18,    19,    37,    46,    13,    36,    24,    36,     0,
      27,    28,    27,    28,    29,    30,    31,    32,    33,    36,
      37,    38,    39,    37,    41,    42,    61,     1,    45,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      14,    15,   138,   122,    18,    19,   117,   145,   135,   100,
      24,    -1,    -1,    27,    28,    -1,    29,    30,    31,    32,
      33,    -1,    36,    37,    -1,    39,    -1,    41,    42,    -1,
       1,    45,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    -1,    14,    15,    -1,    -1,    18,    19,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    27,    28,    -1,     3,
       4,     5,     6,     7,     8,    36,    37,    38,    39,    -1,
      41,    42,    -1,    -1,    45,    19,    -1,    -1,    -1,    -1,
      24,    21,    -1,    27,    28,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    42,    39,
      40,    45,    27,    28,    29,    30,    31,    32,    33,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    43
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/share/bison/bison.simple"

/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
   Foundation, Inc.

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

/* This is the parser code that is written into each bison parser when
   the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
# if YYLSP_NEEDED
  YYLTYPE yyls;
# endif
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# if YYLSP_NEEDED
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAX)
# else
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)
# endif

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif


#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).

   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
   first token.  By default, to implement support for ranges, extend
   its range to the last symbol.  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)       	\
   Current.last_line   = Rhs[N].last_line;	\
   Current.last_column = Rhs[N].last_column;
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#if YYPURE
# if YYLSP_NEEDED
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, &yylloc, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval, &yylloc)
#  endif
# else /* !YYLSP_NEEDED */
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval)
#  endif
# endif /* !YYLSP_NEEDED */
#else /* !YYPURE */
# define YYLEX			yylex ()
#endif /* !YYPURE */


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

#ifdef YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif
#endif

#line 315 "/usr/share/bison/bison.simple"


/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif

/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
   variables are global, or local to YYPARSE.  */

#define YY_DECL_NON_LSP_VARIABLES			\
/* The lookahead symbol.  */				\
int yychar;						\
							\
/* The semantic value of the lookahead symbol. */	\
YYSTYPE yylval;						\
							\
/* Number of parse errors so far.  */			\
int yynerrs;

#if YYLSP_NEEDED
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES			\
						\
/* Location data for the lookahead symbol.  */	\
YYLTYPE yylloc;
#else
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES
#endif


/* If nonreentrant, generate the variables here. */

#if !YYPURE
YY_DECL_VARIABLES
#endif  /* !YYPURE */

int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* If reentrant, generate the variables here. */
#if YYPURE
  YY_DECL_VARIABLES
#endif  /* !YYPURE */

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack. */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

#if YYLSP_NEEDED
  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
#endif

#if YYLSP_NEEDED
# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
# define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
#if YYLSP_NEEDED
  YYLTYPE yyloc;
#endif

  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
#if YYLSP_NEEDED
  yylsp = yyls;
#endif
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  */
# if YYLSP_NEEDED
	YYLTYPE *yyls1 = yyls;
	/* This used to be a conditional around just the two extra args,
	   but that might be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
# else
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);
# endif
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
# if YYLSP_NEEDED
	YYSTACK_RELOCATE (yyls);
# endif
# undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
#if YYLSP_NEEDED
      yylsp = yyls + yysize - 1;
#endif

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
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
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

#if YYDEBUG
     /* We have to keep this `#if YYDEBUG', since we use variables
	which are defined only if `YYDEBUG' is set.  */
      if (yydebug)
	{
	  YYFPRINTF (stderr, "Next token is %d (%s",
		     yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise
	     meaning of a token, for further debugging info.  */
# ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
# endif
	  YYFPRINTF (stderr, ")\n");
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
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

#if YYLSP_NEEDED
  /* Similarly for the default location.  Let the user run additional
     commands if for instance locations are ranges.  */
  yyloc = yylsp[1-yylen];
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
#endif

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif

  switch (yyn) {

}

#line 705 "/usr/share/bison/bison.simple"


  yyvsp -= yylen;
  yyssp -= yylen;
#if YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;
#if YYLSP_NEEDED
  *++yylsp = yyloc;
#endif

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* defined (YYERROR_VERBOSE) */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*--------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action |
`--------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;
      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;


/*-------------------------------------------------------------------.
| yyerrdefault -- current state does not do anything special for the |
| error token.                                                       |
`-------------------------------------------------------------------*/
yyerrdefault:
#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */

  /* If its default is to accept any token, ok.  Otherwise pop it.  */
  yyn = yydefact[yystate];
  if (yyn)
    goto yydefault;
#endif


/*---------------------------------------------------------------.
| yyerrpop -- pop the current state because it cannot handle the |
| error token                                                    |
`---------------------------------------------------------------*/
yyerrpop:
  if (yyssp == yyss)
    YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#if YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "Error: state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

/*--------------.
| yyerrhandle.  |
`--------------*/
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

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

/*---------------------------------------------.
| yyoverflowab -- parser overflow comes here.  |
`---------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}
#line 196 "grammar.y"

