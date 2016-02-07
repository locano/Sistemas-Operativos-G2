// CallbacksPQ.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class claseA
{
	public:
		static int f2(int param)
		{
			printf("Funcion 2: Estatica en clase A - %d\n", param);
			return param;
		}
};

class claseB
{
	public:
		static void calling_function(int (claseB::*&fAddress)(int))
		{
			fAddress = &f3;
		}

	private:
		int f3(int param)
		{
			printf("Funcion 3: Privada en clase B - %d\n", param);
			return param;
		}
};

static int f1(int param) {
	printf("Funcion 1: Estatica de todo el programa - %d\n", param);
	return param;
}

int main()
{
	int(*PrimerCallback) (int);
	int(*SegundoCallback) (int);
	int(claseB::*TercerCallback) (int);
	
	PrimerCallback = f1;
	SegundoCallback = claseA::f2;

	PrimerCallback(10);
	SegundoCallback(20);
	
	claseB::calling_function(TercerCallback);
	claseB *objeto = new claseB();
	(objeto->*TercerCallback)(30);

	getchar();
    return 0;
}

