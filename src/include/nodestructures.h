#ifndef __NODESTRUCTURES_H
#define __NODESTRUCTURES_H
#include "icode.h"
#include "types.h"

/* 
   This file is used to define all the different types of structures 
   needed by the grammar for the various grammatical constructs..
   e.g. code blocks, and variable specs.
   */

struct expnode {
  enum symclass currclass ;
  struct type *currtype ;
  int *currarraydims ; /* Current array dimensions */
  union symclassdata currdata ;
  codeblock code ; /*Points to the code that evaluates this expression */
} ;

struct explistnode {
  struct expnode exp ;
  struct explistnode *next ;
} ;

struct initspecnode {
  struct expnode initexp ;
} ;

struct paramnode {
  struct expnode defaultexp ;
  char *text ;
  struct type *type ;
  int *arraydimensions ;
  struct paramnode *next ;
} ;

/* This structure is almost identical to paramnode */
struct fieldnode {
  int fieldno ; /*Which field is this*/
  char *text ;
  struct type *type ;
  int *arraydimensions ;
  struct fieldnode *next ;
} ;

struct funcspecnode {
    char *text ;
    struct paramnode *paramlist ;
} ;

struct varspecnode {
  char* text ; /*text for this variable*/
  enum symclass varclass ; /*The class of this variable */
  int *arraydimensions ;
  struct expnode initexp; /* expression for initialising this var */
  char* splinetype ; /*Spline type if this is an array */
  struct paramnode *paramlist ; /*Poiter to parameters*/
  codeblock funccode ;
} ;

struct arrayspecnode {
  int *arraydimensions ; 
  char *splinetype ;
} ;

#endif

