%{
#include <stdio.h>
int outputLexical = 1;	// flag qui permet d'afficher(1)/masquer(0) les messages de l'analyseur lexicale, par défaut (1)
	/* fonction qui affiche un message passé en paramétre */
void output(const char* msg) {
	if(outputLexical == 1) {
		printf("%s\n", msg);
	}
}


%}
%option yylineno

lettre			[a-zA-Z]
chiffre			[0-9]
id 				{lettre}({lettre}|{chiffre})*
nb 				{chiffre}+

blanc			[ \t\n]+
chaine			\'[^\']*\'
commentaire		"{"[^{}]*"}"

%%
[bB][eE][gG][iI][nN]					{ output("BEGIN_TOKEN"); }
[dD][oO]								{ output("DO_TOKEN"); 	}
[cC][oO][nN][sS][tT]					{ output("CONST_TOKEN");}
[eE][nN][dD]							{ output("END_TOKEN"); 	}
[rR][eE][aA][dD]						{ output("READ_TOKEN"); }
[iI][fF]								{ output("IF_TOKEN"); 	}
[wW][rR][iI][tT][eE]					{ output("WRITE_TOKEN"); }
[E][O][F]								{ output("FIN_TOKEN"); }
[pP][rR][oO][gG][rR][aA][mM]			{ output("PROGRAM_TOKEN"); }
[tT][hH][eE][nN]						{ output("THEN_TOKEN"); }
[vV][aA][rR]							{ output("VAR_TOKEN"); 		}
[wW][hH][iI][lL][eE]					{ output("WHILE_TOKEN"); }
[ \t]									{;}
[\n]									{ ;}
[\r\n]									{;}




"+" 									{ output("PLUS_TOKEN"); }
"-" 									{ output("MOINS_TOKEN"); }
"." 									{ output("PT_TOKEN"); }
"*" 									{ output("MULT_TOKEN"); }
"," 									{ output("VIR_TOKEN"); }
":=" 									{ output("AFF_TOKEN"); }
"<" 									{ output("INF_TOKEN"); }
"<=" 									{ output("INFEG_TOKEN"); }
">" 									{ output("SUP_TOKEN"); }
">=" 									{ output("SUPEG_TOKEN"); }
"<>" 									{ output("DIFF_TOKEN"); }
"("										{ output("PO_TOKEN"); }
")"										{ output("PF_TOKEN"); }
";" 									{ output("PV_TOKEN"); }
"/" 									{ output("DIV_TOKEN"); }




[a-zA-Z][a-z]*[0-9]*					{ output("ID_TOKEN")    ;}
[1-9][0-9]* 							{ output("NUM_TOKEN")   ;}
.										{ output("ERREUR_TOKEN") ;}

%%