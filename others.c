#include"header.h"
void execute_others(char **args,int t)
{
	pid_t pid;
	args[size1-t]='\0';
	int p=0;
	int status;
	if((pid=fork())<0)
	{
		printf("ERROR: Forking failed\n");
		return ;
	}
	p++;
	if(pid==0)
	{
		setpgid(0,0);
		if(execvp(*args,args)<0)
		{
			printf("ERROR: Invalid Command\n");
			exit(0);
		}
		exit(0);
	}
	else
	{
		p=1;
		jobs[jobsize].jobid=jobsize+1;
		jobs[jobsize].status=1;
		jobs[jobsize].pid=pid;
		strcpy(jobs[jobsize].com,args[0]);
		jobsize++;
		if(t)
		{
            signal(SIGCHLD,checkbg);
		}
		else
		{
			int stat2;
			tcsetpgrp(0,pid);
			waitpid(pid,&status,WUNTRACED);
			signal(SIGTTOU,SIG_IGN);
			tcsetpgrp(0,getpid());
			signal(SIGTTOU,SIG_DFL);
		}
	}
}