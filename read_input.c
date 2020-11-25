#include"header.h"

char tempstr[MAXL];

void read_inp(char** c,char home[])
{
	char inp[MAXL];
	if(fgets(inp,MAXL,stdin) == NULL)
	{
		execute_overkill(0);
		printf("\n----------------------------------------------------------------\n\n");
		exit(0);
	}
	inp[strlen(inp)-1]='\0';
	strcpy(tempstr,inp);
	char *tokens=strtok(inp,";");
	int i=0;
	while(tokens!=NULL)
	{
		c[i]=tokens;
		add_history(c[i],home);
		i++;
		tokens=strtok(NULL,";");
	}
	size=i;
	c[size]=NULL;
}

void trim_inp(char *inp,char **c)
{
	int i=0;
	char delim[]=" \t";
	strcpy(tempstr,inp);
	char *tokens=strtok(inp,delim);
	while(tokens!=NULL)
	{
		c[i++]=tokens;
		tokens=strtok(NULL,delim);
	}
	size1=i;
	c[size1]=NULL;
}