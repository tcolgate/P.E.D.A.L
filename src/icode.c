/*
 This file provides the definition of the intermediate code, and the
 mechanism to process that code
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "include/parsepdl.h"
#include "include/icode.h"
#include "include/symtab.h"
#include "include/types.h"
#include "include/scope.h"

/*
extern float starttime ;
extern float endtime ;
extern float timedelta ;
extern int quiet ; /*Shoudl we output progress dots??*/

codeblock 
ic_Append (codeblock code , enum instruction instr, char* arg) {

  struct command *new ;
  new = NEW(struct command) ;
  new->instr = instr ;
  new->arg = arg ;
  new->next = NULL ; 
  
  if(code != NULL){
    code->last->next = new ;
    new->previous = code->last ;
    code->last = new ;
    code->size += 1 ;
    return code ;
  } else {
    codeblock newblock  ;
    newblock = NEW (struct commandlist) ;
    newblock->size = 1 ;
    newblock->first = new ;
    newblock->last = new ;
    new->previous = NULL ;
    return newblock ;
  } ;  
} ;

codeblock 
ic_Join (codeblock c1, codeblock c2) {
  if ((c1 == NULL) && (c2 == NULL)){
    return NULL ;
  } else if (c2 == NULL) {
    return c1 ;    
  } else if (c1 == NULL) {
    return c2 ;
  } else { ;
    c1->size += c2->size ;
    c1->last->next = c2->first ;
    c2->first->previous = c1->last ;
    c1->last = c2->last ;
    free(c2) ;
    return c1 ;
  } ;
};


codeblock 
ic_Replicate(codeblock code) {
  struct command *curr = NULL;
  struct command *new = NULL;
  struct command *prevnew = NULL;
  
  codeblock result = NEW (struct commandlist) ;
  result->size = code->size ;
  curr = code->first ;
  result->first = result->last = NULL ; 
  
  while (curr != NULL) {
    new = NEW(struct command) ;
    new->instr = curr->instr ;
    new->arg = curr->arg ;
    new->next = NULL ;
    if(prevnew != NULL){
      prevnew->next = new ;
    }else{
      result->first = new ;
    } ;
    result->last = new ;
    curr = curr->next ;
    prevnew = new ;  
  } ;
   
  return result ;
} ;

void
SetupICode(void){

  enum instruction inst ;
  
  inst =add ; IStrings[inst] = "add" ; ICodeFuncs[inst] = ICode_add ;
  inst =sub  ; IStrings[inst] = "sub" ; ICodeFuncs[inst] = ICode_sub ;
  inst =mul  ; IStrings[inst] = "mul" ; ICodeFuncs[inst] = ICode_mul ;
  inst =divide  ; IStrings[inst] = "divide" ; ICodeFuncs[inst] = ICode_divide ;
  inst =jmp  ; IStrings[inst] = "jmp" ; ICodeFuncs[inst] = ICode_jmp ;
  inst =jnz  ; IStrings[inst] = "jnz" ; ICodeFuncs[inst] = ICode_jnz ;
  inst =jpz  ; IStrings[inst] = "jpz" ; ICodeFuncs[inst] = ICode_jpz ;
  inst =inc  ; IStrings[inst] = "inc" ; ICodeFuncs[inst] = ICode_inc ;
  inst =dec  ; IStrings[inst] = "dec" ; ICodeFuncs[inst] = ICode_dec ;
  inst =push  ; IStrings[inst] = "push" ; ICodeFuncs[inst] = ICode_push ;
  inst =pop  ; IStrings[inst] = "pop" ; ICodeFuncs[inst] = ICode_pop ;
  inst =label  ; IStrings[inst] = "label" ; ICodeFuncs[inst] = ICode_label ;
  inst =declare ; IStrings[inst] = "declare" ; ICodeFuncs[inst] = ICode_declare;
  inst =call  ; IStrings[inst] = "call" ; ICodeFuncs[inst] = ICode_call ;
  inst =sfstart  ; IStrings[inst] = "sfstart"; ICodeFuncs[inst] = ICode_sfstart;
  inst =ret  ; IStrings[inst] = "ret" ; ICodeFuncs[inst] = ICode_ret ;
  inst =out  ; IStrings[inst] = "out" ; ICodeFuncs[inst] = ICode_out ;
  inst =ref  ; IStrings[inst] = "ref" ; ICodeFuncs[inst] = ICode_ref ;
  inst =subref ; IStrings[inst] = "subref" ; ICodeFuncs[inst] = ICode_subref ;
  inst =deref  ; IStrings[inst] = "deref" ; ICodeFuncs[inst] = ICode_deref ;
  inst =assign  ; IStrings[inst] = "assign" ; ICodeFuncs[inst] = ICode_assign ;
  inst =indx  ; IStrings[inst] = "indx" ; ICodeFuncs[inst] = ICode_indx ;
  inst =flatten  ; IStrings[inst] = "flatten";ICodeFuncs[inst] = ICode_flatten ;
  inst =nop  ; IStrings[inst] = "#" ; ICodeFuncs[inst] = ICode_nop ;
  inst =isin  ; IStrings[inst] = "sin" ; ICodeFuncs[inst] = ICode_sin ;
  inst =icos  ; IStrings[inst] = "cos" ; ICodeFuncs[inst] = ICode_cos ;
  inst =itan  ; IStrings[inst] = "tan" ; ICodeFuncs[inst] = ICode_tan ;
  inst =pushtime; IStrings[inst] ="pushtime"; ICodeFuncs[inst] = ICode_pushtime;
} ;

