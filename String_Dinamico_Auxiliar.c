#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void cambio(char *aux){
	int i,temp;
	for(i=0;i<100 && temp == 0;i++){
		if(aux[i] == '\n'){
			aux[i] = '\0';
			temp = 1;
		}
	}
}
int main(int args, char *argv[]){
	char Aux[50];
	printf("Escribe Una Oracion: ");
	fgets(Aux,50,stdin);
	cambio(Aux);
	int letras = strlen(Aux);
	char *Oracion = (char*)malloc(letras*sizeof(char));
	strcpy(Oracion,Aux);
	fflush(stdin);
	printf("[*] Oracion:\t\"%s\"\n[*] Caracteres:\t%d",Oracion,letras);
	free(Oracion);
}
