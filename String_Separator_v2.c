#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void cambio(char *aux){
	unsigned int i,temp;
	for(i=0;i<= strlen(aux) && temp == 0;i++){
		if(aux[i] == '\n'){
			aux[i] = '\0';
			temp = 1;
		}
	}
}

int WordCount(char *Oracion){
	int i,temp=1,letras = strlen(Oracion);
	for(i=0;i<letras;i++){
		if(Oracion[i] == ' '){
			temp++;
		}
	}
	return temp;
}

char* SeparateWord(char *string, const char *delim,char **Words,int palabras,int cont=1){
	setbuf(stdin,NULL);
	if(palabras > 0){
		unsigned int i,j;
		char *tmp;
		int num = 0;
		char *str = (char*)malloc((strlen(string)+1)*sizeof(char));
		if(str == NULL){
		printf("[!] No se ha podido reservar memoria suficiente!\n");
		exit(1);
	}
		strcpy(str,string);
		tmp = strtok(str,delim);
		if (tmp == NULL){
			printf("[!] Error separando string!\n");
			exit(1);
		}
		num++;
		Words[cont-1] = (char*)malloc(strlen(tmp)*sizeof(char));
		if(Words[cont-1] == NULL){
		printf("[!] No se ha podido reservar memoria suficiente!\n");
		exit(1);
	}
		for(i=0;i<strlen(tmp);i++){
			Words[cont-1][i] = tmp[i];
		}
		char *str2 = (char*)malloc((strlen(string)+1)*sizeof(char));
		if(str2 == NULL){
		printf("[!] No se ha podido reservar memoria suficiente!\n");
		exit(1);
	}
		strcpy(str2,string);
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
		strcpy(string,str2);
		cont += 1;
		return SeparateWord(string,delim,Words,palabras-1,cont);
	}
	else{
		return string;
	}
}
int main(int args, char *argv[]){
	char Aux[270];
	printf("[+] Escribe el texto (255 Carateres max.): ");
	fgets(Aux,270,stdin);
	cambio(Aux);
	unsigned int letras = strlen(Aux);
	char *Oracion = (char*)malloc(letras*sizeof(char));
	if(Oracion == NULL){
		printf("[!] No se ha podido reservar memoria suficiente!\n");
		exit(1);
	}
	strcpy(Oracion,Aux);
	setbuf(stdin,NULL);
	printf("[*] Texto:\t\"%s\"\n[*] Caracteres:\t%d\n",Oracion,letras);
	unsigned int palabras = WordCount(Oracion);
	printf("[*] Palabras: %i\n",palabras);
	setbuf(stdin,NULL);
	char **Words = (char**)malloc(palabras*sizeof(char*));
	if(Words == NULL){
		printf("[!] No se ha podido reservar memoria suficiente!\n");
		exit(1);
	}
	SeparateWord(Oracion," ",Words,palabras);
	unsigned int i;
	for(i=0;i<palabras;i++){
		printf("[*] Word[%i] = [%s]\n",i,Words[i]);
	}
	free(Oracion);
	free(Words);
	setbuf(stdin,NULL);
}
