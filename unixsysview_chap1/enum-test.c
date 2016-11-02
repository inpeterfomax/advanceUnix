#include<stdio.h>

enum u{
	FT_1,
	FT_2,
	FT_3
};

#define FT_1 FT_1

int main()
{
	printf("FT_1 : %d \n",FT_1); return 0;
}
