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

void WordCount(char *Oracion,int *Cont){
	int i,temp=1;
	for(i=0;i<*Cont;i++){
		if(Oracion[i] == ' '){
			temp++;
		}
	}
	printf("\n[*] N^ de Palabras: %i \n",temp);
}

void SeparateWord(char *string, const char *delim){
	char *tmp;
	int num = 0;
	char *str = (char*)malloc((strlen(string)+1)*sizeof(char));
	strcpy(str,string);
	tmp = strtok(str,delim);
	if (tmp == NULL){
		printf("[!] Error separando string!\n");
		exit(1);
	}
	num++;
	printf("Primera parabra -> [%s] \n",tmp);
	char *str2 = (char*)malloc((strlen(string)+1)*sizeof(char));
	strcpy(str2,string);
	unsigned int i,j;
	int esp = 0;
	for(i=0;i<strlen(str2) && esp == 0;i++){
		if(string[i] == ' '){
			int k = i+1;
			for(j=0;j<(strlen(str2)-strlen(tmp));j++){
				str2[j] = string[k];
				k++;
			}
			esp++;
		}
	}
	printf("Recorte: %s\n",str2);
	strcpy(string,str2);
	printf("Ahora string es: %s\n",string);
	free(str);
	free(str2);
}
int main(int args, char *argv[]){
	char Aux[255];
	printf("[+] Escribe el texto (255 Carateres max.): ");
	fgets(Aux,255,stdin);
	cambio(Aux);
	int letras = strlen(Aux);
	char *Oracion = (char*)malloc(letras*sizeof(char));
	strcpy(Oracion,Aux);
	fflush(stdin);
	letras = strlen(Oracion);
	printf("[*] Texto:\t\"%s\"\n[*] Caracteres:\t%d",Oracion,letras);
	WordCount(Oracion,&letras);
	int i = 0;
	while(i < 3){
		SeparateWord(Oracion," ");
		i++;
	}
	free(Oracion);
}