void
fdumpcodeblock(FILE* stream, codeblock code){
  
  struct command* curr ;
  
  if(code != NULL){
    curr = code->first ;
  
    while (curr != NULL){
      fprintf (stream, "%s %s \n", IStrings[curr->instr], curr->arg) ;
      curr = curr->next ;
    } ;
  } ; 
} ;

void 
PushItem (struct machinestate* state, struct stackelement* newitem) {
  newitem->parent = NULL ; /*Anything going straight onto the stack has no
			     parent*/
  if(state->SP!= NULL){
    newitem->next = NULL ;
    newitem->previous = state->SP ;
    state->SP->next = newitem ;
    state->SP = newitem ;
  }else{
    newitem->previous = NULL ;
    newitem->next = NULL ;
    state->SP = newitem ;
    state->SB = newitem ;
  } ;
} ;

struct stackelement *
PopItem(struct machinestate* state){
  struct stackelement *result = NULL;
  if(state->SP == NULL){
    fprintf (stderr,"Error: Stack Underflow\n") ;
  } else {
    result = state->SP ;
    /*XXX Need to free some stuff up here*/
    state->SP = state->SP->previous ;
    if(state->SP != NULL){
      state->SP->next = NULL ;
    } else {
      state->SB = NULL ;
    } ;
    
  } ;
  result->next = NULL ;
  result->previous = NULL ; 
  return result ;
} ;

void 
ICode_add (struct machinestate* state) {
  struct stackelement *arg1,*arg2 ;
  arg1 = PopItem(state) ;
  arg2 = PopItem(state) ;
  arg1->edata.value = arg1->edata.value + arg2->edata.value ;
  PushItem(state,arg1) ;

  state->IP = state->IP->next ;  return ;
} ;

void 
ICode_sub (struct machinestate* state) {
  struct stackelement *arg1,*arg2 ;
  arg1 = PopItem(state) ;
  arg2 = PopItem(state) ;
  arg1->edata.value = arg2->edata.value - arg1->edata.value ;
  PushItem(state,arg1) ;

  state->IP = state->IP->next ;  return ;
} ;

void 
ICode_mul (struct machinestate* state) {
  struct stackelement *arg1,*arg2 ;
  arg1 = PopItem(state) ;
  arg2 = PopItem(state) ;
  arg1->edata.value = arg2->edata.value * arg1->edata.value ;
  PushItem(state,arg1) ;

  state->IP = state->IP->next ;  return ;
} ;

