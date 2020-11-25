#include "header.h"


int jobsize=0;
char tmp[MAXL];

int main(int argc,char* argv[])
{
	signal(SIGINT,NULL);
	signal(SIGTSTP,NULL);
	char home[MIDL];
	char prevdir[MIDL];
	char prevprompt[MIDL];
	char* inp[100];
	char* inp1[100];
	getcwd(home , MIDL);
	printf("\n----------------------------------------------------------------\n");
	printf("Current Directory: %s\n",home);
	printf("----------------------------------------------------------------\n\n");
	strcpy(origin_home,home);
	strcpy(prevdir,home);
	while(1)
	{
		for(int i=0;i<100;i++)
		{
			inp[i]="";
		}
		size=0;
		prompt(path,home,prevprompt,prevdir);
		strcpy(path2,path);
		read_inp(inp1,home); // take input and store ";" separated token in c[]
		checkbg(); // check background
		for(int i=0;i<size;i++)
		{
			strcpy(tmp,inp1[i]);
			trim_inp(inp1[i],inp);
			int t=check_pipe(inp);
			if(t<0)
			{
				printf("Error: Invalid Command\n");
				continue;
			}
			if(t>0)
			{
				piping(tmp,path,path2,home,prevdir);
				continue;
			}
			executecommand(inp,path,path2,home,prevdir);
		}
	}
	printf("----------------------------------------------------------------\n\n");
	return 0;
}