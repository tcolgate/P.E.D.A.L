#ifndef __SYMTAB_H
#define __SYMTAB_H

/* 
 * These structures are influenced by the type model presented in
 * Writing Compilers and Interpreters by [author]
 */


/*
 * Will need a system for dealing with scope, preferably using a list of
 * symbol tables each entry representing a currently valid symbol table (eg one for each codeblock. These lists should be also stored on a stack to facilitate function calls, the current list o valid scopes is popped onto a stack when a function is called.
  */

enum symclass {
	type,
	func,
	instance
} ;

union symclassdata {
      struct fieldnode *fields ;
      struct paramnode *paramlist ;
      int sfoffset ; 
} ;
			

struct symbol {
  char *text ;
  enum symclass class ;
  struct type *type  ;
  union symclassdata data ;
  int arraydimensions[16] ; /*How many array dimensions this symbol has */
  int isglobal; /* Stack frame offset of this variable (assuming instance */
} ;

struct st_node {
  struct symbol *sym ;
  struct st_node *lnode ;
  struct st_node *rnode ;
} ;

struct st_table {
  struct st_node *root ;
  int currsfoffset ; /*Stack Frame offset of any new symbols*/
  struct st_table * next ; /*used for maintaining scopes*/
} ;

/*
 *  These are the function prototypes for the symbo table functions.
 */

/* Create/Desroy a symbol table */
struct st_table *st_CreateTable (int) ;
int st_DestroyTable (struct st_table*) ;

/* Add a symbol to the symbol table */
int st_Insert (struct st_table*, struct symbol*) ;

/* Locate Symbol*/
struct symbol* st_FindSymbol(const struct st_table*, const char*) ;

struct symbol *st_CreateSymbol (char*, enum symclass, struct type* ,union symclassdata) ;

#endif 



