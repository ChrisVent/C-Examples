#include <stdio.h>
#include <stdlib.h>
// PILAS == ULTIMO EN ENTRAR, PRIMERO EL SALIR --->  "last in, first out" (LIFO)
// COLAS == PRIMERO EN ENTRAR, PRIMERO EN SALIR  ---> "first in, first out" (FIFO)
// ESTA ES UNA "cola", el primer elemento de la lista, es el primero en salir de la misma... 
typedef struct Nodo{
	int Dato;
	Nodo *Siguiente;
}Nodo;
Nodo *NodoInicial;
Nodo *NodoFinal;
void InitLista(){
	NodoInicial = NULL;
	NodoFinal = NULL;
}
void Add_EmptyList(int dato){
	Nodo *NodoExample = (Nodo*)malloc(sizeof(Nodo));
	if(NodoExample == NULL){
		printf("[!] Error in Memory Reserving");
		exit(1);
	}
	NodoExample->Dato = dato;
	NodoInicial = NodoExample;
	NodoFinal = NodoExample;
	NodoExample->Siguiente = NULL;
}

void Push_Stack(int dato){
	Nodo *NodoExample = (Nodo*)malloc(sizeof(Nodo));
	if(NodoExample == NULL){
		printf("[!] Error in Memory Reserving");
		exit(1);
	}
	NodoExample->Dato = dato;
	NodoFinal->Siguiente = NodoExample;
	NodoFinal = NodoExample;
}
int Pop_Stack(){
	Nodo *SuprNodo;
	SuprNodo = NodoInicial;
	NodoInicial = NodoInicial->Siguiente;
	free(SuprNodo);
	return 0;
}
void ShowList(){
	Nodo *Aux = NodoInicial;
	if(Aux == NULL){
		printf("[ Cola vacia! ]\n");
		exit(1);
	}
	else{
		printf("[ ");
		while(Aux != NULL){
			if(Aux->Siguiente != NULL){
				printf("%02i -> ",Aux->Dato);
			}
			else{
				printf("%02i",Aux->Dato);
			}
			Aux = Aux->Siguiente;
		}
		printf(" ]\n");
	}
}
int main(){
	InitLista();
	Add_EmptyList(0);
	int i;
	for(i=1;i<=5;i++){
		Push_Stack(i*10);
	}
	printf("[*] Primer Nodo: %02i\n",NodoInicial->Dato);
	printf("[*] Estado de cola:\t");
	ShowList();
	for(i=0;i<=5;i++){
		printf("[*] Estado de cola:\t");
		Pop_Stack();
		ShowList();
	}
}
