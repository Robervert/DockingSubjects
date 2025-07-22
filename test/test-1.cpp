#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
{
	char inputone[200];
	char input1[200];
	printf("<\\Docking_Subjects:>_");
	scanf("%s", input1);
	while (1)
	{
		strncpy(inputone, input1, 200);
		if (strcmp(inputone, "a") == 0) //*****DOCKING_SUBJECTS***** ½Ó¿Ú
		{
			cout << "first!\n";
		}
		else if (strcmp(inputone, "b") == 0)
		{
			cout << "second!\n";
		}
		else
		{
			cout << "wrong\n";
		}
	}
	return 0;
}