void 
ICode_divide (struct machinestate* state) {
  struct stackelement *arg1,*arg2 ;
  arg1 = PopItem(state) ;
  arg2 = PopItem(state) ;
  arg1->edata.value = arg2->edata.value / arg1->edata.value ;
  PushItem(state,arg1) ;

  state->IP = state->IP->next ;  return ;
} ;

void
ICode_jmp (struct machinestate* state) { 
  long displacement = strtol(state->IP->arg,NULL,0) ;
  if(displacement >0 ){ /* A forward jump */
    while (displacement >= 0){
      state->IP = state->IP->next ;
      displacement -- ;
    } ;
  } else {
    while (displacement < -1){
      state->IP = state->IP->previous ;
      displacement ++ ;
    } ;
  } ;
} ;

void
ICode_jnz (struct machinestate* state) {   
  long displacement = strtol(state->IP->arg,NULL,0) ;
  struct stackelement *condition = PopItem(state) ;
  
  if(!(condition->edata.value==0)){
    if(displacement >0 ){ /* A forward jump */
      while (displacement >= 0){
        state->IP = state->IP->next ;
        displacement -- ;
      } ;
    } else {
      while (displacement <-1){
        state->IP = state->IP->previous ;
        displacement ++ ;
      } ;
    } ;
  } else {
    state->IP = state->IP->next ;
  } ;
} ;

void
ICode_jpz (struct machinestate* state) {   
  long displacement = strtol(state->IP->arg,NULL,0) ;
  struct stackelement *condition = PopItem(state) ;
  
  if(condition->edata.value==0){
    if(displacement >0 ){ /* A forward jump */
      while (displacement >= 0){
        state->IP = state->IP->next ;
        displacement -- ;
      } ;
    } else {
      while (displacement < -1){
        state->IP = state->IP->previous ;
        displacement ++ ;
      } ;
    } ;
  } else {
    state->IP = state->IP->next ;
  } ;
} ;

void
ICode_inc (struct machinestate* state) {   
  state->IP = state->IP->next ;  return ;
} ;

void
ICode_dec (struct machinestate* state) { 
  state->IP = state->IP->next ;  return ;
} ;

void
ICode_push (struct machinestate* state) { 
  struct stackelement *new ;
  if(isalpha(state->IP->arg[0])){
    int junkdims[16] ;
    junkdims[0] = 0 ;
    /* We are being asked to push a compound type */
    new = CreateStackElement(FindSymbol(state->IP->arg)->type,junkdims,NULL) ;
  } else {
    /* We are being asked to push a literla value */
    new = NEW(struct stackelement);
    new->etype = value ;
    new->type = val ;
    new->index = 0 ;
    new->edata.value = strtod(state->IP->arg,NULL) ;
  } ;
  PushItem(state,new) ;
  state->IP = state->IP->next ;  return ;
} ;

void
ICode_pop (struct machinestate* state) { 
  PopItem(state) ; /*Just junk last value on stack*/
  state->IP = state->IP->next ;  return ;
} ;

void
ICode_label (struct machinestate* state) { 
  /* These are dealt with prior to us seeing them */
  state->IP = state->IP->next ;  return ;
} ;

void
ICode_declare (struct machinestate* state) {
    /*This should really declare a new type at 'runtime'*/
    state->IP = state->IP->next ;  return ;
} ;

void
ICode_call (struct machinestate* state) {
  /*Go back and set the return address for this call in the nearest
    (therefore correct, I hope) sfinfo element on the stack*/
  struct stackelement *curr = state->SP;
  while ((curr != NULL) && (curr->etype!=sfinfo))curr=curr->previous ;
  if(curr!=NULL){
    struct label* currlabel = state->labels;
    curr->edata.sfinfo.retaddress = state->IP->next ;
    /*Find the address of the requested function*/
    while(strcmp(currlabel->name,state->IP->arg)){
	currlabel = currlabel->next ; 
    } ;
    /*Jump to the code for this function*/
    state->IP = currlabel->start ;
    fprintf(state->ribfile,"TransformBegin\n") ;
  } else {
    printf("You have found a bug\n") ;
    printf("The 'runtime' stack has no stackframe info prior to a\n");
    printf("function call. Please read the BUGS file .\n") ;
  } ;
} ;

