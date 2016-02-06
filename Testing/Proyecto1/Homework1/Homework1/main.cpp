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
	static int  getfunction3(int parameter) {	
		 return function3(parameter);
	}

private:
	static int function3(int parameter3) {  
		cout << "Function # = 3 " << "-- Parameter: " << parameter3 << endl;
		return 3;
	}

};

//Ask a number for the function3
string asknumber() {
	cout << "Type a number" << endl;
	string line;
	getline(cin, line);
	return line;

}

//METHOD1, allows you to create the callbacks as parameters and recive de & of the functions
void Callbacks(int(*Callback1) (int), int(*Callback2) (int), int(*Callback3) (int)) {
	Callback1(5);
	Callback2(6);
	string line = asknumber();
	int number =stoi(line);
	Callback3(number);

}



int main() {

	//int random = (rand() % 100) + 1; //Ramdom from 0-101;

	//Method2 create the callbacks by the specific type then you create the reference on the main
	int(*Callback1) (int);  //Callback pointer to any function of int type
	int(*Callback2) (int);
	int(*Callback3) (int) ;
		
	cout << "Method 1" << endl;
	//Method1
//	Callbacks(&function1, &Class_1::function2, &Class_2::getfunction3);

	cout << "Method 2" << endl;
	//Method2
	Callback1 = &function1;
	Callback2 = &Class_1::function2;
	Callback3 = &Class_2::getfunction3;
	Callback1(10);
	Callback2(11);
	string line = asknumber();
	Callback3(stoi(line));

	string lines;
	getline(cin, line );
	return 0;
}



