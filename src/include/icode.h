#ifndef __ICODE_H
#define __ICODE_H
/*
 * This is the defeinition of the structures and functions for the
 * intermediate code. It acts as a producer for a stack based code
 * which is later interpreted to produce the RIB code itself.
 */
#include <stdio.h>

/*Macros for decvlaring new ICode instructions cleanly*/
#define DECLARE_INST (name) \
  inst =name ; IStrings[inst] = "name" ; ICodeFuncs[inst] = ICode_name ;

typedef struct commandlist* codeblock ;

/* 
 *  This enum represents the instruction set of the icode, almost all of
 * these instruction operate exclusively on the stack. label works on
 * the icode source itself setting jump pooint. The j instructions are used
 * for moving around the icode. out is used to output actual text (RIB)
 */

enum instruction {
  add,
  sub,
  mul,
  divide,
  jmp,
  jnz,
  jpz,
  inc,
  dec,
  push,
  pop,
  label,
  declare,
  sfstart,
  call,
  ret,
  out,
  ref,
  subref,
  deref,
  assign,
  indx,
  flatten,
  nop,
  isin,
  icos,
  itan,
  pushtime
} ;


struct command {
  int line ; int pos ; /* The line and position of the expression that generated this instruction */
  enum instruction instr;
  char *arg ;/* Not sure about this one yet */
  struct command *next,*previous ;
} ;

struct commandlist {
  struct command *first,*last ;
  int size ;
} ; 

/*All the types of elements that can go on the stack */
enum elementtype {
  value ,	/*Element is an actual value*/
  fieldlist ,	/*Element is a compound object*/
  array,	/*Element is an array*/
  reference,	/*Element is a reference to another element*/
  sfinfo	/*Element is an address in the icod*/
    		/*  (used for return addresses     */
} ;

/*This is data that is pushed onto the stack when a function is called*/
struct sfinfo {
  struct command* retaddress ; /*Address to return to*/
} ;

struct referenceinfo {
  struct stackelement *ref ;/*The element being referenced*/
  struct stackelement *interp ; /*Value arrived at by interpolation
				 (if different)*/
} ;

/* This is the data required for an element on the stack */
union elementdata {
  double value ;
  struct sfinfo sfinfo ;
  struct referenceinfo reference ;
  struct stackelement* arrayelements ;
  struct stackelement* fields ;
} ;

/* This is an actual stack element */
struct stackelement {
  enum elementtype etype ;
  double index ; /*Used by array elements and compound objects*/
  union elementdata edata ;
  struct type* type ; /*This is strange, we have run time type info, it
			 required for some opcode, but this offsers
			 even more poweful arrays (dynamic typing)
			 which we dp pt use.*/
  struct stackelement *next,*previous,*parent; /*Although this is a stack, we
					   may need to traverse ub both 
					   directions,parent is required
					   to avoid a problem with assign*/
} ;

struct machinestate {
  double time ;
  struct label *labels ;
  FILE *ribfile ;
  struct command *IP ; /* Instruction Pointer */
  struct stackelement *SB ; /* Stack Base  */
  struct stackelement *SP ; /* Stack Head  */
  struct stackelement *SF ; /* Stack Frame */ 
} ;

struct label {
   struct command *start ;
   char *name ;
   struct label *next ;
};


#define NO_OF_INSTRUCTIONS 32 /*Number of different instrction*/

char *IStrings [NO_OF_INSTRUCTIONS] ;/*Translation table for the instrucions*/
void (*ICodeFuncs[NO_OF_INSTRUCTIONS])(struct machinestate* );
codeblock outputcode ;

void  SetupICode(void) ;
void  fdumpcodeblock(FILE* , codeblock) ;
void RunICode (FILE*) ;

codeblock ic_Append (codeblock, enum instruction, char* arg) ;
codeblock ic_Join (codeblock, codeblock) ;
codeblock ic_Replicate(codeblock) ;

void Preamble (void) ;
void PostAmble (void) ;
void PushItem (struct machinestate*, struct stackelement*) ;
struct stackelement *PopItem(struct machinestate*) ;

struct stackelement* CreateStackElement(struct type*,int*,struct stackelement*);
struct stackelement* CopyStackElement(struct stackelement*,int);
void FreeStackElement(struct stackelement*) ;

/* These are all the routines to handle the icode instructions */
void ICode_add (struct machinestate* ) ;
void ICode_sub (struct machinestate* ) ;
void ICode_mul (struct machinestate* ) ;
void ICode_divide (struct machinestate* ) ;
void ICode_jmp (struct machinestate* ) ;
void ICode_jmp (struct machinestate* ) ;  
void ICode_jnz (struct machinestate* ) ;    
void ICode_jpz (struct machinestate* ) ;    
void ICode_inc (struct machinestate* ) ;    
void ICode_dec (struct machinestate* ) ;  
void ICode_push (struct machinestate* ) ;  
void ICode_pop (struct machinestate* ) ;  
void ICode_label (struct machinestate* ) ;  
void ICode_declare (struct machinestate* ) ;
void ICode_call (struct machinestate* ) ;  
void ICode_sfstart (struct machinestate* ) ;
void ICode_ret (struct machinestate* ) ;  
void ICode_out (struct machinestate* ) ;  
void ICode_ref (struct machinestate* ) ;  
void ICode_subref (struct machinestate* ) ;  
void ICode_deref (struct machinestate* ) ;  
void ICode_assign (struct machinestate* ) ;  
void ICode_indx (struct machinestate* ) ;  
void ICode_flatten (struct machinestate* ) ;  
void ICode_nop (struct machinestate* ) ;  
void ICode_sin (struct machinestate* ) ;
void ICode_cos (struct machinestate* ) ;
void ICode_tan (struct machinestate* ) ;
void ICode_pushtime (struct machinestate* ) ;

#endif
