#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void Perceptron(){
	srand(time(NULL));
	float intervalos[] = {-0.98,-0.876,-0.654,-0.754,0.453,0.953,-0.322,-0.298,-0.11,-0.065,0.0234,0.232,0.2335,0.4674,0.675,0.7883, 0.752,0.823,0.9876};
	float w1_peso,w2_peso,Umbral,defumbral,factor;
	int i;
	int x1[] = {1,1,-1,-1};
	int x2[] = {1,-1,1,-1};
	int result[] = {1,-1,-1,-1};
	w1_peso = intervalos[rand() % 18];
	w2_peso = intervalos[rand() % 18];
	factor = intervalos[rand() % 18];
	Umbral = intervalos[rand() % 18];
	defumbral = -1;
	int verdad = 0;
	int op;
	int cont = 0;
	int n = 0;
//////////// ENTRENAMIENTO DEL PERCEPTRON;
	while(verdad == 0){
		n++;
		//printf("--------------------- Epoca %i ----------------------\n\n",n);
		for(i=0;i<4;i++){
			//printf("[*] Pesos Sinapticos: %.2f & %.2f -- Umbral: %f\n",w1_peso,w2_peso,Umbral);
			op = ((x1[i]*w1_peso)+(x2[i]*w2_peso)) + (defumbral*Umbral);
			if(op >= 0){
				op = 1;
			}
			else{
				op = -1;
			}
			//printf("\tSalida: %2i --> Patron: %2i\n\n",op,result[i]);
			if(op != result[i]){
				w1_peso = w1_peso + (2*factor)*(x1[i]*result[i]);
				w2_peso = w2_peso + (2*factor)*(x2[i]*result[i]);
				Umbral = Umbral + (2*factor)*(defumbral*result[i]);
			}
		}
		for(i=0;i<4;i++){
			op = ((x1[i]*w1_peso)+(x2[i]*w2_peso)) + (defumbral*Umbral);
			if(op == result[i]){
				cont++;
			}
			if(cont == 4){
				verdad = 1;
			}
		}
		if(n > 200){
			printf("[!] Demasiadas epocas realizadas!\n");
			printf("[!] Intente nuevamente con otros pesos sinapticos.\n");
			exit(1);
		}
	}
/////////// MOSTRAR RESULTADOS FINALES
	system("clear");
	printf("\n[*] FINALIZANDO ENTRENAMIENTO...\n");
	printf("[*] PERCEPTRON SIMPLE [ENTRENADO]\n");
	printf("\n--------------- DATOS FINALES --------------------------------\n\n");
	printf("[*] Total de epocas: (%i)\n",n);
	printf("[*] Peso Sinaptico 1\t\t--> %2.2f\n",w1_peso);
	printf("[*] Peso Sinaptico 2\t\t--> %2.2f\n",w2_peso);
	printf("[*] Umbral(Polarizacion)\t--> %2.2f\n",Umbral);
	printf("\n\n--------------- VERFICIACION DE ENTRENAMIENTO ------------------\n\n");
	for(i=0;i<4;i++){
		op = ((x1[i]*w1_peso)+(x2[i]*w2_peso)) + (defumbral*Umbral);
		if(op >= 0){
			op = 1;
		}
		else{
			op = -1;
			}
		printf("\n[*] Entradas: (%2i,%2i) --> Salida: %2i",x1[i],x2[i],op);
		if(op != result[i]){
			system("clear");
			printf("\n[!] Demasiadas epocas realizadas!\n");
			printf("[!] Intente nuevamente con otros pesos sinapticos.\n");
			exit(1);
			Perceptron();
			}
	}
}
int main(int argc, char **argv)
{
	Perceptron();
	return 0;
}
