#include"header.h"

int check_pipe(char **args)
{
	int r=0,ar[MAXL],i;
	for(i=0;i<size1;i++)
	{
		if(strcmp(args[i],"|")==0)
		{
			ar[r]=i;
			r++;
		}
	}
	if(r>0)
	{
		if(ar[0]==0 || ar[r-1]==size1-1)
		{
			return -1;
		}
	}
	i=1;
	while(i<r)
	{
		if(ar[i]-ar[i-1]==1)
		{
			return -1;
		}
		i++;
	}
	return (r>0);
}

void piping(char *args,char *path,char *path2,char *home,char *prevdir)
{
	char *comm[MAXL],*token=strtok(args,"|");
	int pipenos=0,i;
	int stdin=dup(0),stdou=dup(1);
	int in1=dup(stdin),out1;
	while(token!=NULL)
	{
		comm[pipenos++]=token;
		token=strtok(NULL,"|");
	}
	
	for(i=0;i<pipenos-1;i++)
	{
		if(dup2(in1,0)!=0)
		{
			printf("Error: dup2 Failed\n");
		}
		int tp=0;
		close(in1);
		int inter[2];
		if(pipe(inter)<0)
		{
			printf("Error: Pipes Failed\n");
		}
		out1=inter[1];
		in1=inter[tp];

		if(dup2(out1,1)!=1)
		{
			printf("Error: dup2 Failed\n");
		}
		close(out1);
		
		char* tmp[MIDL];
		trim_inp(comm[i],tmp);
		executecommand(tmp,path,path2,home,prevdir);
		tp=1;
	}

	if(dup2(in1,0)!=0)
	{
		printf("Error: dup2 Failed\n");
	}

	close(in1);
	out1=dup(stdou);
	int zz=1;
	if(dup2(out1,zz)!=1)
	{
		printf("Error: dup2 Failed\n");
	}
	close(out1);
	char* temp[MIDL];
	trim_inp(comm[pipenos-1],temp);
	executecommand(temp,path,path2,home,prevdir);

	dup2(stdin,0);
	dup2(stdou,1);
	return;
}