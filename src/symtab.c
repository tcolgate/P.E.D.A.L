#include <stdlib.h>
#include <stdio.h>
#include "include/parsepdl.h"
#include "include/symtab.h"

struct st_table*
st_CreateTable (int sfstart) {
  struct st_table *new ;
  new = NEW(struct st_table) ;
  new->currsfoffset = sfstart ;
  new->root = NULL ;
  return new ;
} ;

int 
st_DestroyTable (struct st_table *table){
  /* Must traverse tree and free all nodes and sub symbol tables */
  return 0 ;
} ;

		   


/* Add a symbol to the symbol table */
int 
st_Insert (struct st_table *table, struct symbol *sym) {
  struct st_node *prev, *curr ;

  /* Set the stack frame offset of this symbol and increse the tables cursf */
  if (sym->class == instance){
    sym->data.sfoffset = table->currsfoffset ;
    table->currsfoffset++ ;
  } ;
  
  if (table->root == NULL) {
    table->root = NEW (struct st_node) ;
    table->root->rnode = NULL ;
    table->root->lnode = NULL ;
    table->root->sym = sym ;
    return 1 ;   
  } else {
    int path = 0 ; 
    prev = curr = table->root ;
    while(curr != NULL){
      if (strcmp(curr->sym->text, sym->text) < 0) {
	prev = curr ;
	path = 0 ;
	curr = prev->lnode ;
      }else{
	prev = curr ;
	path = 1 ;
       	curr = prev->rnode ;
      }
    } ;

    if (path == 0) {
      prev->lnode = NEW (struct st_node) ;
      prev->lnode->lnode = NULL ;
      prev->lnode->rnode = NULL ;
      prev->lnode->sym  = sym ;
      return 1 ;
    } else {
      prev->rnode = NEW(struct st_node) ;
      prev->rnode->lnode = NULL ;
      prev->rnode->rnode = NULL ;
      prev->rnode->sym  = sym ;
      return 1 ;
    }    
    return 0 ;
  }
  return 0 ;
} ;

/* Locate Symbol*/
struct symbol* 
st_FindSymbol (const struct st_table *table, const char *text){
  struct st_node *curr = table->root ;
  
  while ( curr != NULL ) {
    int comp = strcmp(curr->sym->text, text) ;
    if (comp < 0){
      curr = curr->lnode ;
    } else if (comp > 0) {
      curr = curr->rnode ;
    } else {
      return curr->sym ;
    } ;
  } ;

  return NULL ;  
} ;




















