/* Functions for hadnling both internal and userdefineed types */
#include <stdlib.h>
#include <string.h>

#include "include/parsepdl.h"
#include "include/symtab.h"
#include "include/icode.h"
#include "include/scope.h"
#include "include/types.h"

struct type* CreateType ( char* text, struct fieldnode *fields) {
  /* Should register the symbol text in target as a type with typespec 
     data */
  struct type *newtype ;
  struct symbol *newsym ;
  
} ;

void InitialiseTypes (void) {
  struct fieldnode *fields ;
  int arraydims[16] ;
  arraydims[0] = 0 ;
  
} ;

/* This routine is really only used when constructing the builtin types,
   since it is fairly trivial to do it inline in the parser */

struct fieldnode *
AppendField (
    struct fieldnode* fields, 
    int fieldno, 
    char* text, 
    struct type* type,
    int *arraydims
) {
  
} ;

int 
AdjustTypes() {
} ;
