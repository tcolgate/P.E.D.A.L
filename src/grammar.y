%{
/* 
 *  This is the grammar for PEDAL. 
 */
%}

%token TYPE VAR FUNCNAME NUMBER MEMBER MEMBERFUNC
%token IMPORT STARTSTATEBLOCK ENDSTATEBLOCK
%token IF ELSE FOR WHILE BREAK OBJECT RETURN TIME 
%token SPLINETYPE COMPARISON UMINUS
%token STRING QSTRING 

/*types*/

/* Precedences */
%left '='
%left '-' '+'
%left '*' '/' '^' '.'
%left POW
%nonassoc CAST
%left ':'
%nonassoc UMINUS

%%

program:	  
	  statement_list
	;

statement_list:	  
	  statement_list ';' statement
	| statement 
	;

statement:	  
	  control_statement
	| function_declaration
	| object_declaration
	;

object_declaration:
	 OBJECT STRING '{' field_list '}' 
	;

function_declaration:
	  TYPE arrayspec STRING param_list block_statement 
	| TYPE STRING param_list block_statement 
	;

control_statement:  
	  import
	| if_statement
        | for_statement
        | while_statement
        | block_statement
	| expression          
	| '<' expression '>'  
	| RETURN expression 
	| variable_declaration	
	| /* empty */ 
	| error
	;

block_statement:
          STARTSTATEBLOCK control_statement_list ENDSTATEBLOCK
        | '{' control_statement_list '}'
	;

control_statement_list:
          control_statement_list ';' control_statement
        | control_statement
	;

import: 	  
	  IMPORT QSTRING 
	;

variable_declaration:	  
	  TYPE arrayspec STRING initspec 
	| TYPE STRING initspec
	;

arrayspec: 
	  arrayspec '[' NUMBER splinespec ']'
	| '[' NUMBER splinespec ']'
	;

splinespec:
	;

initspec:
	  '=' expression 
	| /* empty */    
	;


param_list:	  
	  param_list ',' param
	| param
	| /* empty */
	;

param:	
	  TYPE arrayspec STRING default_spec
	| TYPE STRING default_spec
	;

default_spec:	  
	  '=' expression
	| /* empty */
	;		

field_list:	
	  field_list field
	| field
	;

field:       	  
	  TYPE arrayspec STRING  ';'
	| TYPE STRING ';'
	| TYPE STRING '(' param_list ')' '{' control_statement_list '}'
	;
 
if_statement:	  
	  IF '(' condition ')' block_statement 
	| IF '(' condition ')' block_statement ELSE block_statement 
	;
		
for_statement:	  
	  FOR '(' expression ';' condition ';' expression ')' block_statement 
	;

while_statement:  
	  WHILE '(' condition ')' block_statement 
	;

condition:	  
	  expression 
	| expression COMPARISON expression 
	| expression '<' expression 
	| expression '>' expression 
	| '!' expression 
	;

lvalue:		  
	  lvalue '[' expression ']' 
        | lvalue ':' MEMBER 
	| MEMBER /*For encapsulated functions*/
        | VAR
	;

expression:	  
	  lvalue
	| lvalue '=' expression
	| '-' expression %prec UMINUS
	| '+' expression %prec UMINUS
	| expression '+' expression 
	| expression '-' expression
	| expression '*' expression
	| expression '/' expression
	| expression POW expression
	| expression '.' expression /*Dot product*/
	| expression '^' expression /*Cross product*/
	| '(' expression ')' 
	| '[' explist ']' 
	| FUNCNAME '(' explist ')' 
	| lvalue ':' MEMBERFUNC '(' explist ')' 
	| MEMBERFUNC '(' explist ')' /* For encapsulated funtions */
	| '(' TYPE ')' expression %prec CAST
	| NUMBER 
	| TIME
	| QSTRING /*Mainlt here just to allow filename passing*/
	| STRING /* Catching erroes */
	;

explist: 	  
	  explist ',' exp 
	| exp 
        ;

exp:		  
	  expression 
	| /* empty */
	;

%%
