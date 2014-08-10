/*rename the original type to a new name*/

#include<stdio.h>
#include<unistd.h>

typedef struct {
	int a;
	int b;
	char c;
}student;
typedef int* Mying ; 
typedef char* Mychar;

int main()
{
	student f = {
		.a = 10,
		.b = 12,
		.c = 'c',
	};

	student g = {12,12,'d'}; 

	student y[4] = {
		{11,11,'c'},
		{32,32,'g'},
		{32,32,'g'},
		{32,32,'g'},
	};
	
	Mying x = &(f.b); 
	
		
	return 0;
}
