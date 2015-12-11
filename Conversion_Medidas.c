#include <stdio.h>
#include <stdlib.h>

int menu;
float centimetros;
float metros;
float pulgadas;
float pies;
typedef float medida;
typedef float entrada;
char Salir;

float conversion_Pulgadas_Metros(float pulgadas);
float conversion_Centimetros_Pulgadas(float centimetros);
float conversion_Centimetros_Metros(float centimetros);
float conversion_Pies_Metros(float pies);
float conversion_Pies_Pulgadas(float pies);
float conversion_Metros_Pulgadas(float metros);
float conversion_Pulgadas_Pies(int pulgadas);

void inchesToMetros();
void cmToInches();
void cmToMetros();
void feetsToMetros();
void feetsToinches();
void metrosToInches();
void inchesToFeets();
void Salida();
void Principal();
void Intro();
int main(int argc, char **argv)
{
	Intro();
	Principal();
	return 0;
}

void Intro(){
	printf(" ---------------------------------------------------------------------------\n");
	printf("          o  o       o oooooo  oo    o   ooooooo   oooooo   oooooo          \n");
	printf("       o    o o     o  o       o o   o  oo         o        o    oo         \n");
	printf("       oooooo  o   o   oooooo  o  o  o  o   oooo   oooooo   o ooooo         \n");
	printf("       o    o   o o    o       o   o o  o      oo  o        o  o            \n");
	printf("       o    o    o     oooooo  o    oo   oooooo    oooooo   o   oo          \n");
	printf(" ---------------------------------------------------------------------------\n\n");
}
void Salida(){
	printf("---------------------------------------------------------------------------\n");
	printf(" [+] Quieres salir? [s,n]: ");
	scanf("%c",&Salir);
	if(Salir == 'n' || Salir == 'N'){
		system("clear");
		Principal();
	}
	else{
			system("exit");
		}
}
float conversion_Pulgadas_Metros(float pulgadas){
	centimetros = pulgadas * 2.54;
	metros = centimetros /100;
	return metros;
}
float conversion_Centimetros_Pulgadas(float centimetros){
	pulgadas = centimetros / 2.54;
	return pulgadas;
}
float conversion_Centimetros_Metros(float centimetros){
	metros = centimetros / 100;
	return metros;
}
float conversion_Pies_Metros(float pies){
	float pulgs = pies * 12;
	centimetros = pulgs / 2.54;
	metros = centimetros / 1000;
	return metros;
}
float conversion_Pies_Pulgadas(float pies){
	pulgadas = pies *12;
	return pulgadas;
}
float conversion_Metros_Pulgadas(float metros){
	float centi = metros / 100;
	pulgadas = centi * 2.54;
	return pulgadas;
}
float conversion_Pulgadas_Pies(int pulgadas){
	pies = pulgadas / 12;
	return pies;
}


void inchesToMetros(){
	system("clear");
	printf("---------------------------------------------------------------------------\n");
	printf(" Escribe la cantidad en pulgadas: ");
	entrada pulgadas;
	scanf("%f",&pulgadas);
	medida m = conversion_Pulgadas_Metros(pulgadas);
	printf("---------------------------------------------------------------------------\n");
	printf(" [*] %f metros \n",m);
}
void cmToInches(){
	system("clear");
	printf("---------------------------------------------------------------------------\n");
	printf(" Escribe la cantidad en centimetros: ");
	entrada centimetros;
	scanf("%f",&centimetros);
	medida inches = conversion_Centimetros_Pulgadas(centimetros); 
	printf("---------------------------------------------------------------------------\n");;
	printf(" [*] %f pulgadas\n",inches);
}
void cmToMetros(){
	system("clear");
	printf("---------------------------------------------------------------------------\n");
	printf(" Escribe la cantidad en centimetros: ");
	entrada centimetros;
	scanf("%f",&centimetros);
	medida inches = conversion_Centimetros_Metros(centimetros); 
	printf("---------------------------------------------------------------------------\n");
	printf(" [*] %f Metros\n",inches);
}
void feetsToMetros(){
	system("clear");
	printf("---------------------------------------------------------------------------\n");
	printf(" Escribe la cantidad en Pies: ");
	entrada pies;
	scanf("%f",&pies);
	medida inches = conversion_Pies_Metros(pies); 
	printf("---------------------------------------------------------------------------\n");
	printf(" [*] %f Metros\n",inches);
}
void feetsToinches(){
	system("clear");
	printf("---------------------------------------------------------------------------\n");
	printf(" Escribe la cantidad en Pies: ");
	entrada pies;
	scanf("%f",&pies);
	medida inches = conversion_Pies_Pulgadas(pies); 
	printf("---------------------------------------------------------------------------\n");
	printf(" [*] %f Pulgadas\n",inches);
}
void metrosToInches(){
	system("clear");
	printf("---------------------------------------------------------------------------\n");
	printf(" Escribe la cantidad en Metros: ");
	entrada metros;
	scanf("%f",&metros);
	medida inches = conversion_Metros_Pulgadas(metros); 
	printf("---------------------------------------------------------------------------\n");
	printf(" [*] %f Pulgadas\n",inches);
}
void inchesToFeets(){
	system("clear");
	printf("---------------------------------------------------------------------------\n");
	printf(" Escribe la cantidad en pulgadas: ");
	entrada pulgadas;
	scanf("%f",&pulgadas);
	medida inches = conversion_Pulgadas_Pies(pulgadas); 
	printf("---------------------------------------------------------------------------\n");
	printf(" [*] %f Pies\n",inches);
}
void Principal(){
	printf("---------------------------------------------------------------------------\n");
	printf(" Conversiones: \n");
	printf("---------------------------------------------------------------------------\n");
	printf("\t1 - Pulgadas a Metros.\n");
	printf("---------------------------------------------------------------------------\n");
	printf("\t2 - Centimetros a Metros.\n");
	printf("---------------------------------------------------------------------------\n");
	printf("\t3 - Pies a Metros.\n");
	printf("---------------------------------------------------------------------------\n");
	printf("\t4 - Centimetros a Pulgadas.\n");
	printf("---------------------------------------------------------------------------\n");
	printf("\t5 - Pies a Pulgadas.\n");
	printf("---------------------------------------------------------------------------\n");
	printf("\t6 - Metros a Pulgadas.\n");
	printf("---------------------------------------------------------------------------\n");
	printf("\t7 - Pulgadas a Pies.\n");
	printf("---------------------------------------------------------------------------\n");
	printf(" Opcion: ");
	scanf("%i",&menu);
	switch(menu){
		case 1:
			inchesToMetros();break;
		case 2: 
			cmToMetros();break;
		case 3: 
			feetsToMetros();break;
		case 4:
			cmToInches();break;
		case 5:
			feetsToinches();break;
		case 6: 
			metrosToInches();break;
		case 7:
			inchesToFeets();break;
	}
	if(menu > 7 || menu < 1){
		system("clear");
		printf("Opcion no valida!\n");
		Principal();
	}
	getchar();
	Salida();
}
