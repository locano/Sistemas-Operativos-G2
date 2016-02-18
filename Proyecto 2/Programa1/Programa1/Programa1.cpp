// Programa1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//Define size
//
#define v_size 10 //Tamaño del vector

//Define Process Control States
#define s_running 1 //En ejecucion
#define s_suspended 2 //Suspendido
#define s_blocked 3 //Bloqueado
#define s_ready 4 //Listo para la ejecucion
#define s_ready_and_suspend  5 //Listo y suspendido
#define s_blocked_and_suspend 6 //Bloqueado y suspendido
#define s_waiting 7 //En espera
#define s_done 8 //Terminado


//Define CPU states
#define available 1 //Espacio dispobible
#define not_available 2 //Y ano hay espacio
#define out_of_range 3 //fuera del limite del espacio


//------------------------Funciones-------------------------
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
	static void calling_function(int(*&mem)(int))
	{
		mem = &function;
	}

private:
	static int function(int param)
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

//----------------------------------------------------------


//------------------------Clase-PCB-------------------------
class PCB {
	private:
		int ID;
		int ProcessState;

	public:
		int* puntero;
		int state;
		PCB* siguiente;

	//Función que retorna el ID
	int returnID()
	{
		return ID;
	}

	int returnState() {
		return state;
	}

	int returnProcessState() {
		return ProcessState;
	}

	PCB* getNext(){
		return siguiente;
	}

	#pragma region Constructor y Destructor
	//Constructor para funciones 1 y 2
	PCB(int newId, int newstate ,int* pointer)
	{
		ID = newId;
		state = newstate;
		puntero = pointer;
	}

	//"Desctructor"
	~PCB()
	{
		ID = 0;
		state = available;
		puntero = NULL;
	}
	#pragma endregion
};
//----------------------------------------------------------

//-----------------------Lista circular--------------------
class lista{
	private:
		PCB* actual;
	
	public:
		lista(){
			actual = NULL;
		}
	
		void insertar(PCB* nodo){
			if (actual == NULL)
				actual = nodo;
			else nodo->siguiente = actual->siguiente;

			actual->siguiente = nodo;
		}

		void eliminar(int contPCB, int ID){
			PCB* Aux = actual, *Anterior = Aux; int iterador = 0;
			bool salir = false;
			while (iterador < contPCB && !salir)
			{
				Anterior = Aux;
				Aux = Aux->siguiente;
				if (Aux->returnID() == ID)
					salir = true;
				iterador++;
			}

			if (salir) //Encontró el PCB
			{
				if (Aux == Aux->siguiente)
					actual = NULL;
				else
				{
					Anterior->siguiente = Aux->siguiente;
					actual = Anterior;
				}
			}
			else
				printf("El PCB %d no ha sido encontrado.", ID);
		}

	void eliminar_todos(){
		actual = NULL;
	}

	PCB* tomaPCB()
	{
		return actual;
	}
};

//----------------------------------------------------------

//-----------------------Clase-Kernel-----------------------
class kernel {
	private:
		int PCB_ID;

		#pragma region Métodos privados

		void runFunction(PCB *actPCB)
		{
			actPCB->state = s_waiting;
			printf("Su estado actual es %d\n", actPCB->returnState()); 			
			getchar();
			int *puntero = actPCB->puntero;
			actPCB->state = s_running;
			int(*callback) (int);
			printf("El PCB ejecutado fue el numero %d\n", actPCB->returnID());
			printf("Su estado actual es %d\n", actPCB->returnState());
			callback = (int(*)(int))*(&puntero);
			callback(1); //Ejecuta función			
			getchar();
			actPCB->state = s_done;
			printf("Su estado actual es %d\n", actPCB->returnState());
			getchar();
			
			//Borrarlo después de correrlo
			deletePCB(actPCB->returnID()); //Borra PCB
			//-----------------------------

			printf("\n");
		}
		
		#pragma endregion

