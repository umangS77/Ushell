#include "header.h"
void add_history(char *input, char org_home[])
{
	int l = strlen(org_home),i;
	char pathname[MIDL];
	char pathhist[MIDL];
	for(i=0;i<MIDL;i++)
	{
		pathname[i]='\0';
	}
	strcpy(pathname,org_home);
	char hist[MIDL];
	strcpy(hist,"/history_log.txt");
	for(i=0;i<16;i++)
	{
		pathname[l+i]=hist[i];
	}
	strcpy(pathhist,pathname);
	pathhist[l+16-1]='p';
		FILE *f1;
		f1 = fopen(pathname, "a+");
		int c=0;
		char buf[MIDL];
		while(fgets(buf,MIDL,f1)!=NULL)
		{
			c++;
		}
		if(c>=20)
		{
			FILE *f2;
			f2 = fopen(pathhist, "a+");
			c=0;
			fseek(f1,0,0);
			fseek(f2,0,0);
			while(fgets(buf,MIDL,f1)!=NULL)
			{
				c++;
				if(c==1)
					continue;
				fprintf(f2,"%s",buf);
			}
			fprintf(f2,"%s\n",input);
			fclose(f2);
			fclose(f1);
			remove(pathname);
			rename(pathhist,pathname);
		}
		else
		{
			fprintf(f1,"%s\n",input);
			fclose(f1);
		}
	return;
}

void print_history(char org_home[], int x, bool args)
{
	if(x<0)
	{
		printf("INVALID INPUT\n");
		return;
	}
	if(x==0)
	{
		return;
	}
	// printf("A %d\n",x);
	if(args == false)
		x=10;
	else if(args==true && x>20)
	{
		printf("Error : Argument must be <= 20.\n");
		return;
		x=10;
	}
	int l = strlen(org_home),i=0;
	char pathname[MIDL],buf[MIDL];
	for(i=0;i<MIDL;i++)
	{
		pathname[i]='\0';
	}
	strcpy(pathname,org_home);
	char hist[MIDL];
	strcpy(hist,"/history_log.txt");
	for(i=0;i<16;i++)
	{
		pathname[l+i]=hist[i];
	}
	FILE *f1;
	f1 = fopen(pathname,"a+");
	i=0;
	while(fgets(buf,MIDL,f1)!=NULL)
	{
		i++;
	}
	// printf("i= %d\n",i);
	if(i<x)
	{
		printf("Only %d commands are saved\n",i);
		x=i;
	}
	fseek(f1,0,0);
	int j=1;
	while(fgets(buf,MIDL,f1)!=NULL)
	{
		if(j>(i-x))
		printf("%s",buf);
		j++;
	}
	fclose(f1);
	return;
}