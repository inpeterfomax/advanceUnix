#include"head.h"

int main(int argc,char*argv[])
{
	static const int a = 5;
	static char chararry[]="this is the initialization for the static char chararry[]";
	puts(chararry);
	static char chararryagain[]="this is the initialization + " " + for the static char arry again" " " "+" "again again again " "helo again ,and i do not know this is happening!";
	puts(chararryagain);
//	a =4;
	static char charmore[]={'a','b','c','d','e'};
	
	puts(charmore);
	
	unlink("./test.txt");

	return a;
	
}

