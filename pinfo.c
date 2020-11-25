#include"header.h"

int pinfo(char **args)
{
	char file1[MIDL],file2[MIDL],file3[MIDL],status,inp[100],*buffer;
	buffer = (char *)malloc(sizeof(buffer));

	lli id,pid,process_id,memory=0;
	if(args[1]==NULL)
	{
		pid = getppid();
	}
	else
		pid = atoi(args[1]);

	sprintf(file3,"/proc/%lld/exe",pid); // symbolic link
	lli i = readlink(file3,buffer,MIDL);
	buffer[strlen(buffer)]='\0';
	sprintf(file1,"/proc/%lld/stat",pid);

	FILE *f1 = fopen(file1,"r");
	if(f1==NULL)
	{
		printf("Error : Invalid pid\n");
	}
	else
	{
		fscanf(f1,"%lld %s %c %lld",&process_id,inp,&status,&id);

		printf("pid -- %lld\n",process_id);
		printf("Process Status -- {%c}\n",status);

		sprintf(file2,"/proc/%lld/statm",pid);

		FILE *f2=fopen(file2,"r");
		fscanf(f2,"%lld %lld",&memory,&process_id);
		printf("memory -- %lld\n",memory);
		printf("Executable Path -- %s\n",buffer);
		fclose(f1);
		fclose(f2);
	}
	return 1;
}