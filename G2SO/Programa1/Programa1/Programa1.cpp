// Programa1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int temp_data = 100;
static int temp_bss;

void print_addr(void)
{
	int local_var = 100;
	
	int *code_segment_address = (int*)&print_addr;
	int *data_segment_address = &temp_data;
	int *bss_address = &temp_bss;
	int *stack_segment_address = &local_var;
	printf("\nAddress of various segments:");
	printf("\n\tCode Segment : %p", code_segment_address);
	printf("\n\tData Segment : %p", data_segment_address);
	printf("\n\tBSS : %p", bss_address);
}

int main()
{
	print_addr();
	getchar();
	return 0;
}


