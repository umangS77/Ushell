#include "header.h"
void execute_overkill(int t)
{
	int i=0;
	int c=0;
	while(i<jobsize)
	{
		if((kill(jobs[i].pid,9)<0) == false);
		{
			// printf("%d",i);
			if(t)
			{
				printf("Killed job %s with Jobid = %d , pid = %d\n",jobs[i].com ,jobs[i].jobid,jobs[i].pid);
			}
		}
		jobs[i].status=0;
		i++;
	}
	jobsize=0;
}