void
ICode_sfstart (struct machinestate* state) {
  struct stackelement *new = NEW(struct stackelement);
  new->etype = sfinfo ;
  PushItem(state,new) ;
  state->IP = state->IP->next ;  return ;
} ;

void
ICode_ret (struct machinestate* state) { 
  struct stackelement* curr = state->SP;

  /*Go back and find the start of the current stack frame*/
  while ((curr != NULL) && (curr->etype!=sfinfo))curr=curr->previous ;
  if(curr!=NULL){
    /*XXX Need to free stack elements properly*/
    curr->etype = state->SP->etype ;
    state->IP = curr->edata.sfinfo.retaddress ;
    curr->edata = state->SP->edata ;
    curr->type = state->SP->type ;
    /*FREE(curr->next)*/
    curr->next = NULL ;
    state->SP = curr ;
    fprintf(state->ribfile,"TransformEnd\n") ;
  } else {
    printf("You have found a bug\n") ;
    printf("The 'runtime' stack has no stackframe info after a\n");
    printf("function call. Please read the BUGS file .\n") ;
  } ;
} ;

void
ICode_out (struct machinestate* state) { 
  struct stackelement *object = PopItem(state) ;
  char outputline[256] ;
  char numeral[10] ;
  
  if(object->type == val){
   
  } else if (object->type == point){
   
  } else if ((object->type == sphere) ||\
      	     (object->type == cone) ||\
	     (object->type == disk) ||\
	     (object->type == cylinder) ||\
	     (object->type == parabaloid) ||\
	     (object->type == torus)){
    struct stackelement *currfield = object->edata.fields;

    sprintf(outputline,"%s ",object->type->symbol->text) ;
    while(currfield != NULL){
      sprintf(numeral,"%f ",currfield->edata.value) ;
      strcat(outputline,numeral) ;
      currfield = currfield->next ;
    } ;
    strcat(outputline,"\n") ;
    fprintf(state->ribfile,outputline) ;
  } else {
    fprintf(state->ribfile,"Outputting compound tupes is not yet supported\n") ;
  } ; 
		
  state->IP = state->IP->next ;  return ;
} ;

void
ICode_ref (struct machinestate* state) { 
  struct stackelement *new = NEW(struct stackelement) ;
  struct stackelement *curr = state->SP ;
  int offset = strtol(&(state->IP->arg[2]),NULL,0) ;
  new->etype = reference ;
  new->previous= NULL ;
  new->next = NULL ;

  /*Start indexing from the correct point depending on the scope of this var*/  
  switch(state->IP->arg[0]){
    case 'g':
      curr = state->SB ;
      break ;
    case 'l': 
      curr = state->SP ;
      while ((curr != NULL) && (curr->etype!=sfinfo)){
	curr=curr->previous ; 
      } ;	
      curr = curr->next ;  
      break ;
  } ;
  
  /*Set curr to the element at the specified offset*/
  while(offset >0){
    curr = curr->next ;
    offset-- ;
  } ;
  new->edata.reference.ref = curr;
  new->edata.reference.interp = NULL;
  PushItem(state, new) ;
  state->IP = state->IP->next ;  return ;
} ;

void
ICode_subref (struct machinestate* state) { 
  struct stackelement *newref ;
  struct stackelement *currref = state->SP->edata.reference.ref ;
  int fieldno = strtol(state->IP->arg,NULL,0) ;
  /*Start at the first field of the referenced item*/
  newref = currref->edata.fields ;
  while(fieldno >0) {
    newref = newref->next ;
    fieldno-- ;
  } ;
  state->SP->edata.reference.ref = newref ;
  state->SP->edata.reference.interp = NULL ;
  state->IP = state->IP->next ;  return ;
} ;

