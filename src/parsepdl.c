#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "include/parsepdl.h"
#include "include/symtab.h"
#include "include/types.h"
#include "include/scope.h"
#include "include/icode.h"
#include "include/nodestructures.h"

#include "grammar.h" 

extern FILE *yyin ;
extern int yyparse(void) ;

/* Global info, mostly to reflect the option */
int dumpicode = 0 ; /*Whether or not to dump the intermediate code to a file*/
int quiet = 0 ; /* Whether to run quite (for batch mode) */
int pipe = 0 ; /*Whether to act as a pipe*/

float starttime,endtime ;/*Start and finsh values for time variable*/
float timedelta ;/*Amount to increase time by each erm... time*/

extern int errorcount ;

char *pdlfilename = NULL; /*name of the file being read and parsed NULL=STDIN */
char *ribfilename = NULL ;
FILE *icodefile = NULL; /*The file to dump the icode to*/
FILE *ribfile = NULL; /*File to dump RIB to, NULL=STDOUT*/

int
ParseSwitches(int argc, char** argv){
  int arg ;

  FILE *input ;
  
  /*setup some default values*/
  starttime = 0.0;
  endtime = 10.0 ;
  timedelta = 1.0/24.0 ;
  
  if (argc > 1) {
    for ( arg = 1 ; arg < argc ; arg++){
      if(argv[arg][0] == '-'){
        /* This is a set of switches */
        int letter = 1 ;
        while (argv[arg][letter] != '\0'){
	  switch (argv[arg][letter]){
	    case 'o':
	        dumpicode=1 ;
		break ;
	    case 'f':
		ribfilename=&(argv[arg][letter+1]) ;
		letter+=strlen(&(argv[arg][letter+1])) ;
		break ;
	    case 'q':
		quiet = 1 ;
		break ;
	    case 'p':
		quiet = 1 ;
		pipe = 1 ;
		break ;	
		/* The time related options */
	    case 'S':
		starttime = strtod(&(argv[arg][letter+1]),NULL) ;
		letter+=strlen(&(argv[arg][letter+1])) ;
		break ;
	    case 'E':
		endtime = strtod(&(argv[arg][letter+1]),NULL) ;
		letter+=strlen(&(argv[arg][letter+1])) ;
		break ;
	    case 'D':
		timedelta = strtod(&(argv[arg][letter+1]),NULL) ;
		letter+=strlen(&(argv[arg][letter+1])) ;
		break ;
		
		/* The help options */
	   case 'h':  
		return 0 ; 
		break ;
		
		/*unrecognised option*/
  	    default :  
		printf ("Invalid switch -%c\n",argv[arg][letter]) ; 
		return 0 ; 
		break ;
  	  } ;
	  letter++ ;
        } ;
      } else {
        /* This is a filename */
        pdlfilename = argv[arg] ;
      } ;
    } ;
  } else {
    /* There were no switches, so everything must be OK */
    return 1 ;
  } ;
  if (pdlfilename != NULL){
    input = fopen(pdlfilename,"r") ;
    if (input != NULL){
      yyin = input ;
      
      return 1 ;
    } else {
      printf ("File not found: %s\n",pdlfilename);
      return 0 ;
    } ;
  } ;
  
  return 1 ;
} ;

int
main(int argc, char** argv){
  char icodefilename[128] ;
  FILE *yyincopy = yyin;

  if (ParseSwitches(argc,argv)){ 
  /* Initialise the types symbol table */
    InitialiseGlobalScope() ; 
    
    if(dumpicode){
      if(yyin != yyincopy){
        strcpy(icodefilename,pdlfilename) ;
        if(!strcmp(&(pdlfilename[strlen(pdlfilename)-4]),".pdl")){
          icodefilename[strlen(icodefilename)-1]='o' ;
        } else {
	  strcat(icodefilename,".pdo") ;
        }	;
      } else {
	strcpy(icodefilename,"stdin.pdo") ;
      } ;
      if(!(icodefile = fopen(icodefilename,"w"))){
        dumpicode = 0 ;
        printf("Could not open %s for writing ICode\n",icodefilename) ;
      };
    };

    if(ribfilename == NULL){
      if(yyin != yyincopy){
        ribfilename = (char*) malloc ((strlen(pdlfilename)+4) *sizeof(char)) ;
        ribfilename[0] = '\0' ;
        strcpy(ribfilename,pdlfilename) ;
        if(!strcmp(&(pdlfilename[strlen(pdlfilename)-4]),".pdl")){
          ribfilename[strlen(ribfilename)-3]='r' ;
	  ribfilename[strlen(ribfilename)-2]='i' ;
	  ribfilename[strlen(ribfilename)-1]='b' ;
        } else {
          strcat(icodefilename,".rib") ;
        } ;
      } else {
	ribfilename = "stdin.rib" ;
      } ;
    } ;
    
    if(pipe){
      ribfile = stdout ;
    } else {
      if(!(ribfile = fopen(ribfilename,"w"))){
        printf ("Could not open %s for writing RIB\n",ribfilename) ;
        return 0;
      } ;
    } ;
    
    errorcount = 0 ;						    
    if(!quiet){
      printf("Parsing script\n") ;
    } ;
    yyparse () ;
    printf("\n") ; /*Gives a new line after the progress dots. */
    if(errorcount == 0) {
      if(!quiet){
        if(dumpicode) printf ("ICode will be dumped to %s\n",icodefilename) ;
        if(ribfilename!=NULL)printf("Producing %s\n",ribfilename) ;
      } ;
    } else {
      printf("There were %i error.\n",errorcount);
      printf("These must be fixed before processing can continue\n") ;
    } ;
    return 1 ;
	  
  } else {
    printf("PEDAL to RIB converter:\n") ;
    printf("Usage: parsepdl [OPTIONS] [file]\n") ;
    printf("Options:\n") ;
    printf("  -q: Run quietly, if you are using this in a pipeline\n") ;
    printf("  -o: To dump the intermediate code\n") ;
    printf("  -f: Filename to dump RIB to, a default is supplied otherwise\n");
    printf("  -p: Act as a pipe, write RIB to stdout, implies quite\n");
    printf("  -h: This usage message\n") ;
    printf("  -S: Start time \n") ;
    printf("  -E: End time \n") ;
    printf("  -D: Time Delta, the time increment\n") ;
    return 0 ;
  } ;
}

