#ifndef BISON_GRAMMAR_H
# define BISON_GRAMMAR_H

# ifndef YYSTYPE
#  define YYSTYPE int
#  define YYSTYPE_IS_TRIVIAL 1
# endif
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


extern YYSTYPE yylval;

#endif /* not BISON_GRAMMAR_H */
