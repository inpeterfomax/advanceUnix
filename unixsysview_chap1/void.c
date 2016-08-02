/*
 *void:no parameter.what need do is add void into a funciton definitation.
 *():means you can pass any parameter into it. but ,it's meaningless.
 */


#include<stdio.h>

static void sub_call( void )
{
	printf("%s %d\n",__FUNCTION__,__LINE__);
}

int main()
{
		int a = 10;
	sub_call();

	printf("%s %d\n",__FUNCTION__,__LINE__);

	sub_call(a);
	
	printf("%s %d\n",__FUNCTION__,__LINE__);

	return 0;
}
