%option noyywrap

%{
/*
 *  This is the lexer for pedal.
 */

#include <string.h>

#include "include/parsepdl.h"
#include "include/symtab.h"
#include "include/types.h"
#include "include/icode.h"
#include "include/nodestructures.h"
#include "include/scope.h"

#include "grammar.h"
extern struct type* lvaluetype ;

int lineno = 1 ;
char linebuf[512] ;
int position ;
int errorcount ;

char *getstringcopy1 (char* ) ;
int yyerror (char*) ;

%}


ws		[\t ]+ 				
number		(([0-9]+)|([0-9]*\.[0-9]+))	
string 		[a-zA-Z_]+[a-zA-Z0-9_]*
qstring		'[^'\n]*'
comment		#.*				
circumflex	\.\.\.

%%

{ws}		{position += yyleng ;}

\n.*		{
		  /* These variables are used to report errors */
		  lineno++ ;
		  strcpy(linebuf,yytext+1) ;
		  position = 0 ;
		  yyless(1) ;
		}

{comment}	{position += yyleng ;}

import		{position += yyleng ; return IMPORT ;}

if		{position += yyleng ; return IF ;} 
else		{position += yyleng ; return ELSE ;} 
for 		{position += yyleng ; return FOR ;} 
while		{position += yyleng ; return WHILE ;} 
break		{position += yyleng ; return BREAK ;} 
object		{position += yyleng ; return OBJECT ;} 
return		{position += yyleng ; return RETURN ;}
T		{position += yyleng ; return TIME ;}		

"=="	|
"<="	|	
">="		{position += yyleng ; return COMPARISON ; }

"%{"            {position += yyleng ; return STARTSTATEBLOCK ; }
"}%"            {position += yyleng ; return ENDSTATEBLOCK ; }

[\{]                    {position += 1 ;PushSymbolTable() ; return yytext[0] ; }
[\}]                    {position += 1 ;PopSymbolTable() ; return yytext[0] ; }

[-=+*/(),.;\[\]><]        {position += yyleng ; return yytext[0] ;} 

{number}        { 
		  position += yyleng ;
		  /*yylval.text = getstringcopy1(yytext) ; */
		  return NUMBER ;
		}
		

{string}	{
                    return STRING ;
                }
		

{qstring}	{
		  int c = input() ;
		  unput(c) ;
		  if (c != '\"') {
                    return QSTRING ;
		  } else {
		    yymore () ;
		  } ;
		  position += yyleng ;
		}
		
{circumflex}	{ 
		  return CIRCUMFLEX ;
		}
%%

int
yyerror (char* err){
        fprintf (stderr, "\nERROR:line %d: %s\n %s\n", lineno,err,linebuf ) ;
	fprintf (stderr, "%*s\n",position+1,"^") ;
	errorcount++ ;
        return 0 ;
} ;

char*
getstringcopy1 (char* string){
  char* copy ;
  copy = calloc (strlen(string) + 1,sizeof(char));
  strcpy(copy,string) ;
  return copy ;
};

