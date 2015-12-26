#include <iostream>
#include <stdlib.h>
using namespace std;

class Tablero{
	private:
	int filas;
	int columnas;
	public:
	Tablero(int fil, int col){
		this->filas = fil;
		this->columnas = col;
	}
	int **InitTablero(){
		int **matriz = (int**)malloc(this->filas*sizeof(int*));
		if(matriz == NULL){
			cout << "[!] No se pudo reservar Memoria!" << endl;
			exit(1);
		}
		int i,j;
		for(i=0;i<this->filas;i++){
			matriz[i] = (int*)malloc(this->columnas*sizeof(int));
			if(matriz[i] == NULL){
				cout << "[!] No se pudo reservar Memoria!" << endl;
				exit(1);
			}
		}
		for(i=0;i<(this->filas);i++){
			for(j=0;j<(this->columnas);j++){
				matriz[i][j] = (i+1)*(j+1);
			}
		}
		return matriz;
	}
	void ShowTablero(int **matriz){
		int i,j;
		for(i=0;i<(this->filas);i++){
			for(j=0;j<(this->columnas);j++){
				cout << matriz[i][j] << "\t";
			}
			cout << "\n\n\n";
		}
	}
};

int main(int argc , char **argv){
	Tablero Tab(8,8);
	int **tablero = Tab.InitTablero();
	Tab.ShowTablero(tablero);
	return 0;
}