void
ICode_deref (struct machinestate* state) { 
  /* Get the reference, it should be the next item on the stack */
  struct stackelement *reference = PopItem(state) ;
  struct stackelement *original = reference->edata.reference.ref ;
  struct stackelement *copy ;
  if(reference->edata.reference.interp!=NULL){
    copy = reference->edata.reference.interp;
  } else {
    copy = CopyStackElement(original,0);
  } ;
  FreeStackElement(reference) ;
  PushItem(state,copy) ;
  state->IP = state->IP->next ;  return ;
} ;

void
ICode_assign (struct machinestate* state) { 
  struct stackelement *data = PopItem(state) ;
  struct stackelement *copy = CopyStackElement(data,0) ;
  struct stackelement *referenced = PopItem(state)->edata.reference.ref ;
  copy->previous = referenced->previous ;
  copy->next = referenced->next ;
  copy->parent = referenced->parent ;
  /*Knit the new copy into place*/
  if(copy->previous != NULL){
    copy->previous->next = copy ;
  } else {
    if(copy->parent==NULL){
      /*The item we are replacing is the stack base*/
      state->SB = copy ;
    } else {
      if(copy->parent->etype==fieldlist){
        copy->parent->edata.fields = copy ;
      } else if (copy->parent->etype==array){
	copy->parent->edata.arrayelements = copy ;
      } ;
    } ;
  } ;

  if(copy->next != NULL){
    copy->next->previous = copy ;
  } else {
    if(copy->parent==NULL){
      /*The item we are replacing is the stack base*/
      state->SP = copy ;
    } ;
  } ;
  
  /*Freeup the old element*/
  referenced->next = NULL ; /*Ensure we dont wipe out the whole stack*/
  FreeStackElement(referenced) ;
  /*Put the data back on the stack for subsequent assigns*/
  PushItem(state,data) ;
  state->IP = state->IP->next ;  return ;
} ;

void
ICode_indx (struct machinestate* state) { 
  struct stackelement *array ,*ref;
  double index = PopItem(state)->edata.value;
  int roundedindex = index;
  int i = 0 ;
  
  ref = PopItem(state) ;
  array = ref->edata.reference.ref ;
  
  if(array->type == val){
    /* We may be able to perform an interpolation here */
    ref->edata.reference.interp = NULL ;
  } else if (array->type == point) {
    /*May be able to perform some kind of spline/patch thing*/
    ref->edata.reference.interp = NULL ;
  } else {
    /* This is just a regular array. no iterps can be done */
    ref->edata.reference.interp = NULL ;
  } ;
  array = array->edata.arrayelements ;
  while ((array->next!=NULL) && (roundedindex != i)){
    i++ ;
    array = array->next ;
  } ;
  /*adjust the old reference to point to the new object, then put it back*/
  ref->edata.reference.ref = array ;
  PushItem(state,ref) ;
  state->IP = state->IP->next ;  return ;
} ;

void
ICode_flatten (struct machinestate* state) { 
  long range = strtol(state->IP->arg,NULL,0) ;
  struct stackelement *new = NEW(struct stackelement) ;
  struct stackelement *prev ;
  int index ;
  
  new->etype = array ; 
  new->edata.arrayelements = PopItem(state) ;
  new->type = new->edata.arrayelements->type ;
  new->parent = NULL ;
  
  prev = new->edata.arrayelements ;
  index = prev->index = 0  ;
  prev->parent = new ;
  prev->previous = NULL ;
  prev->next = NULL ;
  range-- ; /*The first item has already been removed*/
  while(range >0) {
    index++ ;
    prev->next = PopItem(state) ; 
    prev->next->index = index ;
    prev->next->parent = new ;
    prev->next->previous = prev ;
    prev->next->next  = NULL ;
    prev = prev->next ;
    range-- ;
  } ;
  PushItem(state,new) ;
  state->IP = state->IP->next ;  return ;
} ;

