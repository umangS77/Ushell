#include "header.h"

void execute_unsetenv(char **args)
{
	if(size1!=2)
	{
		printf("Error: Invalid input\n");
	}
	else if(unsetenv(args[1])!=0)
	{
		printf("Error: Unable to unset value.\n");
	}
	return;
}