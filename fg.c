#include "header.h"

void execute_fg(char **args)
{
	int flag=0,i;
	if(size1!=2)
	{
		printf("Error: Invalid input\n");
		return ;
	}
	pid_t p=atoi(args[1]);
	int tp;
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
		printf("Error: Invalid Jobid.\t\nProcess with Jobid %d doesn't exist\n",p);
	}
	else
	{
		int status,k=0;
		p=jobs[i].pid;
		kill(p,SIGCONT);
		tcsetpgrp(k,p);
		waitpid(p,&status,WUNTRACED);
		signal(SIGTTOU,SIG_IGN);
		tcsetpgrp(k,getpid());
		signal(SIGTTOU,SIG_DFL);
	}
}
