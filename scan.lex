%option noyywrap
%option caseless
%{
#ifndef LEXICAL_PARSER_ZZ
#include "fonction.h"
#define LEXICAL_PARSER_ZZ
#endif
%}


lettre			[a-zA-Z]
chiffre			[0-9]
id 				{lettre}({lettre}|{chiffre})*
nb 				{chiffre}+

blanc			[ \t\n]+
chaine			\'[^\']*\'
commentaire		"{"[^{}]*"}"

%%
[bB][eE][gG][iI][nN]					return BEGIN_TOKEN; 
[dD][oO]								return DO_TOKEN ;
[cC][oO][nN][sS][tT]					return CONST_TOKEN ;
[eE][nN][dD]							return END_TOKEN ;
[rR][eE][aA][dD]						return READ_TOKEN ;
[iI][fF]								return IF_TOKEN ;
[wW][rR][iI][tT][eE]					return WRITE_TOKEN ;
[E][O][F]								return FIN_TOKEN ;
[pP][rR][oO][gG][rR][aA][mM]			return PROGRAM_TOKEN ;
[tT][hH][eE][nN]						return THEN_TOKEN ;
[vV][aA][rR]							return VAR_TOKEN ;		
[wW][hH][iI][lL][eE]					return WHILE_TOKEN ;
[ \t]									
[\n]									
[\r\n]									

"+" 									return PLUS_TOKEN ;
"-" 									return MOINS_TOKEN ;
"." 									return PT_TOKEN ;
"*" 									return MULT_TOKEN ;
"," 									return VIR_TOKEN ;
":=" 									return AFF_TOKEN ;
"<" 									return INF_TOKEN ;
"<=" 									return INFEG_TOKEN ;
">" 									return SUP_TOKEN ; 
">=" 									return SUPEG_TOKEN ;
"<>" 									return DIFF_TOKEN ;
"("										return PO_TOKEN ;
")"										return PF_TOKEN ;
";" 									return PV_TOKEN ;
"/" 									return DIV_TOKEN ;

[a-zA-Z][a-z]*[0-9]*					return ID_TOKEN ;
[1-9][0-9]* 							return NUM_TOKEN ;

.										return ERREUR_TOKEN ;

%%
