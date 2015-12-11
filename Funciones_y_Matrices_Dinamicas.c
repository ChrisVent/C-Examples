#include <stdio.h>
#include <stdlib.h>
// VERIFICAR MEDIANTE FUNCIONES
//QUE DOS MATRICES TIENEN LOS MISMOS ELEMENTOS
// DE FORMA DINAMICA

int **reservar(int filas,int columnas){
// DEBEMOS PONER LOS ** PARA LO QUE DEVUELVA SEA UNA MATRIZ
// OSEA UN PUNTERO A PUNTERO HACIA LA MATRIZ QUE INVOQUE LA
// FUNCION
	int i;
	int **mat;
	mat = (int**)malloc(filas*sizeof(int*));
	if(mat == NULL){
		printf("[!] Oops, Algo salio mal!\n");
		exit(1);
	}
	for(i=0;i<filas;i++){
		mat[i] = (int*)malloc(columnas*sizeof(int));
		if(mat[i] == NULL){
			printf("[!] Oops, Algo salio mal!\n");
			exit(1);
		}
	}
	return mat;
}

void introduce(int filas,int columnas, int **matriz){
	if(matriz == NULL){
		printf("Piensas introducir a una matriz vacia?");
		exit(1);
	}
	int i,j;
	for(i=0;i<filas;i++){
		for(j=0;j<columnas;j++){
			printf("\tvalor para elemento[%i][%i]: ",i,j);
			scanf("%i",&matriz[i][j]);
		}
	}
}

void comparar(int filas,int columnas, int **mat1, int **mat2){
	int i,j,aux = 0;
	for(i=0;i<filas && aux == 0;i++){
		for(j=0;j<columnas && aux == 0;j++){
			if(mat1[i][j] != mat2[i][j]){
				aux = 1;
			}
		}
	}
	if(aux == 0){
		printf("[*]Ambas matrices son iguales!\n");
	}
	else{
		printf("[-] Ambas matrices no son iguales!\n");
	}
}
int main(int argc, char **argv)
{
	int **m1;
	int **m2;
	int fil,col;
	printf("Numero de filas: ");
	scanf("%i",&fil);
	printf("Numero de columnas: ");
	scanf("%i",&col);
	
	m1 = reservar(fil,col);
	m2 = reservar(fil,col);
	printf("Valores de la primera matriz: \n");
	introduce(fil,col,m1);
	printf("Valores de la segunda matriz: \n");
	introduce(fil,col,m2);
	comparar(fil,col,m1,m2);
	free(m1);
	free(m2);
	return 0;
}

