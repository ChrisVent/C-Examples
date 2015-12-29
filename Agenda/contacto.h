#include "header.h"

Contacto::Contacto(){
	this->nombre = ' ';
	this->numero = ' ';
	this->apellido = ' ';
	this->ID = ++::ID;
}

Contacto::Contacto(string numero, string nombre, string apellido){
	this->nombre = nombre;
	this->numero = numero;
	this->apellido = apellido;
	this->ID = ++::ID;
	::cont = this->ID;
}

int Contacto::GetID(){
	return (*this).ID;
}
string Contacto::GetNom(){
	return (*this).nombre;
}
string Contacto::GetNum(){
	return (*this).numero;
}
string Contacto::GetApe(){
	return (*this).apellido;
}

void Contacto::Mostrar(){
	if(this->numero != " "){
		cout << endl << "\tID: \t" << this->ID << endl;
		cout << "\tNombre: \t" << this->nombre << endl;
		cout << "\tApellido: \t" << this->apellido << endl;
		cout << "\tTelefono: \t" << this->numero << endl; 
		cout << endl << "\t---------------------------------------------" << endl;
	}
}

void Contacto::Asignar(string numero = " ", string nombre = " ", string apellido = " "){
	this->numero = numero;
	this->nombre = nombre;
	this->apellido = apellido;
	::cont = this->ID;
}

char Contacto::GetInicial(int p=0){
	if(p == 2) return this->apellido[0];
	else return this->nombre[0];
}

void Contacto::ModificarNom(string nombre, string apellido){
	if(nombre != " "){
		this->nombre = nombre;
	}
		if(apellido != " "){
		this->apellido = apellido;
	}
}
void Contacto::ModificarTel(string numero){
	if(numero != " "){
		this->numero = numero;
	}
}

Contacto::~Contacto(){
	//cout << "\t[!] Se ha borrado el contacto: [" << (*this).nombre << " - " << (*this).numero << "]" << "[" << (*this).ID << "]" << endl;
}

void Agenda::Mostrar(){
	this->Disponibles();
	cout << "___________________________________________________________" << endl << endl;
	for(int i=0;i<MAX;i++){
		contacto[i].Mostrar();
	}
	getchar();
}

void Agenda::Buscar(){
	char ini;
	cout << "\tEscribe la letra a buscar: ";
	cin >> ini;
	bool found = false;
	ini = toupper(ini);
	cout << "___________________________________________________________" << endl << endl;
	cout << endl << "[*] Resultados de Busqueda para \"" << ini << "\":" << endl;
	for(int i=0;i<cont;i++){
		if( ini == toupper(contacto[i].GetInicial()) || ini == toupper(contacto[i].GetInicial(2))){
			found = true;
			contacto[i].Mostrar();
		}
	}
	if(found == false){
		cout << "    [...No se encontraron resultados!]." << endl;
	}
	getchar();
}

void Agenda::Disponibles(){
	cout << "___________________________________________________________" << endl << endl;
	cout << endl << "[*] Un total de " << cont << " Contacto(s) Asignado(s)."<< endl;
	cout << "\t" << MAX-cont << " Contactos Disponibles." << endl << endl;
}

void Agenda::Crear(int ID){
	if(cont < MAX){
		string en, num, nom, ape;
		getline(cin,en,'\n');
		cout << endl << "[+] Agregar Contacto: " << endl;
		cout << "\tTelefono: ";
		getline(cin,num,'\n');
		cout << "\tNombre: ";
		getline(cin,nom,'\n');
		cout << "\tApellido: ";
		getline(cin,ape,'\n');
		contacto[ID].Asignar(num,nom,ape);
		cout << endl <<"[*] Contacto Creado!! (Presione ENTER Para volver al menu)";
	}
	else{
		cout << "\n\n[*]Aqui esta lleno! ";
		getchar();
	}
	getchar();
}

void Agenda::Modificar(){
	int ID, op;
	string num,nom,ape,n,m;
	cout << "\tEscribe el ID del contacto: ";
	cin >> ID;
	getline(cin,n,'\n');
	contacto[ID-1].Mostrar();
	cout << "\tModificar: " << endl;
	cout << "\t\t1 - Telefono" << endl;
	cout << "\t\t2 - Nombre y Apellido" << endl;
	cout << "\tOPCION: ";
	cin >> op;
	getline(cin,m,'\n');
	switch(op){
	case 1:	
		cout << "\t\tTelefono: ";
		getline(cin,num);
		contacto[ID-1].ModificarTel(num);
		break;
	case 2:
		cout << "\t\tNombre: ";
		getline(cin,nom);
		cout << "\t\tApellido: ";
		getline(cin,ape);
		contacto[ID-1].ModificarNom(nom, ape);
		break;
	}
	cout << "\n[*] Contacto Modificado! (PRESIONE ENTER PARA VOLVER)";
}

void Agenda::Cargar(){
	//ifstream agenda("agenda.txt");
	agenda = fopen("agenda.txt","r");
	if(agenda == NULL){
		cout << "[!] No existe tal archivo!" << endl;
		exit(2);
	}
	char c[100];
	while(feof(agenda) == 0){
		fgets(c,100,agenda);
		cout << c;
	}
	fclose(agenda);
	getchar();
}

void Agenda::Guardar(){
	ofstream agenda("agenda.txt");
	//ifstream --> para entrada // ofstream --> para salida
	for (int i = 0; i< cont ; i++){
		agenda << endl << "\tID:\t\t" << contacto[i].GetID() << endl;
		agenda << "\tNombre:\t\t" << contacto[i].GetNom() << endl;
		agenda << "\tApellido:\t" << contacto[i].GetApe() << endl;
		agenda << "\tTelefono:\t" << contacto[i].GetNum() << endl;
		agenda << "-----------------------------------------" << endl;
	}
	agenda.close();
}
Agenda::~Agenda(){
	//cout << endl << "[!] Se ha borrado la agenda con sus " << ::ID << " contactos" << endl;
}
Programa::Programa(){
	this->Open();
}

void Programa::Open(){
	system("clear");
	cout << " Agenda v1 [By Dext3r copyright(c) 2016]" << endl;
	cout << "[*] Lista de contactos para manipular, guardar, y visualizar tus contactos" << endl ;
	cout << endl << endl << "Selecione una opcion: " << endl;
	cout << "\t1 - Visualizar lista de Contactos" << endl;
	cout << "\t2 - Crear nuevo contacto" << endl;
	cout << "\t3 - Buscar un contacto" << endl;
	cout << "\t4 - Modificar un contacto" << endl;
	cout << "\t5 - Importar Agenda desde archivo" << endl;
	cout << "\t6 - Guardar Agenda en texto plano" << endl;
	cout << "\t7 - Salir" << endl;
	this->Menu();
}

void Programa::Menu(){
	cout << "OPCION: ";
	int op;
	cin >> op;
	switch(op){
	case 1: agenda.Mostrar(); getchar(); Open();
	case 2: agenda.Crear(cont); Open();
	case 3: agenda.Buscar(); getchar(); Open();
	case 4: agenda.Modificar(); getchar(); Open();
	case 5: agenda.Cargar(); getchar(); Open();
	case 6:	agenda.Guardar(); getchar(); cout << "\n[*] Agenda Guardada en \'agenda.txt\'" << endl << endl; Open();
	case 7: exit(1); 
	default: Open();
	}
}
