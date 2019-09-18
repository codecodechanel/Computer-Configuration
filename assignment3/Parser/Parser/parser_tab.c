
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TIDEN	258
#define	TNUMBER	259
#define	TCONST	260
#define	TIF	261
#define	TINT	262
#define	TRETURN	263
#define	TVOID	264
#define	TWHILE	265
#define	TFLOAT	266
#define	TCHAR	267
#define	TSTRING	268
#define	TADDASSIGN	269
#define	TSUBASSIGN	270
#define	TMULASSIGN	271
#define	TDIVASSIGN	272
#define	TMODASSIGN	273
#define	TOR	274
#define	TAND	275
#define	TEQUAL	276
#define	TNOTEQU	277
#define	TGREAT	278
#define	TLESS	279
#define	TGREATE	280
#define	TLESSE	281
#define	TINC	282
#define	TDEC	283
#define	TPLUS	284
#define	TMINUS	285
#define	TMULTIPLY	286
#define	TDIVIDE	287
#define	TMOD	288
#define	TNOT	289
#define	TASSIGN	290
#define	TLPAREN	291
#define	TRPAREN	292
#define	TCOMMA	293
#define	TSEMICOLON	294
#define	TLBRACKET	295
#define	TRBRACKET	296
#define	TLBRACE	297
#define	TRBRACE	298
#define	LOWER_THEN_ELSE	299
#define	TELSE	300

#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#include "glob.h"

int type_int = 0;
int type_void = 0;
int type_float = 0;
int type_char = 0;

void line(int);
extern printError();
extern yylex();
extern yyerror(s);

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		191
#define	YYFLAG		-32768
#define	YYNTBASE	46

#define YYTRANSLATE(x) ((unsigned)(x) <= 300 ? yytranslate[x] : 94)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    17,    20,    23,
    26,    30,    33,    35,    37,    40,    42,    44,    46,    48,
    50,    52,    54,    56,    60,    64,    66,    67,    69,    73,
    76,    79,    83,    87,    90,    92,    93,    95,    98,   102,
   106,   108,   112,   114,   118,   122,   126,   128,   133,   138,
   140,   141,   143,   144,   146,   149,   152,   154,   156,   158,
   160,   162,   165,   168,   170,   171,   177,   185,   191,   195,
   197,   200,   203,   206,   209,   212,   216,   220,   222,   226,
   230,   234,   238,   242,   246,   250,   252,   256,   258,   262,
   264,   268,   272,   274,   278,   282,   286,   290,   292,   296,
   300,   302,   306,   310,   314,   316,   319,   322,   325,   328,
   330,   335,   340,   343,   346,   351,   353,   354,   356,   358,
   362,   364,   366
};

