/*
 *   This header describes the structures used for maintaining the namespace,
 * it is concerned with controling which variables are currently in scope.  
 */
#include "include/parsepdl.h"
#include "include/symtab.h"
#include "include/types.h" 
#include "include/scope.h"

#include <stdlib.h>

/* This Pushes a new, empty , scope onto the scopestack */
int PushScope () {
  struct scope *newscope ;
  
  newscope = NEW (struct scope) ;
  newscope->next = scopestack ;
  newscope->first = NULL ;
  scopestack = newscope ;
  
  return 1 ;
};

/* This pops the tp[ scp[e pff pf the scp[e stack and frees all symbol tables */
int PopScope () {
  struct scope *old ;
  
  old = scopestack ;
  scopestack = scopestack->next ;
  /*  Free up symbol tables from the old scope */
  return 1 ;
};

/* This pushes a new symbol table into the current scope */
int PushSymbolTable () {
  struct st_table *newtable ;
  newtable = NEW(struct st_table) ;
  newtable->root = NULL ;
  newtable->next = scopestack->first ;
  newtable->currsfoffset = 0 ;
  if(scopestack->first != NULL){
    newtable->currsfoffset = scopestack->first->currsfoffset ;
  } ;
  scopestack->first = newtable ;
  
  return 1 ;
};

/* This pops a symbol table off the stack and frees up all the symbols */
int PopSymbolTable () {
  struct st_table *old ;
  old = scopestack->first ;
  scopestack->first = scopestack->first->next ;
	  
  return 1 ;
};

/*This function adds a symbol in the correct symbol table given current scope */
int AddSymbol (struct symbol *newsym) {
  if(newsym->class!=type){
    newsym->isglobal = 0  ;
    if(globalscope == scopestack) {
      newsym->isglobal = 1 ;
    } ;
    st_Insert (scopestack->first , newsym ) ;
    return 1 ;
  } else {
    /* All types are global */
    st_Insert (globalscope->first , newsym ) ;
    return 1 ;
  } ;
};

/* This function is used to find a symbol anywhere in the current scope */
struct symbol *FindSymbol (char *symtext) {
  struct st_table *curr ;
  struct symbol *result ;
  
  curr = scopestack->first ;
  while (curr != NULL){
    result = st_FindSymbol (curr , symtext) ;
    if(result != NULL) {
      return result ; 
    }else {
      curr = curr->next ;
    } ;
  } ;
  
  /* If we havent already  checked the global scope, check it now */
  if (scopestack != globalscope) {
    curr = globalscope->first ;
    while (curr != NULL ){
      result = st_FindSymbol (curr , symtext) ;
      if(result != NULL) {
        return result ;
      }else {
        curr = curr->next ;
      } ;
    } ;
  } ;
    
  return NULL ;
} ;

void 
InitialiseGlobalScope(void) {
  scopestack = NULL ;
  
  /* These add a scope to deal with global variable and types */
  PushScope () ;
  globalscope = scopestack ;
  PushSymbolTable() ; 
  
  InitialiseTypes() ;
  
};

