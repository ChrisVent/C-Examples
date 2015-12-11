#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdio_ext.h>
int numero,src,i,potencia;
typedef char String[16];
String Binario;
char Salida;
int j;
int main(){
		printf("\nEscribe el numero a pasar a binario: ");
		setbuf(stdin, NULL);
		scanf("%d",&numero);
		src = numero;
			for(i = 15 ; i >= 0 ; i--){
				potencia = pow(2,i);
				if (potencia <= numero){
					numero -= potencia;
					strcat(Binario,"1");
					if(strlen(Binario) == 4 || strlen(Binario) == 9 || strlen(Binario) == 14){
						strcat(Binario," ");
					}
				}
				else{
					strcat(Binario,"0");
					numero = numero;
					if(strlen(Binario) == 4 || strlen(Binario) == 9 || strlen(Binario) == 14){
						strcat(Binario," ");
					}
				}
			}
		printf("\n[*] El numero %i en binario es: %s\n",src,Binario);
	return EXIT_SUCCESS;
}
