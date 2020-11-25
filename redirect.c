#include "header.h"
int check_redirection(char **args)
{
	for(int i=0;i<size1;i++)
	{
		// if(strcmp(args[i],">")==0 || strcmp(args[i],">>")==0 || strcmp(args[i],"<")==0)
		if(args[i][0]=='>' || args[i][0]=='<')
		{
			return 1;
		}
	}
	return 0;
}

int redirection(char **args)
{
	int f1=0,f2=0,f3=0,fl=0,fl2=0;
	for(int i=0;i<size1;i++)
	{
		if(strcmp(args[i],"<")==0)
		{
			f1=i;
			fl=1;
		}
		if(strcmp(args[i],">")==0)
		{
			f2=i;
		}
		if(strcmp(args[i],">>")==0)
		{
			f3=i;
			fl2=1;
		}
	}
	int ptr=100;
	char in[MAXL],out[MAXL];
	if(f1!=0)
	{
		ptr=f1;
		strcpy(in,args[f1+1]);
	}
	if(f2!=0 || f3!=0)
	{
		strcpy(out,args[f2+f3+1]);
		int lp = f2+f3;
		if(ptr>=lp)
		{
			ptr=f2+f3;
		}
	}
	args[ptr]=NULL;
	int ini,outi,fd[2];
	if(f1)
	{
		struct stat tmp;
		if(stat(in,&tmp)<0)
		{
			perror(in);
		}
		int v=0;
		ini=dup(0);
   		fd[0]=open(in,O_RDONLY,0644);
		dup2(fd[0],0);
	}
	fl++;
	if(f2 || f3)
	{
		outi=dup(1);
		int ll=1;
		if(f2)
	    {
	    	fl2=0;
	    	fd[1]=open(out,O_WRONLY | O_CREAT | O_TRUNC,0644);
	    }
		else
		{
			fl2=1;
	    	fd[1]=open(out,O_WRONLY | O_CREAT | O_APPEND,0644);
		}
		if(dup2(fd[1],ll)<0)
		{
			printf("Error: dup2 failed.\n");
			return 0;
		}
	}
	int temp = 0;
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		close(fd[1]);
		printf("Error: Fork error.\n");
		return temp;
	}
	if(pid==0)
	{
		if(execvp(args[0],args)<0)
		{
			printf("Error in executing: %s",args[0]);
			exit(0);
		}
	}
	else
	{
		wait(NULL);
		dup2(ini,0);
		dup2(outi,1);
	}
}