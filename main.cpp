#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#include "List.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	List studentList;
	
	int counter = 0;
 
	char stayAlive;
	
	do
	{
		studentList.createStudent(counter);
		counter++;
		
		cout << "More data entry? \nY/y to continue, any key to abort."<<endl;
		cin >> stayAlive;
		
	} while (stayAlive == 'Y' || stayAlive == 'y');   
	
	studentList.traverse(); 
	
	cout << "Grade Average: " << studentList.gradesAverage();
	
	return 0;
}