void
ICode_nop (struct machinestate* state) { 
  state->IP = state->IP->next ;  return ;
} ;

void
ICode_sin (struct machinestate* state) {
  struct stackelement *arg = PopItem(state) ;
  arg->edata.value = sin(arg->edata.value) ;
  PushItem(state,arg) ;

  state->IP = state->IP->next ;  return ;
} ;

void
ICode_cos (struct machinestate* state) {
  struct stackelement *arg = PopItem(state) ;
  arg->edata.value = cos(arg->edata.value) ;
  PushItem(state,arg) ;

  state->IP = state->IP->next ;  return ;
} ;

void
ICode_tan (struct machinestate* state) {
  struct stackelement *arg = PopItem(state) ;
  arg->edata.value = tan(arg->edata.value) ;
  PushItem(state,arg) ;

  state->IP = state->IP->next ;  return ;
} ;

void
ICode_pushtime (struct machinestate* state) {
  struct stackelement *new = NEW(struct stackelement) ;
  new->type = val ;
  new->etype = value ;
  new->edata.value = state->time ;
  new->parent = NULL ;
  PushItem(state,new) ;  
  state->IP = state->IP->next ;  return ;
} ;

/*This routine creates a stackelement of a given type, it will
  recursively create any required subelements*/
struct stackelement*
CreateStackElement(struct type* type, int *arraydims,struct stackelement *parent){
  struct stackelement *new = NEW(struct stackelement) ;
  new->parent = parent ;
  new->type = type ;
  if(arraydims[0]==0){
    struct fieldnode *currfield = type->fields ;
    if(currfield ==NULL){
      /*This is a single value*/
      new->etype = value ;
      new->edata.value = 0 ;
    } else {
      /*We are pushing a compund object*/
      struct stackelement *currelem ;
      new->etype = fieldlist ;
      new->edata.fields=CreateStackElement(currfield->type,currfield->arraydimensions,new) ;
      new->previous = NULL ;
      new->edata.fields->next = NULL ;
      currelem = new->edata.fields ;
      currfield=currfield->next ;
      while (currfield!=NULL){
	currelem->next = CreateStackElement(currfield->type,currfield->arraydimensions,new) ;
	currelem->next->previous = currelem ;
	currelem = currelem->next;
	currelem->next = NULL ;
	currfield= currfield->next ;
      } ;
    } ;
  } else {
    int newdims[16] , n;
    int width = arraydims[0] ;
    struct stackelement *curr =NULL;
    for(n=0;n<14;n++){
      newdims[n] = arraydims[n+1] ;
    } ;
    arraydims[15] = 0 ;
    new->etype=array ;
    
    curr = CreateStackElement(type,newdims,new) ;
    width -- ;
    new->previous = NULL ;
    curr->next = NULL ;
    new->edata.arrayelements = curr ;
    while(width>0){
      curr->next = CreateStackElement(type,newdims,new) ;
      curr->next->previous = curr ;
      curr = curr->next ;
      curr->next = NULL ;
      width -- ;
    } ;
  } ;
  return new ;
} ;

/*This makes a replica of a stack element, including any data fields*/
/*traverse = 1 causes all subsequent elements to be copied*/
struct stackelement * 
CopyStackElement(struct stackelement * orig, int traverse){
  struct stackelement *new ;
  if(orig!=NULL){
    new = NEW(struct stackelement) ;
    new->etype = orig->etype ;
    new->type = orig->type ;
    switch(new->etype){
      case array:
        new->edata.arrayelements=CopyStackElement(orig->edata.arrayelements,1);
        break ;
      case fieldlist:
	new->edata.fields=CopyStackElement(orig->edata.fields,1);
        break ;
      default:
        new->edata = orig->edata ;
        break ;
    } ;
    if(traverse == 1){
      new->next = CopyStackElement(orig->next,1) ;
    } else {
      new->next = NULL ;
    } ;
  } else {
    new = NULL ;
  } ;
  
  return new ;
} ;

