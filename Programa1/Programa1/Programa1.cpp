// Programa1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class claseA
{
public:
	static int function(int param)
	{
		printf("Funcion 2: estatica en clase A\n");
		printf(" - Se mando el valor: %d\n", param);
		return param;
	}
};

class claseB
{

	public:
		static void calling_function(int (claseB::*&mem)(int))
		{
			mem = &function;
		}

	private:
		int function(int param)
		{
			printf("Funcion 3: privada en clase B\n");
			printf(" - Se mando el valor: %d\n", param);
			return param;
		}
};

static int function(int param)
{
	printf("Funcion 1: estatica de todo el programa\n");
	printf(" - Se mando el valor: %d\n", param);
	return param;
}

int main()
{

	int(*PrimerCallback) (int);
	int(*SegundoCallback) (int);
	int(claseB::*TercerCallback) (int);

	PrimerCallback = &function;
	PrimerCallback(10);

	SegundoCallback = &claseA::function;
	SegundoCallback(20);

	claseB::calling_function(TercerCallback);
	claseB *objeto = new claseB();
	(objeto->*TercerCallback)(30);
	
	
	
    return 0;
}


