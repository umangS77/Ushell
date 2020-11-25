#include "header.h"

void checkbg()
{
	int status;
	pid_t pid;
	int ptr=0,j=0;
	while((pid=waitpid(-1,&status,WNOHANG | WUNTRACED))>0)
	{
		if(WIFEXITED(status))
		{
			int t=1,i=0;
			for(;i<jobsize;i++)
			{
				if(jobs[i].pid==pid && jobs[i].status)
				{
					jobs[i].status=0;
					// printf("home= %s, path= %s",home,path);
					// strcpy(home,path);
					jobs[i].pid=pid;
					fprintf(stderr,"\nProcess %s with pid %d exited normally.\n",jobs[i].com,pid);
					prompt(path,home,prevprompt,prevdir);
					break;
				}
			}
		}
		if(WIFSIGNALED(status))
		{
			int t=1,i=0;
			for(;i<jobsize;i++)
			{
				// printf("home---> %s\n",home);
				if(jobs[i].pid=pid && jobs[i].status)
				{
					jobs[i].status=0;
					// printf("home= %s, path= %s\n",home,path);
					// strcpy(home,path);
					// prompt(path,home,prevprompt,prevdir);
					jobs[i].pid=pid;
					fprintf(stderr,"Process %s with pid %d exited abnormally.\n",jobs[i].com,pid);
					break;
				}
			}
		}
	}
	for(;j<jobsize;j++)
	{
		if(jobs[j].status)
		{
			jobs[ptr++]=jobs[j];
		}
	}
	jobsize=ptr;
}