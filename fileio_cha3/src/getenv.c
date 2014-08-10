#include <stdlib.h>
#include <string.h>

int main()
{
	char *env = NULL;

	env = getenv("HOME");

	printf("%s\n",env);

	return 0;

}