	public:
		int PCB_count;
		lista *PCB_list;
		#pragma region Constructor y Destructores

			//Constructor del kernel
			kernel()
			{
				PCB_count = 0;
				PCB_list = new lista();
				PCB_ID = 1;
			}

			//"Destructor del kernel"
			~kernel()
			{
				delete_ALL_PCB(); //Borra todos los PCB
				PCB_count = 0;
			}

		#pragma endregion

		#pragma region Métodos para agregar PCB

			/*
				Método que agrega un PCB a lista circular.
			*/
			void addPCB(int *callback)
			{
				if (PCB_count < v_size)
				{
					PCB_list->insertar(new PCB(PCB_ID, not_available, callback)); //Agrega PCB a lista
					PCB_count++;
					PCB_ID++;
				}
				else
					printf("Error. No se permiten mas procesos");
			}
		#pragma endregion

		#pragma region Métodos para quitar PCB

			void deletePCB(int ID)
			{
				bool founded = false;
				int cont = 0;
				PCB *actPCB = NULL;
				while (!founded && cont < PCB_count) //Busca el PCB. Al encontrarlo se sale del ciclo
				{
					actPCB = PCB_list->tomaPCB();
					if (actPCB->returnID() == ID) //Si es igual al que se está buscando...
						founded = true; else
						cont++;
				}
				if (founded)
					PCB_list->eliminar(PCB_count, ID); else
					printf("El PCB %d no ha sido encontrado\n", ID);
			}

			/*
			Método que recorre lista de PCB y los
			elimina todos.
			*/
			void delete_ALL_PCB()
			{
				PCB_list->eliminar_todos();
			}

		#pragma endregion

		#pragma region Métodos para correr PCB
			
			/*
			Método que busca un PCB por ID. Si lo encuentra
			lo ejecuta. Si no,
			*/
			void runPCB(int ID)
			{
				bool founded = false;
				int cont = 0;
				PCB *actPCB = NULL;
				while (!founded && cont < PCB_count) //Busca el PCB. Al encontrarlo se sale del ciclo
				{
					actPCB = PCB_list->tomaPCB();
					if (actPCB->returnID() == ID) //Si es igual al que se está buscando...
						founded = true; else
						cont++;
				}
				if (founded) //Si encuentra el PCB lo ejecuta
					runFunction(actPCB); //Corre PCB
				else
					printf("El PCB %d no ha sido encontrado\n", ID);
			}

			/*
			Método que corre todos los PCB
			*/
			void runAllPCB()
			{
				PCB *actPCB;
				for (int i = 0; i < PCB_count; i++)
				{
					actPCB = PCB_list->tomaPCB();
					runFunction(actPCB);
				}
			}

		#pragma endregion
};
//----------------------------------------------------------

int main()
{
	#pragma region Proyecto 2
	int(*privado)(int);
	claseB::calling_function(privado);
	kernel *newKernel = new kernel();

	newKernel->addPCB((int*)&function);
	newKernel->addPCB((int*)&claseA::function);
	newKernel->addPCB((int*)privado);
	newKernel->runAllPCB();
	//newKernel->~kernel();
	#pragma endregion

	#pragma region Proyecto 1
	/*int *hola;
	int(*PrimerCallback) (int);
	PCB *elpcb = new PCB(10, PrimerCallback);
	int(*SegundoCallback) (int);
	int(claseB::*TercerCallback) (int);

	PrimerCallback = &function;
	PrimerCallback(10);

	SegundoCallback = &claseA::function;
	SegundoCallback(20);

	claseB::calling_function(TercerCallback);
	claseB *objeto = new claseB();
	(objeto->*TercerCallback)(30);

	initializateArray(vector);

	setPosition(&function,vector);
	setPosition(&claseA::function,vector);

	recorreVector(vector);
	//setPosition(&function);
	//PrimerCallback = (int(*)(int))vector[0];
	//PrimerCallback(11);
	*/
	#pragma endregion

	return 0;
}


