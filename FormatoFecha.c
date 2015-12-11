#include <time.h>
#include <stdio.h>

int main()
{
  time_t t;
  struct tm *tm;
  char fechayhora[100];

  t=time(NULL);
  tm=localtime(&t);
  strftime(fechayhora, 100, "%d/%m/%Y -> %I:%M:%S", tm);
  printf ("Hoy es: %s\n", fechayhora);
}
/*
La forma de utilizar strftime() es pasando los siguientes parámetros:

Un array de char o char* donde almacenaremos la cadena de caracteres resultante
El tamaño máximo de caracteres que podemos ocupar, es decir, el tamaño reservado para la variable anterior
El formato en el que queremos presentar los datos, con algunas palabras clave que indicarán dónde va cada uno de los datos, los más importantes son:
%s : Número de segundos desde la época: 1 de Enero del 1970 a las 00:00
%d : Día del mes (del 01 al 31)
%m : Mes (del 01 al 12)
%Y : Año (con 4 cifras. Ej: 2012)
%y : Año (con 2 cifras. Ej : 12)
%H : Horas en formato 24h (de 00 a 23)
%I : Horas en formato 12h) (de 01 a 12)
%M : Minutos (de 00 a 59)
%S : Segundos (de 00 a 59)
%z : Huso horario (diferencia horaria con respecto a GMT)
%u : Día de la semana (del 1 al 7 donde 1 es Lunes)
%w : Día de la semana (del 0 al 6 donde 0 es Domingo)
Hay muchos más, para obtener la lista completa, utilizad: “$ man strftime” o “$ man date” en la línea de comandos
Puntero a struct tm de donde sacamos la información (debemos llamar siempre previamente a la función localtime()
*/
