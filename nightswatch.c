#include "header.h"

bool keyPressed()
{
    struct termios oldtime, newtime;
    int mem;
    tcgetattr(STDIN_FILENO, &oldtime);
    newtime = oldtime;
    newtime.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newtime);
    ioctl(STDIN_FILENO, FIONREAD, &mem);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldtime);
    if(mem > 0)
    	return true;
    return false;
}

void execute_nightswatch(char **args)
{
	int time = atoi(args[2]);
	if(strcmp(args[1],"-n")!=0 || time==0 || strcmp(args[3],"interrupt")!=0)
	{
		printf("Error: Invalid arguments\n");
		return;
	}
	while(1)
	{
		if(keyPressed())
		{
			if(getchar() == 'q')
			{
				printf("\n");
				return;
			}
		}
		char file [MIDL];
	    strcpy(file,"/proc/interrupts");
	    FILE * fl = fopen (file,"r");

	    if (fl != NULL)
	    {
	        int count=0;
	        char buffer[100];
	        while (fgets(buffer, sizeof(buffer), fl))
	        {
	            count++;
	            if(count==1  || count==3)
	            {
	                buffer[95]='\0';
	                printf("%s\n",buffer+6);
	                if(count==3)
	                	break;
	            }
	        }
	    }
	    
	    fclose(fl);
	    for(int i=0;i<time;i++)
	    {
	    	if(keyPressed())
			{
				if(getchar() == 'q')
				{
					printf("\n");
					return;
				}
			}
			sleep(1);
	    }
	}
}