void
FreeStackElement(struct stackelement* element){
  if(element!=NULL){
    FreeStackElement(element->next) ;
    if(element->etype == array){
      FreeStackElement(element->edata.arrayelements) ;
    } ;
    free(element) ;
  } ;
} ;


void
RunICode (FILE *output) {
  struct machinestate currstate ;
  double T ;
  time_t todaysdate ;
  int frameno ;

  /* Run through and find all the labels, put them in the list of labels */
  /* As the code is constructed to jump over functions labels wil not be
     spotted by running the code, we must actually find them.*/
  currstate.labels = NULL ;
  currstate.ribfile = output ;
  currstate.IP = outputcode->first ;
  currstate.SP = currstate.SB = currstate.SF = NULL ;
  
  while(currstate.IP != NULL){
    if(currstate.IP->instr == label){
      struct label *new = NEW(struct label) ;
      new->start = currstate.IP ;
      new->name = currstate.IP->arg ;
      new->next = currstate.labels ;
      currstate.labels = new ;
    } ;
    currstate.IP = currstate.IP->next ;
  } ;
  
  todaysdate = time(NULL) ;
  fprintf(output,"##RenderMan RIB-Structure 1.0\n") ;
  fprintf(output,"##CreationDate %s",ctime(&todaysdate)) ;
      
  frameno = 0 ;
  /* Actually run the code !! ATLAST!! */
  for(T = starttime ; T < endtime ; T += timedelta ){
    int progresstrack = 0;
    if(!quiet)printf("Frame %i:",frameno) ;
    currstate.IP = outputcode->first ;
    FreeStackElement(currstate.SB) ;
    currstate.SP = currstate.SB = currstate.SF = NULL ;
    currstate.time = T ;

    /*Frame preamble*/
    fprintf (output,"FrameBegin %i\n",frameno) ;
    fprintf(output,"Display \"frame%.4i.tif\" \"file\" \"rgb\"\n",frameno) ;
	/*Give a reasonable lighting environment*/
    fprintf(output,"Projection \"perspective\"  \"fov\" 23\n") ;
    fprintf(output,"LightSource \"distantlight\" 1  \"intensity\" 0.75  \"from\"  [ 1 1 1 ]  \"to\"  [ 0 0 0 ]  \"lightcolor\"  [ 1 1 1 ]\n") ;
    fprintf(output,"LightSource \"ambientlight\" 2  \"intensity\" 0.3\n") ;   
    fprintf(output,"WorldBegin\n") ;

    /*We are now ready to start putting stuff into the scene*/    
    while(currstate.IP != NULL){
      if(ICodeFuncs[currstate.IP->instr] != NULL){
#ifdef DEBUG
        struct stackelement *currelem= currstate.SB ;
	while(currelem != NULL){
	  switch(currelem->etype){
	    case value: printf("Value %e\n",currelem->edata.value) ; break ;
	    case array: printf("Array \n") ; break ;
	    case fieldlist: printf("CompundType \n") ; break ;
	    case reference: printf("A reference\n") ;break ;
	    case sfinfo: printf("A stackframe\n") ;break ;
	  } ;
	  currelem = currelem->next ;
	} ;
        printf("%s %s\n",IStrings[currstate.IP->instr],currstate.IP->arg) ;
#endif
	ICodeFuncs[currstate.IP->instr](&currstate) ;
	if((!quiet) && (progresstrack == 50)){
	  printf(".") ;
	  progresstrack = 0 ;
	} else {
	  progresstrack ++ ;
	} ;
      } else {
	printf("Unimplemented Icode Instruction %s\n",IStrings[currstate.IP->instr]) ;
	printf("Read BUGS, then mail me a bugreport\n") ;
	currstate.IP = currstate.IP->next ;
      } ;
    } ;
    fprintf (output,"WorldEnd\n") ;
    fprintf (output,"FraneEnf\n") ;
    printf("\n") ;
    frameno += 1 ;
  } ;
} ;

*/
