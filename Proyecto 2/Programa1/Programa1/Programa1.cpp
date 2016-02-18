// Programa1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>
<<<<<<< HEAD
#include <Windows.h>
=======
>>>>>>> refs/remotes/origin/master
using namespace std;

//Define size
//
#define v_size 10 //Tamaño del vector

//Define Process Control States
<<<<<<< HEAD
#define s_running 0 //En ejecucion
#define s_suspended 1 //Suspendido
#define s_blocked 2 //Bloqueado
#define s_ready 3 //Listo para la ejecucion
#define s_ready_and_suspend  4 //Listo y suspendido
#define s_blocked_and_suspend 5 //Bloqueado y suspendido
#define s_waiting 6 //En espera
#define s_done 7 //Terminado

//Define CPU states
#define available 8 //Espacio dispobible
#define not_available 9 //Ya no hay espacio
#define out_of_range 10 //fuera del limite del espacio
#define s_delete 11 //Terminado

string ProcessName[12] = {"Corriendo","Suspendido","Bloqueado", "Listo","Listo y Suspendido","Bloqueado y Suspendido", "En Espera", "Terminado",
"Disponible","No Disponible", "Fuera de Limite", "Eliminado"
};
=======
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
>>>>>>> refs/remotes/origin/master


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
<<<<<<< HEAD
		int ID;  
		int state;
	public:
		int ProcessState; //Describe en que proceso se encuentra el PCB	
		int* puntero;	// Almacena el valor de la direccion del callback a realizar.
				// Tiene el tipo de estado actualmente en el CPU.
		PCB* siguiente; // Apuntador asia siguiente PCB


		void setState(int state) {
			this->state = state;
		}

		void setProcess(int pross) {
			this->ProcessState = pross;
		}
=======
		int ID;
		int ProcessState;

	public:
		int* puntero;
		int state;