static const short yyrhs[] = {    47,
     0,    48,     0,    47,    48,     0,    49,     0,    65,     0,
     3,    39,     0,     3,     1,     0,    50,    61,     0,    50,
    39,     0,    50,     1,     0,    51,    56,    57,     0,    51,
    57,     0,    52,     0,    53,     0,    52,    53,     0,    54,
     0,    55,     0,     5,     0,     7,     0,     9,     0,    11,
     0,    12,     0,     3,     0,    36,    58,    37,     0,    36,
    58,     1,     0,    59,     0,     0,    60,     0,    59,    38,
    60,     0,    59,    60,     0,    51,    68,     0,    42,    62,
    43,     0,    42,    62,     1,     0,    63,    70,     0,    64,
     0,     0,    65,     0,    64,    65,     0,    51,    66,    39,
     0,    51,    66,     1,     0,    67,     0,    66,    38,    67,
     0,    68,     0,    68,    35,     4,     0,    68,    35,    13,
     0,    68,    35,    79,     0,     3,     0,     3,    40,    69,
    41,     0,     3,    40,    69,     1,     0,     4,     0,     0,
    71,     0,     0,    72,     0,    71,    72,     0,    71,    65,
     0,    61,     0,    73,     0,    75,     0,    76,     0,    77,
     0,    74,    39,     0,    78,     1,     0,    78,     0,     0,
     6,    36,    78,    37,    72,     0,     6,    36,    78,    37,
    72,    45,    72,     0,    10,    36,    78,    37,    72,     0,
     8,    74,    39,     0,    81,     0,    29,    80,     0,    30,
    80,     0,    31,    80,     0,    32,    80,     0,    33,    80,
     0,    36,    86,    37,     0,    36,    86,     1,     0,    82,
     0,    88,    35,    81,     0,    88,    14,    81,     0,    88,
    15,    81,     0,    88,    16,    81,     0,    88,    17,    81,
     0,    88,    18,    81,     0,    69,    35,    81,     0,    83,
     0,    82,    19,    83,     0,    84,     0,    83,    20,    84,
     0,    85,     0,    84,    21,    85,     0,    84,    22,    85,
     0,    86,     0,    85,    23,    86,     0,    85,    24,    86,
     0,    85,    25,    86,     0,    85,    26,    86,     0,    87,
     0,    86,    29,    87,     0,    86,    30,    87,     0,    88,
     0,    87,    31,    88,     0,    87,    32,    88,     0,    87,
    33,    88,     0,    89,     0,    30,    88,     0,    34,    88,
     0,    27,    88,     0,    28,    88,     0,    93,     0,    89,
    40,    78,    41,     0,    89,    36,    90,    37,     0,    89,
    27,     0,    89,    28,     0,    89,    40,    78,     1,     0,
    91,     0,     0,    92,     0,    81,     0,    92,    38,    81,
     0,     3,     0,     4,     0,    36,    78,    37,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    30,    32,    33,    35,    36,    37,    38,    44,    45,    46,
    53,    54,    60,    62,    63,    65,    66,    68,    70,    71,
    72,    73,    75,   118,   119,   125,   126,   128,   129,   130,
   136,   138,   139,   145,   147,   148,   150,   151,   153,   161,
   172,   173,   175,   176,   177,   178,   180,   193,   206,   212,
   213,   215,   216,   218,   219,   220,   222,   223,   224,   225,
   226,   228,   229,   235,   236,   238,   239,   241,   243,   245,
   247,   248,   249,   250,   251,   253,   254,   259,   260,   261,
   262,   263,   264,   265,   266,   272,   273,   275,   276,   278,
   279,   280,   282,   283,   284,   285,   286,   288,   289,   290,
   292,   293,   294,   295,   297,   298,   299,   300,   301,   303,
   304,   305,   306,   307,   308,   315,   316,   318,   320,   321,
   323,   328,   329
};

static const char * const yytname[] = {   "$","error","$undefined.","TIDEN",
"TNUMBER","TCONST","TIF","TINT","TRETURN","TVOID","TWHILE","TFLOAT","TCHAR",
"TSTRING","TADDASSIGN","TSUBASSIGN","TMULASSIGN","TDIVASSIGN","TMODASSIGN","TOR",
"TAND","TEQUAL","TNOTEQU","TGREAT","TLESS","TGREATE","TLESSE","TINC","TDEC",
"TPLUS","TMINUS","TMULTIPLY","TDIVIDE","TMOD","TNOT","TASSIGN","TLPAREN","TRPAREN",
"TCOMMA","TSEMICOLON","TLBRACKET","TRBRACKET","TLBRACE","TRBRACE","LOWER_THEN_ELSE",
"TELSE","mini_c","translation_unit","external_dcl","function_def","function_header",
"dcl_spec","dcl_specifiers","dcl_specifier","type_qualifier","type_specifier",
"function_name","formal_param","opt_formal_param","formal_param_list","param_dcl",
"compound_st","compound","opt_dcl_list","declaration_list","declaration","init_dcl_list",
"init_declarator","declarator","opt_number","opt_stat_list","statement_list",
"statement","expression_st","opt_expression","if_st","while_st","return_st",
"expression","function_st","function_expression","assignment_exp","logical_or_exp",
"logical_and_exp","equality_exp","relational_exp","addtive_exp","multiplicative_exp",
"unary_exp","postfix_exp","opt_actual_param","actual_param","actual_param_list",
"primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    46,    47,    47,    48,    48,    48,    48,    49,    49,    49,
    50,    50,    51,    52,    52,    53,    53,    54,    55,    55,
    55,    55,    56,    57,    57,    58,    58,    59,    59,    59,
    60,    61,    61,    62,    63,    63,    64,    64,    65,    65,
    66,    66,    67,    67,    67,    67,    68,    68,    68,    69,
    69,    70,    70,    71,    71,    71,    72,    72,    72,    72,
    72,    73,    73,    74,    74,    75,    75,    76,    77,    78,
    79,    79,    79,    79,    79,    80,    80,    81,    81,    81,
    81,    81,    81,    81,    81,    82,    82,    83,    83,    84,
    84,    84,    85,    85,    85,    85,    85,    86,    86,    86,
    87,    87,    87,    87,    88,    88,    88,    88,    88,    89,
    89,    89,    89,    89,    89,    90,    90,    91,    92,    92,
    93,    93,    93
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     2,     2,     2,
     3,     2,     1,     1,     2,     1,     1,     1,     1,     1,
     1,     1,     1,     3,     3,     1,     0,     1,     3,     2,
     2,     3,     3,     2,     1,     0,     1,     2,     3,     3,
     1,     3,     1,     3,     3,     3,     1,     4,     4,     1,
     0,     1,     0,     1,     2,     2,     1,     1,     1,     1,
     1,     2,     2,     1,     0,     5,     7,     5,     3,     1,
     2,     2,     2,     2,     2,     3,     3,     1,     3,     3,
     3,     3,     3,     3,     3,     1,     3,     1,     3,     1,
     3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
     1,     3,     3,     3,     1,     2,     2,     2,     2,     1,
     4,     4,     2,     2,     4,     1,     0,     1,     1,     3,
     1,     1,     3
};

