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
# define	STARTLIMITEDSTATEBLOCK	266
# define	ENDLIMITEDSTATEBLOCK	267
# define	IF	268
# define	ELSE	269
# define	FOR	270
# define	WHILE	271
# define	BREAK	272
# define	OBJECT	273
# define	RETURN	274
# define	TIME	275
# define	BASISFUNC	276
# define	COMPARISON	277
# define	UMINUS	278
# define	STRING	279
# define	QSTRING	280
# define	CIRCUMFLEX	281
# define	POW	282
# define	CAST	283


extern YYSTYPE yylval;

#endif /* not BISON_GRAMMAR_H */