>>>>>>> refs/remotes/origin/master

	//Función que retorna el ID
	int returnID()
	{
		return ID;
	}

	int returnState() {
<<<<<<< HEAD
		return state; //devuelve estado en el CPU
	}

	int returnProcessState() {
		return ProcessState; //Devuelve estado del proceso.
	}

	PCB* getNext(){
		return siguiente;
=======
		return state;
	}

	int returnProcessState() {
		return ProcessState;
>>>>>>> refs/remotes/origin/master
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

<<<<<<< HEAD
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
				if (Aux == Aux->siguiente) {					
					
					
					actual->ProcessState = s_delete;
					cout << "El Estado del PCB es: " + ProcessName[actual->returnProcessState()] << endl;
					cout << "Apache una tecla para terminar proceso" << endl;
					getchar(); 
					actual = NULL;
				}
				else
				{
					actual->ProcessState = s_delete;
					cout << "El Estado del PCB es: " + ProcessName[actual->returnProcessState()] << endl;
					cout << "Apache una tecla para continuar con el otro proceso proceso" << endl;
					getchar();
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
=======
>>>>>>> refs/remotes/origin/master

//-----------------------Clase-Kernel-----------------------
class kernel {
	private:
<<<<<<< HEAD
		int PCB_ID;

		#pragma region Métodos privados

		//Establece los estados segun su ejecucion.
		void setProcessStates(PCB *actPCB, int state,int delay) {
			actPCB->setProcess(state);
			cout<< "Su estado actual es: " + ProcessName[actPCB->returnProcessState()]<<endl;
			Sleep(delay);
			//https://ccodigo.wordpress.com/tag/time/
		}
		
		//Ejecuta la ejecucion individual del PCB
		void runFunction(PCB *actPCB)
		{
			//Inicia Espera para ejecutar
			setProcessStates(actPCB, s_waiting,3000);			
			
			//Inicia proceso de ejecucion
			setProcessStates(actPCB, s_running,2000);
			int *puntero = actPCB->puntero;
			int(*callback) (int);
			printf("El PCB ejecutado fue el numero %d\n", actPCB->returnID());
			callback = (int(*)(int))*(&puntero);
			callback(1); //Ejecuta función		

			//Establece el final de la ejecucion
			setProcessStates(actPCB, s_done,2000);
						
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
=======

		#pragma region Métodos privados
		void initializateArray()
		{
			for (int i = 0; i < v_size; i++)
				if (pcbList[i] != NULL)
					pcbList[i] = NULL;
		}

		//Función que retorna primera celda disponible
		int firstAvailable()
		{
			int cont = 0;
			while (cont < v_size)
			{
				if (pcbList[cont] == NULL)
					return cont; else
					cont++;
			}
		}

		//Método que ejecuta PCB específico
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
			
			printf("\n");
		}
		#pragma endregion

	public:
		PCB *pcbList[v_size]; //Vector de 10 posiciones
		int PCB_count;

		#pragma region Constructor y Destructores

			//Constructor del kernel
			kernel()
			{
				PCB_count = 0;
				initializateArray(); //Vuelve todo NULL
>>>>>>> refs/remotes/origin/master
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
<<<<<<< HEAD
				Método que agrega un PCB a lista circular.
			*/
			void addPCB(int *callback)
			{
				if (PCB_count < v_size)
				{

					PCB_list->insertar(new PCB(PCB_ID, available, callback)); //Agrega PCB a lista

					//Permite decir que se ingreso y su estado actual en el CPU
					//cout<<"El estado en el CPU actual es: "  +ProcessName[PCB_list->tomaPCB()->returnState()]<<endl;
					

					PCB_count++;
					PCB_ID++;
=======
			Método que agrega un puntero y lo convierte
			en PCB. Luego, este lo ingresa en la lista en
			la primera posición disponible.
			*/
			void addToAvailable(int *callback)
			{
				if (PCB_count <= 10)
				{
					int first = firstAvailable() + 1; //Toma 1er espacio NULL disponible
					PCB *newPCB = new PCB(first, not_available, callback); //Crea PCB
					pcbList[first - 1] = newPCB; //Lo agrega a lista
					PCB_count++;
>>>>>>> refs/remotes/origin/master
				}
				else
					printf("Error. No se permiten mas procesos");
			}
<<<<<<< HEAD
=======

			/*
			Método que agrega un puntero y lo convierte
			en PCB. Luego, este lo ingresa en la lista en
			la posición index.
			*/
			void addToIndex(int *callback, int index)
			{
				if (index >= 0 && index < v_size)
				{
					if (pcbList[index] == NULL)
					{
						PCB *newPCB = new PCB(index + 1,not_available, callback); //Crea PCB
						pcbList[index] = newPCB; //Lo agrega a lista
						PCB_count++;
					}
					else
						printf("Error. La posicion %d ya esta ocupada", index);
				}
				else
					printf("Error. Indice no esta dentro del rango [0..%d]\n", v_size);
			}
>>>>>>> refs/remotes/origin/master
		#pragma endregion

		#pragma region Métodos para quitar PCB

<<<<<<< HEAD
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
=======
			/*
			Método que borra un PCB en una posición
			específica.
			*/
			void deletePCB(int index)
			{
				if (index >= 0 && index < v_size)
				{
					if (pcbList[index] != NULL) //Si es != null, borra PCB
					{
						PCB_count--;
						pcbList[index]->~PCB(); //Utiliza destructor
						pcbList[index] = NULL; //Es necesario?
					}
				}
				else
					printf("Error. Índice no está dentro del rango [0..%d]\n", v_size);;
>>>>>>> refs/remotes/origin/master
			}

			/*
			Método que recorre lista de PCB y los
			elimina todos.
			*/
			void delete_ALL_PCB()
			{
<<<<<<< HEAD
				PCB_list->eliminar_todos();
=======
				for (int i = 0; i < v_size; i++)
					deletePCB(i);
>>>>>>> refs/remotes/origin/master
			}

		#pragma endregion

		#pragma region Métodos para correr PCB
			
			/*
<<<<<<< HEAD
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
=======
				Método que corre un PCB en una posición index.
			*/
			void runFunction_Index(int index)
			{
				if (index >= 0 && index < v_size)
				{
					PCB *act = pcbList[index];
					if (act != NULL)
						
						runFunction(act); //Corre PCB
						
				}
				else
					printf("Error. indice no esta dentro del rango [0..%d]\n", v_size);
			}

			/*
				Método que corre todos los PCB en lista
			*/
			void runAllFunctions()
			{
				for (int i = 0; i < PCB_count; i++)
				{
					runFunction_Index(i);
				}

				for (int j = 0; j < PCB_count; j++)
				{
					deletePCB(j); //Borra PCB
>>>>>>> refs/remotes/origin/master
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

<<<<<<< HEAD
	newKernel->addPCB((int*)&function);
	newKernel->addPCB((int*)&claseA::function);
	newKernel->addPCB((int*)privado);
	newKernel->runAllPCB();
	//newKernel->~kernel();
=======
	newKernel->addToAvailable((int*)&function);
	newKernel->addToAvailable((int*)&claseA::function);
	newKernel->addToAvailable((int*)privado);
	newKernel->runAllFunctions();
	newKernel->~kernel();
>>>>>>> refs/remotes/origin/master
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


