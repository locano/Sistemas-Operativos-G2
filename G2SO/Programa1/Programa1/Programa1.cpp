// Programa1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// ***** EJERCICIO 1 - Imprimir direcciones de segmentos *****
int temp_data = 100;
static int temp_bss;

void imprimirDireccionesSegmentos(void)
{
	int varLocal = 100;
	int *dirCodeSegment = (int*)&imprimirDireccionesSegmentos; //Code Segment: Primera función
	int *dirDataSegment = &temp_data; //Data Segment: Primera variable
	int *dirBSS = &temp_bss; //BSS Segment: Primera variable no inicializada
	int *dirStackSegment = &varLocal; //Stack Segment: Primera variable local
	printf("Direcciones de los segmentos de memoria:");
	printf("\n\tCode Segment: %p", dirCodeSegment);
	printf("\n\tData Segment: %p", dirDataSegment);
	printf("\n\tBSS: %p", dirBSS);
	printf("\n\tStack Segment: %p", dirStackSegment);
}

// ***** PROYECTO 1 - Callbacks *****
//Función estática global
static int funcion1(int param)
{
	printf("\n\t Función 1: %i", param);
	return 1;
}

//Clase con función pública
class clase1
{
public:
	static int funcion2(int param);
};

class clase2
{
public:
	static void calling_function(int(*&mem)(int))
	{
		mem = &funcion3;
	}
private:
	static int funcion3(int param);
};

int clase1::funcion2(int param)
{
	printf("\n\t Función 2: %i", param);
	return 2;
}

int clase2::funcion3(int param)
{
	printf("\n\t Función 3: %i", param);
	return 3;
}

int main()
{
	// ***** EJERCICIO 1 *****
	//imprimirDireccionesSegmentos(); //Imprime las direcciones de los segmentos de memoria

	// ***** PROYECTO 1 *****
	int(*cb1)(int) = funcion1;
	int(*cb2)(int) = clase1::funcion2;
	int(*cb3)(int);
	clase2::calling_function(cb3);

	cb1(10);
	cb2(20);
	cb3(30);

	getchar();
	return 0;
}


