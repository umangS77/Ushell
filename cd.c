#include "header.h"

void execute_cd(char **c, char* prevdir)
{
	if(strcmp(c[1],"")==0 || strcmp(c[1],".")==0)
	{
		return;
	}
	if(strcmp(c[1],"-") == 0)
	{
		printf("%s\n",prevdir);
		if(prevdir[0]=='~')
		{
			char tempdir[MIDL];
			strcpy(tempdir,home);
			lli l = strlen(tempdir);
			for(lli i=1;i<strlen(prevdir);i++)
				tempdir[l++] = prevdir[i];
			strcpy(prevdir,tempdir);
		}

		int f=chdir(prevdir);
		if(f<0)
		{
			perror(prevdir);
		}
		return;
	}
	if(strcmp(c[1],"~")==0)
	{
		strcpy(c[1],home);
	}
	int p=chdir(c[1]),k;
	if(p<0)
	{
		printf("Error: %s directory does not exist.\n",c[1]);
	}
	return;
}