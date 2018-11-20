#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
 #define TOKEN_SIZE 50 

#ifndef LEXICAL_PARSER_ZZ
#include "fonction.h"
#define LEXICAL_PARSER_ZZ
#endif

//const char* fileName = "le.txt";
//char ligne[81] ;

//char* token =(char *)malloc(81*sizeof(char)); ;
//char token[81] ;
//FILE *fileSrc = fopen(fileName, "r");
CODE_LEX token ;

int main(){
	read_token() ;
	//printf("%s\n",(char*)yytext ) ;


    PROGRAM() ;
    if (token == END_OF_FILE)
 		printf("BRAVO: le programme est correcte!!!");
	else printf("PAS BRAVO: fin de programme erronée!!!!");
/*	
	while (token != END_OF_FILE){
		
		printf("%s\n",(char*)yytext) ;
		read_token() ;
	}
/*	
	if (token==FIN_TOKEN){
 		printf("BRAVO: le programme est correcte!!!");
	}
	}else printf("PAS BRAVO: fin de programme erronée!!!!")

*/

	return 0;
}


void read_token() {
  token = (CODE_LEX)yylex();
  //token.NOM =(char*)yytext ;
}
/*


void read_token(){
	//char ligne[81] ;

	char* token2 =(char *)malloc(81*sizeof(char));
	//free(token) ;
	token2 =fgets(token2, 1024, fileSrc) ;
	//printf("%s",token2);/*fin de fichier non atteinte*/
	//token =(char *)malloc(81*sizeof(char)); 
	  //memset (token, 0 ,81) ;
	   //strcpy(token,token2) ;	
	//COD_LEX *coo =(COD_LEX*) ligne ;
	//printf("%s\n", (char*)tooken.CODE) ;

	//tooken.CODE = coo->code ; 




void Test_Symbole(CODE_LEX cl, Erreurs COD_ERR){
	if ( token == cl){
		read_token();
	}
	else
	Erreur(COD_ERR);
}
void PROGRAM(){
 	Test_Symbole(PROGRAM_TOKEN, PROGRAM_ERR);
 	Test_Symbole(ID_TOKEN, ID_ERR);
 	Test_Symbole(PV_TOKEN, PV_ERR);
 	BLOCK();
	Test_Symbole(PT_TOKEN, PT_ERR);
}
void BLOCK(){
 	CONSTS();
 	VARS();
	INSTS();
}
void CONSTS() {
 	switch (token){
 		case CONST_TOKEN :  read_token() ;
 							Test_Symbole(ID_TOKEN, ID_ERR);
							Test_Symbole(EGAL_TOKEN, EGAL_ERR);
 							Test_Symbole(NUM_TOKEN, NUM_ERR);
							Test_Symbole(PV_TOKEN, PV_ERR);
							while (token == ID_TOKEN){
 								read_token() ;
								Test_Symbole(EGAL_TOKEN, EGAL_ERR);
 								Test_Symbole(NUM_TOKEN, NUM_ERR);
								Test_Symbole(PV_TOKEN, PV_ERR);
							}
							printf("const nadi\n"); break;

 		case VAR_TOKEN: break;
 		case BEGIN_TOKEN: break;
 		default: Erreur(CONST_VAR_BEGIN_ERR);break;
 	}
}
void VARS(){
	switch (token){
 		case VAR_TOKEN :  read_token() ;
 							Test_Symbole(ID_TOKEN, ID_ERR);
							
							while (token == VIR_TOKEN){
 								read_token() ;
								Test_Symbole(ID_TOKEN, ID_ERR);
							}
							; 
							Test_Symbole(PV_TOKEN, PV_ERR);
							printf("var ta hia nadia \n"); break;

 		case CONST_TOKEN: break;
 		case BEGIN_TOKEN: break;
 		default: Erreur(CONST_VAR_BEGIN_ERR);break;
 	}

}
void INSTS(){

}
void Erreur(Erreurs err){


}