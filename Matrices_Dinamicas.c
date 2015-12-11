#include <stdio.h>
#include <stdlib.h>

// COPIAR EL CONTENIDO DE UNA MATRIZ EN OTRA DE MANERA DINAMICA
int main(int argc, char **argv)
{
	int fil,col,i,j;
	int **m1;
	int **m2;
	
	printf("Cuantas filas: ");
	scanf("%i",&fil);
	
	printf("Cuantas columnas: ");
	scanf("%i",&col);
	//////// PRIMERA MATRIZ //////////////////
	m1 = (int**)malloc(fil*sizeof(int*));
	if(m1 == NULL){
		printf("[*] No se reservo memoria!\n");
		exit(1);
	}
	for(i=0;i<fil;i++){
		m1[i] = (int*)malloc(col*sizeof(int));
		if(m1[i] == NULL){
			printf("[*] No se reservo memoria!\n");
			exit(1);
		}
	}
	///// ELEMENTOS DE PRIMERA MATRIZ /////////
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			printf("\tValor de matriz[%i][%i]: ",i,j);
			scanf("%i",&m1[i][j]);
		}
	}
	//////////////// SEGUNDA MATRIZ /////////////	
	m2 = (int**)malloc(fil*sizeof(int*));
	if(m2 == NULL){
		printf("[*] No se reservo memoria!\n");
		exit(1);
	}
	for(i=0;i<fil;i++){
		m2[i] = (int*)malloc(col*sizeof(int));
		if(m2[i] == NULL){
			printf("[*] No se reservo memoria\n");
			exit(1);
		}
	}
	printf("\nSEGUNDA MATRIZ\n\n");
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			m2[i][j] = m1[i][j];
			printf("\tValor de matriz[%i][%i]: %i\n",i,j,m2[i][j]);
		}
	}
	free(m1);
	free(m2);
	return 0;
}

