#include "header.h"
void execute_bg(char **args)
{
	int flag,i;
	if(size1!=2)
	{
		printf("Error: Invalid input\n");
		return ;
	}
	pid_t p=atoi(args[1]);
	flag=0;
	for(i=0;i<jobsize;i++)
	{
		if(jobs[i].jobid==p)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		// printf("This process is running now\nName = %s\nJobid = %d\nPid = %d\n",jobs[i].com,p,jobs[i].pid);
		printf("Error: Invalid Jobid.\nProcess with Jobid %d doesn't exist\n",p);
	}
	else
	{
		int status;
		kill(jobs[i].pid,SIGCONT);
	}
}