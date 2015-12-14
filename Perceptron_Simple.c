#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	float w1_peso,w2_peso,Umbral,defumbral;
	//int factor;
	int i;
	int x1[] = {1,1,-1,-1};
	int x2[] = {1,-1,1,-1};
	int result[] = {1,-1,-1,-1};
	w1_peso = 1.2;
	w2_peso = -1.2;
	//factor = 0.5;
	Umbral = -0.4;
	defumbral = -1;
	int verdad = 0;
	int op;
	int cont = 0;
	int n = 0;
//////////// ENTRENAMIENTO DEL PERCEPTRON;
	while(verdad == 0){
		n++;
		system("clear");
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
				w1_peso = w1_peso + (2*0.5)*(x1[i]*result[i]);
				w2_peso = w2_peso + (2*0.5)*(x2[i]*result[i]);
				Umbral = Umbral + (2*0.5)*(defumbral*result[i]);
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
	}
/////////// MOSTRAR RESULTADOS FINALES
	printf("\n\n---------------- VALORES FINALES -----------------\n\n");
	printf("[*] Total de epocas: (%i)\n",n);
	printf("[*] Peso Sinaptico 1\t\t--> %2.2f\n",w1_peso);
	printf("[*] Peso Sinaptico 2\t\t--> %2.2f\n",w2_peso);
	printf("[*] Umbral\t\t\t--> %2.2f\n",Umbral);
	printf("\n\n------------------------------------\n\n");
	int ux1,ux2;
	printf("Escribe el valor para P1 (Entrada 1): ");
	scanf("%i",&ux1);
	printf("Escribe el valor para P2 (Entrada 2): ");
	scanf("%i",&ux2);
	op = ((ux1*w1_peso)+(ux2*w2_peso)) + (defumbral*Umbral);
	if(op >= 0){
		op = 1;
	}
	else{
		op = -1;
	}
	printf("Salida --> %i \n",op);
	return 0;
}
