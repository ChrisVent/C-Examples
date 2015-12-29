#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <new>

using namespace std;
int ID = 0, cont = 0;
#define MAX 10

class Contacto{
	string nombre;
	string numero;
	string apellido;
	int ID;
	public:
	Contacto(); // constructor por defecto
	Contacto(string, string, string); // constructor sobrecargado
	int GetID();
	string GetNom();
	string GetNum();
	string GetApe();
	void ModificarNom(string, string);
	void ModificarTel(string);
	void Asignar(string, string, string);
	void Mostrar();
	char GetInicial(int);
	~Contacto();
};

class Agenda{
	FILE *agenda;
	public:
	void Mostrar();
	void Buscar();
	void Disponibles();
	void Modificar();
	void Cargar();
	void Guardar();
	void Crear(int);
	~Agenda();
};

class Programa{
	public:
	Programa();
	void Menu();
	void Open();
};

Contacto contacto[MAX];
Agenda agenda;
