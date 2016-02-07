//Comments
/*Multiline Comments*/
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

//static type function_name (type parameter)
static int function1(int parameter1) {
	cout << "Function # = 1 " << "-- Parameter: " << parameter1 << endl;
	return 1;
}  

class Class_1 {
public:
  static int function2(int parameter2) {
		cout << "Function # = 2 " << "-- Parameter: " << parameter2 << endl;
		return 2;
	}
};

class Class_2 {
		
public:
	 static void  getfunction3( int (Class_2::*&parameter) (int)) {	
		 parameter = &function3;
	}

private:
	 int function3(int parameter3) {  
		cout << "Function # = 3 " << "-- Parameter: " << parameter3 << endl;
		return 3;
	}

};


/* From this part start the second proyect were we can see the implementation of PCB*/

void *vector[10]; //Array of 10 pointers

void initializateArray(void *theArray[])
{
	for (int i = 0; i < 10; i++)
	{
		theArray[i] = NULL;
	}
}

void setPosition(int(*param)(int), void *theArray[]) {

	for (int i = 0; i < 10; i++)
	{
		if (theArray[i] == NULL) {
			theArray[i] = param;
			return;
		}
	}
}

void searchInVector(void *theArray[])
{
	int(*auxCallback) (int);
	for (int i = 0; i < 10; i++)
	{
		if (theArray[i] != NULL)
		{
			auxCallback = (int(*)(int))theArray[i];
			auxCallback((i + 1) * 10);
			theArray[i] = NULL;
		}
	}
}

void PCB_Calling(int(*Callback1) (int), int(*Callback2) (int), int(Class_2::*Callback3) (int)){

	initializateArray(vector);
	setPosition(Callback1, vector);
	setPosition(Callback2, vector);
	//setPosition(Callback3, vector);
	searchInVector(vector);
}

int main() {

	//int random = (rand() % 100) + 1; //Ramdom from 0-101;

	//Method1 create the callbacks by the specific type then you create the reference on the main
	int(*Callback1) (int);  //Callback pointer to any function of int type
	int(*Callback2) (int);
	int(Class_2::*Callback3) (int) ;

	cout << "Method 1" << endl;
	//Method1
	Callback1 = &function1;
	Callback2 = &Class_1::function2;	
	Class_2::getfunction3(Callback3);
	Class_2 *object = new Class_2();
	(object->*Callback3)(05);

	PCB_Calling(Callback1, Callback2, Callback3);


	string lines;
	getline(cin, lines );
	return 0;
}



