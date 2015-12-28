#include "fecha.h"

int main(int args, char **argv){
	Fecha UnaFecha,Hoy(2,11,2011); // creamos dos objetos con ambos constructores
	int d,m,a;
	cout << "Hoy: " << Hoy << endl << // imprimimos "hoy" mediante la sobrecarga de <<
			"Fecha a sumar: " << UnaFecha << endl;
	cout << "Escribe dias a sumar: ";
	cin >> d;
	cout << "Meses: ";
	cin >> m;
	cout << "Year: ";
	cin >> a;
	UnaFecha.AsignaFecha(d,m,a); // asignamos las variables a la fecha
	Hoy = Hoy + UnaFecha; // utilizamos la sobrecarga del operador +
	cout << "Suma: " << Hoy << endl << endl;
	Hoy++; // utilizamos el subfijo de sobrecarga ++
	cout << "Mas(+) Un Dia: " << Hoy << endl << endl;
	cout << "Escribe La fecha actual en formato (d/m/a): ";
	cin >> Hoy;
	cout << "La fecha es: " << Hoy << endl;
	cout << "Fecha incremento en Prefijo: " << ++Hoy << endl; // utilizamos el prefijo sobrecargado ++
	return 0;
}
