#include <iostream>

using namespace std;

class Fecha{
	int day, month, year;
	public:
		Fecha(); //constructor normal
		Fecha(int,int,int); // constructor sobrecargado
		Fecha operator+(Fecha); //sobrecarga de operador +
		Fecha operator++(int); // sobrecarga de operador de subfijo ++ 
		Fecha &operator++(); // sobrecarga de operador de prefijo ++
		friend ostream &operator<<(ostream &,Fecha); // sobrecarga de operador << salida
		friend istream &operator>>(istream &,Fecha &); // sobrecarga de operador >> entrada
		int MaxDiaMes(int,int); // averiguamos si es de 31,30,28,29
		void AsignaFecha(int,int,int); // asignamos fecha (variables)
}; 
