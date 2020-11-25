#include "header.h"

void job()
{
	char f1[MIDL],f2[MIDL],name[MIDL];
	for(int i=0;i<jobsize;i++)
	{
		if(jobs[i].status==0)
		{
			continue;
		}
		int fl;
		sprintf(name,"/proc/%d/stat",jobs[i].pid);
		FILE *file=fopen(name,"r");
		fl=1;
		// cout<<fl<<"\n";
		if(file==NULL)
		{
			jobs[i].status=0;
			continue;
		}
		// cout<<fl<<"\n";
		fscanf(file,"%s %s %s",f1,f1,f2);
		fl++;
		// cout<<fl<<"\n";
		if(strcmp(f2,"T")!=0)
		{
			printf("[%d] Running %s [%d]\n",jobs[i].jobid,f1,jobs[i].pid);
			continue;
		}
		else
		{
			printf("[%d] Stopped %s [%d]\n",jobs[i].jobid,f1,jobs[i].pid);
		}
	}
}
