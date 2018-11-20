#include <stdio.h>
#include <stdbool.h>
#include <string.h>



#include "fonction.c"




int main(){
	read_token() ;
	
//
	while (token.CODE != FIN_TOKEN){
		printf("%s\n",(char*)token.CODE) ;
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