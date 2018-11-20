#include <stdio.h>
#include <stdbool.h>

typedef enum{
	END_OF_FILE,
	ID_TOKEN,
	PROGRAM_TOKEN,
	CONST_TOKEN,
	 NUM_TOKEN,
	VAR_TOKEN,
	BEGIN_TOKEN,
	END_TOKEN,IF_TOKEN,THEN_TOKEN,WHILE_TOKEN,
	DO_TOKEN,READ_TOKEN,WRITE_TOKEN,PV_TOKEN,PT_TOKEN,
	PLUS_TOKEN,MOINS_TOKEN,MULT_TOKEN,DIV_TOKEN,VIR_TOKEN,AFF_TOKEN,INF_TOKEN,
	INFEG_TOKEN,SUP_TOKEN,SUPEG_TOKEN,DIFF_TOKEN,PO_TOKEN,PF_TOKEN,EGAL_TOKEN,
	FIN_TOKEN,ERREUR_TOKEN
} CODE_LEX;
typedef struct {CODE_LEX CODE; char NOM[20] ;} TSym_Cour;
typedef enum{
	ID_ERR,
	PROGRAM_ERR,
	CONST_ERR,
	VAR_ERR,
	BEGIN_ERR,
	PV_ERR,
	PT_ERR,
	NUM_ERR,
	EGAL_ERR,
	CONST_VAR_BEGIN_ERR
}Erreurs ;
void read_token() ;
extern char* yylval  ;

extern int yylex() ;
extern char* yytext ;

void Test_Symbole(CODE_LEX, Erreurs COD_ERR) ;
void PROGRAM() ;
void BLOCK() ;
void CONSTS() ;
void VARS();
void INSTS();
void Erreur(Erreurs) ;

//void Test_Symbole(code_lex c,erreurs er) ;


//void BLOCK(); 

//void VARS();
//void INSTS();


