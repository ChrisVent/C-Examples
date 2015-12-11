#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LO QUE HACEMOS ES USAR STRINGS DINAMICOS EN NUESTRA
// ESTRUCTURA Y UN 'BUFFER' (AUX) DE LONGITUD 50 PARA 
// ALMACENAR LA CANTIDAD DE CARACTERES EXACTOS DE LA CADENA
typedef struct{
	char *nombre;
	char *autor;
}libro;
void cambio(char aux[50]){
	int i,temp = 0;
	for(i=0;i<100 && temp== 0;i++){
		if(aux[i] == '\n'){
			aux[i] = '\0';
			temp = 1;
		}
	}
}
// EN cambio() LO QUE HACEMOS ES SUSTITUIR EL '\n' QUE
// FGETS() ASIGNA, POR EL FIN DE TEXTO '\0'
int main(int argc, char **argv)
{
	char aux[50];
	libro Jh;
	printf("Nombre del libro: ");
	fgets(aux,50,stdin);
	cambio(aux);
	Jh.nombre = (char*)malloc((strlen(aux)+1)*sizeof(char));
	if(Jh.nombre == NULL){
		printf("[*] No se ha asignado!.");
		exit(1);
	}
	strcpy(Jh.nombre,aux);
	printf("[*] Nombre del libro: %s.\n",Jh.nombre);
	printf("[*] Size del string: %i.\n",strlen(Jh.nombre));
	
	printf("Introduce un autor para el libro: ");
	fflush(stdin);
	fgets(aux,50,stdin);
	cambio(aux);
	Jh.autor = (char*)malloc((strlen(aux)+1)*sizeof(char));
	if(Jh.autor == NULL){
		printf("[*] No se ha designado!.");
		exit(1);
	}
	strcpy(Jh.autor,aux);
	printf("[*] Autor del libro: %s.\n",Jh.autor);
	printf("[*] Size del string: %i.\n\n\n",strlen(Jh.autor));
	printf("\tLibro: %s.\n\tAutor: %s.\n",Jh.nombre,Jh.autor);
	free(Jh.nombre);
	free(Jh.autor);
	// SIEMPRE LIBEREMOS MEMORIA DE MALLOC() CON FREE()
	return 0;
}
