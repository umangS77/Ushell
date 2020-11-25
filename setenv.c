#include "header.h"

void execute_setenv(char **args)
{
	if(size1 <2 || size1>3)
	{
		printf("Error: Invalid input\n");
	}
	else if(size1==2)
	{
		args[2]="";
	}
	if(setenv(args[1],args[2],1)!=0)
	{
		printf("Error: Unable to set value.\n");
	}
	return;
}