static const short yydefact[] = {     0,
     0,    18,    19,    20,    21,    22,     1,     2,     4,     0,
     0,    13,    14,    16,    17,     5,     7,     6,     3,    10,
     9,    36,     8,    47,    27,     0,    12,     0,    41,    43,
    15,     0,     0,    53,    35,    37,    51,     0,     0,    26,
    28,    11,    40,     0,    39,     0,    47,    33,    32,   121,
   122,     0,    51,     0,     0,     0,     0,     0,    51,    57,
     0,    34,    52,    54,    58,     0,    59,    60,    61,     0,
    70,    78,    86,    88,    90,    93,    98,   101,   105,   110,
    38,    50,     0,    31,    25,    24,     0,    30,    42,    44,
    45,     0,     0,     0,     0,     0,    46,    51,     0,    64,
    51,   122,   108,   109,   106,   107,     0,    51,    56,    55,
    62,    63,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    51,    51,    51,    51,    51,
    51,   113,   114,    51,    51,    49,    48,    29,     0,    71,
    72,    73,    74,    75,     0,    69,     0,   123,    85,    87,
   101,    89,    91,    92,    94,    95,    96,    97,    99,   100,
   102,   103,   104,    80,    81,    82,    83,    84,    79,   119,
     0,   116,   118,     0,     0,    51,    51,   112,    51,   115,
   111,    77,    76,    66,    68,   120,    51,    67,     0,     0,
     0
};

static const short yydefgoto[] = {   189,
     7,     8,     9,    10,    32,    12,    13,    14,    15,    26,
    27,    39,    40,    41,    60,    33,    34,    35,    16,    28,
    29,    30,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    97,   140,    71,    72,    73,    74,    75,    76,
    77,    78,    79,   171,   172,   173,    80
};

static const short yypact[] = {   198,
    10,-32768,-32768,-32768,-32768,-32768,   198,-32768,-32768,     9,
    42,   238,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   238,-32768,   -21,   238,   -18,-32768,    20,-32768,   -15,
-32768,    30,    11,   101,   238,-32768,    78,    30,    36,    72,
-32768,-32768,-32768,    30,-32768,   204,     6,-32768,-32768,-32768,
    41,    49,   148,    51,   186,   186,   186,   186,   196,-32768,
    71,-32768,    91,-32768,-32768,    69,-32768,-32768,-32768,    35,
-32768,    98,    92,    94,    67,    93,     7,   224,   127,-32768,
-32768,-32768,    15,-32768,-32768,-32768,   238,-32768,-32768,-32768,
-32768,    84,    84,    84,    84,    84,-32768,   196,    95,-32768,
   196,-32768,-32768,-32768,-32768,-32768,   108,   196,-32768,-32768,
-32768,-32768,   186,   186,   186,   186,   186,   186,   186,   186,
   186,   186,   186,   186,   186,   196,   196,   196,   196,   196,
   196,-32768,-32768,   158,   196,-32768,-32768,-32768,   186,-32768,
-32768,-32768,-32768,-32768,   110,-32768,   116,-32768,-32768,    92,
-32768,    94,    67,    67,    93,    93,    93,    93,     7,     7,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   123,-32768,   126,    16,    13,   138,   138,-32768,   196,-32768,
-32768,-32768,-32768,    87,-32768,-32768,   138,-32768,   169,   170,
-32768
};

