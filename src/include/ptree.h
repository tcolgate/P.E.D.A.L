/* Structures for describing the parse tree 
   These are pretty much directly related to the constructs in the grammar
 */

#ifndef _PTREE_H
#define _PTREE_H


typedef struct {
  float value ;
} PTNumber ;

typedef struct {
  char *text ;
} PTString ;

typedef struct {
} PTType ;

typedef struct {
} PTLValue ;

typedef struct {
} PTLValueExp ;

typedef struct {
  PTLValueExp *lvalue ;
  struct _PTExpreesion *expression ;
} PTAssignOp ;

typedef struct {
} PTUMinuxOP ;

typedef struct {
} PTSumOP ;

typedef struct {
} PTMinusOP ;

typedef struct {
} PTMultiplyOP ;

typedef struct {
} PTDivideOP ; 

typedef struct {
} PTPowOP ;

typedef struct {
} PTDotProdOP ;

typedef struct {
} PTCrossProdOP ;

typedef struct {
} PTArrayExp ;

typedef struct {
} PTCallOP ; 

typedef struct {
} PTSubExp ;

typedef struct {
} PTCastExp ;

typedef struct _PTExpression {
} PTExpression ;

typedef struct {
} PTExpression_List ;

typedef struct {
} PTCondition ;

typedef struct {
    char *name ;
} PTObjectDCL ;

typedef struct {
  char *name ;
} PTFunctionDCL ;

typedef struct {
  char *name ;
  
} PTVariableDCL ;

typedef struct {
  PTExpression *expreesion ; /*Any objects resulting from this expression 
			       should be used as the result for the previous
			       call node */
} PTReturnCST ;

typedef struct {
  PTExpression *expression ; /*The object(s) resulting from this expression
			       should be sent to the output filter*/
} PTOutputExp ;

typedef struct {
  struct PTControlST_List *ControlST_list ;
} PTBlockCST ;

typedef struct {
  PTCondition *Condition ;
  PTBlockCST *MainBlock ; 
} PTWhileCST ;

typedef struct {
  PTExpression *InitExp ;
  PTCondition *Condition ;
  PTExpression *Iterator ;
  PTBlockCST *MainBlock ; 
} PTForCST ;

typedef struct {
  PTCondition *condition ;
  PTBlockCST *thewayoftruth ;/* Well I couldnt think of a better name */
  PTBlockCST *thewayoffalse ;
} PTIfCST ;

typedef struct {
  char *filename ; 
} PTImportCST ;

typedef union {
  PTImportCST ImportCST ;
  PTIfCST IfCST ;
  PTForCST ForCST ;
  PTWhileCST WhileCST ;
  PTBlockCST BlockCST ;
  PTExpression Expression ;
  PTOutputExp OutputExp ;
  PTReturnCST ReturnCST ;
  PTVariableDCL VariableDCL ;
} PTUControlST ;

typedef enum {
  Import,
  If,
  For,
  While,
  Block,
  Expression,
  Output,
  Return,
  Variable,
} PTEControlST ;

typedef struct {
  PTEControlST ControlST;
  PTUControlST ControlSTType;
} PTControlST ;

typedef struct _PTControlST_List{
  PTControlST *ControlST ;
  struct _PTControlST_List *next ;
} PTControlST_List ;

typedef union {
  PTObjectDCL ObjectDCL ;
  PTFunctionDCL FunctionDCL ;
  PTControlST ControlST ;
} PTUStatement ;

typedef enum {
  Object,
  Function,
  Control
} PTEStatement ;

typedef struct {
  PTUStatement Statement ;
  PTEStatement StatementType ;
} PTStatement ;

typedef struct _PTStatement_List {
  PTStatement *Statement ;
  struct _PTStatement_list *next ;
} PTStatement_List ;

typedef struct {
  PTStatement_List *Statemnet_List ;
} PTProgram  ;

typedef struct PTProgram* ptree ;

/* Parse tree functions, these are used to initialise, manipulate and
   store the trees */


#endif

