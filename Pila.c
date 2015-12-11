#include <stdlib.h>
#include <stdio.h>
// PILAS == ULTIMO EN ENTRAR, PRIMERO EL SALIR --->  "last in, first out" (LIFO)
// COLAS == PRIMERO EN ENTRAR, PRIMERO EN SALIR  ---> "first in, first out" (FIFO)
// ESTA ES UNA "pila", el primer elemento de la lista, es el primero en salir de la misma... 
typedef struct Nodo{
	int Dato;
	Nodo *Siguiente;
}Nodo;
Nodo *NodoInicial;
void InitLista(){
	NodoInicial = NULL;
}
void Add_EmptyList(int dato){
	Nodo *NodoExample = (Nodo*)malloc(sizeof(Nodo));
	if(NodoExample == NULL){
		printf("[!] Error in Memory Reserving");
		exit(1);
	}
	NodoExample->Dato = dato;
	NodoExample->Siguiente = NodoInicial;
	NodoInicial = NodoExample;
}
void Push_Queues(int dato){
	Nodo *NodoExample = (Nodo*)malloc(sizeof(Nodo));
	if(NodoExample == NULL){
		printf("[!] Error in Memory Reserving");
		exit(1);
	}
	NodoExample->Dato = dato;
	NodoExample->Siguiente = NodoInicial;
	NodoInicial = NodoExample;
}
void Pop_Queues(){
	Nodo *SuprNodo;
	SuprNodo = NodoInicial;
	NodoInicial = NodoInicial->Siguiente;
	free(SuprNodo);
}
void ShowList(){
	Nodo *Aux;
	Aux = NodoInicial;
	if(Aux == NULL){
		printf("[ Pila vacia! ]\n");
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
int main(int argc, char **argv)
{
	Add_EmptyList(5);
	Push_Queues(10);
	Push_Queues(20);
	Push_Queues(25);
	Push_Queues(30);
	printf("[*] Ultimo Nodo: %i\n",NodoInicial->Dato);
	printf("[*] Estado de pila:\t");
	ShowList();
	int i;
	for(i=0;i<5;i++){
		printf("[*] Estado de pila:\t");
		Pop_Queues();
		ShowList();
	}
	return 0;
}