static const short yypgoto[] = {-32768,
-32768,   164,-32768,-32768,     1,-32768,   161,-32768,-32768,-32768,
   153,-32768,-32768,   -34,   171,-32768,-32768,-32768,    12,-32768,
   139,   155,   154,-32768,-32768,   -63,-32768,   143,-32768,-32768,
-32768,   -46,-32768,    63,   -99,-32768,    85,    83,    23,   -95,
    28,   -53,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		259


static const short yytable[] = {   110,
    11,   103,   104,   105,   106,    88,   100,    11,   149,    20,
    17,    48,   107,   182,   -23,   136,   180,    25,    37,    46,
    43,   155,   156,   157,   158,    38,   164,   165,   166,   167,
   168,   169,    47,    36,   170,   112,    85,   123,   124,   125,
    38,   121,   122,   175,    24,    37,    81,    21,    18,   183,
    22,   145,   138,    49,   147,   137,   181,    44,    45,   151,
   151,   151,   151,   151,   151,   151,   151,   151,   151,   161,
   162,   163,    86,   -64,   109,   -50,     2,    25,     3,   186,
     4,    82,     5,     6,    98,   151,   101,    38,   174,   117,
   118,   119,   120,    50,    51,     2,    52,     3,    53,     4,
    54,     5,     6,    50,    51,   108,    52,   111,    53,    87,
    54,   114,   184,   185,   115,   116,   113,    55,    56,   139,
    57,   121,   122,   188,    58,   -51,    59,    55,    56,   -65,
    57,   187,    22,   146,    58,   -51,    59,   153,   154,   -65,
    50,    51,    22,    52,   148,    53,   176,    54,   159,   160,
    50,    51,   177,   132,   133,   141,   142,   143,   144,   178,
    50,    51,   134,   179,    55,    56,   135,    57,   190,   191,
    19,    58,    31,    59,    55,    56,   -65,    57,    42,    22,
    23,    58,    89,    59,    55,    56,   -65,    57,    50,   102,
    83,    58,    84,    59,  -117,    99,   152,   150,    50,    51,
     1,     0,     2,     0,     3,     0,     4,    90,     5,     6,
     0,     0,    55,    56,     0,    57,    91,     0,     0,    58,
     0,    59,    55,    56,     0,    57,     0,     0,     0,    58,
     0,    59,    92,    93,    94,    95,    96,   126,   127,   128,
   129,   130,     2,     0,     3,     0,     4,     0,     5,     6,
     0,     0,     0,     0,     0,     0,     0,     0,   131
};

static const short yycheck[] = {    63,
     0,    55,    56,    57,    58,    40,    53,     7,   108,     1,
     1,     1,    59,     1,    36,     1,     1,    36,    40,    35,
     1,   117,   118,   119,   120,    25,   126,   127,   128,   129,
   130,   131,     3,    22,   134,     1,     1,    31,    32,    33,
    40,    29,    30,   139,     3,    40,    35,    39,    39,    37,
    42,    98,    87,    43,   101,    41,    41,    38,    39,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,    37,    39,    63,    35,     5,    36,     7,   179,
     9,     4,    11,    12,    36,   139,    36,    87,   135,    23,
    24,    25,    26,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,     3,     4,    35,     6,    39,     8,    38,
    10,    20,   176,   177,    21,    22,    19,    27,    28,    36,
    30,    29,    30,   187,    34,    35,    36,    27,    28,    39,
    30,    45,    42,    39,    34,    35,    36,   115,   116,    39,
     3,     4,    42,     6,    37,     8,    37,    10,   121,   122,
     3,     4,    37,    27,    28,    93,    94,    95,    96,    37,
     3,     4,    36,    38,    27,    28,    40,    30,     0,     0,
     7,    34,    12,    36,    27,    28,    39,    30,    26,    42,
    10,    34,    44,    36,    27,    28,    39,    30,     3,     4,
    37,    34,    38,    36,    37,    53,   114,   113,     3,     4,
     3,    -1,     5,    -1,     7,    -1,     9,     4,    11,    12,
    -1,    -1,    27,    28,    -1,    30,    13,    -1,    -1,    34,
    -1,    36,    27,    28,    -1,    30,    -1,    -1,    -1,    34,
    -1,    36,    29,    30,    31,    32,    33,    14,    15,    16,
    17,    18,     5,    -1,     7,    -1,     9,    -1,    11,    12,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

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
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
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

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
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
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
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
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
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

case 7:
#line 39 "parser.y"
{
			yyerrok;
			printError(wrong_st);
		;
    break;}
case 10:
#line 47 "parser.y"
{
			look_tmp->type = 0; /*type의 default 값은 0*/
			yyerrok;
			printError(wrong_funcdef);
		;
    break;}
case 12:
#line 55 "parser.y"
{
					yyerrok;
					printError(nofuncname);
				;
    break;}
case 19:
#line 70 "parser.y"
{type_int=1;;
    break;}
case 20:
#line 71 "parser.y"
{type_void=1;;
    break;}
case 21:
#line 72 "parser.y"
{type_float=1;;
    break;}
case 22:
#line 73 "parser.y"
{type_char=1;;
    break;}
case 23:
#line 76 "parser.y"
{
			if(look_id->type==0 || look_id->type==5)
			{
				if(type_int == 1)
				{
					look_id->type=4; /*정수를 인자로 반환하는 함수*/
					type_int = 0;
					type_void = 0;
					type_float = 0;
					type_char = 0;
					look_tmp = look_id;
				}
				else if(type_void == 1)
				{
					look_id->type=6; /*반환하는 인자가 없는 함수*/
					type_int = 0;
					type_void = 0;
					type_float = 0;
					type_char = 0;
					look_tmp = look_id;
				}
				else if(type_float == 1)
				{
					look_id->type=7; /*실수를 인자로 반환하는 함수*/
					type_int = 0;
					type_void = 0;
					type_float = 0;
					type_char = 0;
					look_tmp = look_id;
				}
				else if(type_char == 1)
				{
					look_id->type=8; /*문자를 인자로 반환하는 함수*/
					type_int = 0;
					type_void = 0;
					type_float = 0;
					type_char = 0;
					look_tmp = look_id;
				}
			 }
		;
    break;}
case 25:
#line 120 "parser.y"
{
					yyerrok;
					printError(noparen);
				;
    break;}
case 30:
#line 131 "parser.y"
{
			yyerrok;
			printError(nocomma);
		;
    break;}
case 33:
#line 140 "parser.y"
{
			yyerrok;
			printError(nobrace);
		;
    break;}
case 39:
#line 154 "parser.y"
{
			type_int = 0; /*값 다시 초기화*/
			type_void = 0;
			type_float = 0;
			type_float = 0;
			type_char = 0;
		;
    break;}
case 40:
#line 162 "parser.y"
{
			look_tmp->type = 0;
			yyerrok;
			type_int = 0; /*값 다시 초기화*/
			type_void = 0;
			type_float = 0;
			type_char = 0;
			printError(nosemi);
		;
    break;}
case 47:
#line 181 "parser.y"
{
			if(look_id->type==0)
			{
				if(type_int==1) 
					look_id->type=1; /*정수 상수에 대한 변수*/
				else if(type_float==1) 
					look_id->type=2; /*실수 상수에 대한 변수*/
				else if(type_char==1) 
					look_id->type=9; /*문자에 대한 변수*/
			}
			look_tmp = look_id;
		;
    break;}
case 48:
#line 194 "parser.y"
{
			if(look_id->type == 0)
			{
				if(type_int==1)
					look_id->type=3; /*정수 배열에 대한 변수*/
				else if(type_float==1)
					look_id->type=10; /*실수 배열에 대한 변수*/
				else if(type_char==1)
					look_id->type=11; /*문자 배열에 대한 변수*/
				look_tmp = look_id;
			}
		;
    break;}
case 49:
#line 207 "parser.y"
{
			yyerrok;
			printError(nobracket);
		;
    break;}
case 63:
#line 230 "parser.y"
{
			yyerrok;
			printError(nosemi);
		;
    break;}
case 77:
#line 255 "parser.y"
{
						yyerrok;
						printError(noparen);
					;
    break;}
case 85:
#line 267 "parser.y"
{
						yyerrok;
						printError(assignerr);
		;
    break;}
case 115:
#line 309 "parser.y"
{
			yyerrok;
			printError(nobracket);
		;
    break;}
case 121:
#line 324 "parser.y"
{
			if(look_id->type==0)
				look_id->type = 5;
		;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

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
}
#line 331 "parser.y"


void line(int n)
{
	printf("\t %d \t", n);
}