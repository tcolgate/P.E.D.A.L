/*
 *   This header describes the structures used for maintaining the namespace,
 * it is concerned with controling which variables are currently in scope.  
 */
#ifndef __SCOPE_H
#define __SCOPE_H

struct scope *scopestack, *globalscope ;

struct scope {
  struct st_table *first ;
  struct scope *next ;
  int currsfoffset ;
} ;

void InitialiseGlobalScope(void) ;
  
/* This Pushes a new, empty , scope onto the scopestack */
int PushScope () ;

/* This pops the tp[ scp[e pff pf the scp[e stack and frees all symbol tables */
int PopScope () ;

/* This pushes a new symbol table into the current scope */
int PushSymbolTable () ;

/* This pops a symbol table off the stack and frees up all the symbols */
int PopSymbolTable () ;

/*This function adds a symbol in the correct symbol table given current scope */
int AddSymbol (struct symbol *) ;

/* This function is used to find a symbol anywhere in the current scope */
struct symbol *FindSymbol (char*) ;


#endif
