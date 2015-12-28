#include "header.h"

Fecha::Fecha(){  //constructor normal (en caso de usarlo, se predefine como fecha [27,12,2015] )
		this->day = 27;
		this->month = 12;
		this->year=  2015;
	};
Fecha::Fecha(int d,int m ,int y){ // constructor sobrecargado
		this->day = d;
		this->month = m;
		this->year = y;
	}
Fecha Fecha::operator+(Fecha x){
		Fecha Temp;
		int mes;
		Temp.day = this->day + x.day;
		Temp.year = this->year + x.year;
		mes = this->month;
		while(Temp.day > MaxDiaMes(mes,this->year)){
			Temp.day -= MaxDiaMes(mes,this->year);
			mes++;
			while(mes > 12){
				Temp.year++;
				mes -= 12;
			}
		}
		mes += x.month;
		while(mes > 12){
			mes -= 12;
			Temp.year++;
		}
		Temp.month = mes;
		return Temp;
	};
Fecha Fecha::operator++(int){ // postfijo
		Fecha Temp(*this);
		this->day++;
		if(this->day > MaxDiaMes(this->month,this->year)){
			this->day = 1;
			this->month++;
			if(this->month > 12){
				this->month -= 11;
				this->year++;
			}
		}
		return Temp;
	};
Fecha &Fecha::operator++(){ // prefijo
		Fecha Temp(*this);
		this->day++;
		if(this->day > MaxDiaMes(this->month,this->year)){
			this->day = 1;
			this->month++;
			if(this->month > 12){
				this->month -= 11;
				this->year++;
			}
		}
		return *this;
	};
ostream &operator<<(ostream &x,Fecha f){
		x << f.day << "/" << f.month << "/" << f.year;
		return x;
	};
istream &operator>>(istream &x,Fecha &f){
		x >> f.day;
		x.ignore();
		x >> f.month;
		x.ignore();
		x >> f.year;
		x.ignore();
		return x;
	};	
int Fecha::MaxDiaMes(int m, int a){ // revisamos si el parametro para saber si el mes es de 31 o 30, y en caso de febrero(2) revisamos si es bisiesto
		switch(m){
			case 1: 
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
					return 31;
					break;
			case 4:
			case 6:
			case 9:
			case 11:
					return 30;
					break;
			case 2:
					if(a%400 == 0){
						return 29;
					}
					else if (a%100 == 0){
						return 28;
					}
					else if (a%4 == 0){
						return 29;
					}
					else{
						return 28;
					}
			}
			return 0;
	};
void Fecha::AsignaFecha(int d,int m , int y){ // asignar fecha
		this->day = d;
		this->month = m;
		this->year = y;
	};
