#include "header.h"

void execute_kjob(char **args)
{
	if(size1!=3)
	{
		printf("Error: Invalid input\n");
		return ;
	}
	int i;
    bool f=true;
	for(i=0;i<jobsize;i++)
	{
		if(jobs[i].jobid==atoi(args[1]))
		{
			f=false;
			break;
		}
	}
	if(f)
	{
		printf("Error: Invalid Jobid.\nProcess with Jobid %s doesn't exist\n",args[1]);
		return ;
	}
	else if(kill(jobs[i].pid,atoi(args[2]))<0)
	{
		perror("kill");
	}
	sleep(1);
    return;
}