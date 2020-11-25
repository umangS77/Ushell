#include"header.h"
int executecommand(char **c,char *path,char *path2,char *home,char *prevdir)
{

	if(size1==0)
	{
		return 1;
	}
	if(check_redirection(c))
	{
		redirection(c);
		return 1;
	}
	int i;
	int numofcoms=15;
	char* comlist[numofcoms];
	int fl=1;
	comlist[0]="cd";
	comlist[1]="pwd";
	comlist[2]="echo";
	comlist[3]="ls";
	comlist[4]="pinfo";
	comlist[5]="history";
	comlist[6]="nightswatch";
	comlist[9]="setenv";
	comlist[10]="unsetenv";
	comlist[7]="fg";
	comlist[8]="bg";
	comlist[11]="overkill";
	comlist[12]="jobs";
	comlist[13]="kjob";
	comlist[14]="quit";
	for(i=0;i<numofcoms;i++)
	{
		if(strcmp(comlist[i],c[0])==0)
		{
			break;
		}
	}
	fl=0;
	if(c[size1-1][0]=='&' && strlen(c[size1-1])==1)
	{
		i=numofcoms;
	}
	if(i==0)
	{
		execute_cd(c,prevdir);
		return 1;
	}
	else if(i==1)
	{
		printf("%s\n",path2);
		return 1;
	}
	else if(i==2)
	{
		if(c[1]!=NULL)
			execute_echo(c);
		return 1;
	}
	else if(i==3)
	{
		execute_ls(c,home,path);
		return 1;
	}
	else if(i==4)
	{
		pinfo(c);
		return 1;
	}
	else if(i==5)
	{
		if(c[1]==NULL)
			print_history(home,10,false);
		else
		{
			print_history(home,(atoi(c[1])),true );
		}
		return 1;
	}
	else if(i==6)
	{
		execute_nightswatch(c);
		return 1;
	}
	else if(i==7)
	{
		execute_fg(c);
		return 1;
	}
	else if(i==8)
	{
		execute_bg(c);
		return 1;
	}
	else if(i==9)
	{
		execute_setenv(c);
		return 1;
	}
	else if(i==10)
	{
		execute_unsetenv(c);
		return 1;
	}
	else if(i==11)
	{
		execute_overkill(1);
		return 1;
	}
	else if(i==12)
	{
		job();
		return 1;
	}
	else if(i==13)
	{
		execute_kjob(c);
		sleep(1);
		return 1;
	}
	else if(i==14)
	{
		execute_overkill(0);
		printf("\n----------------------------------------------------------------\n\n");
		exit(0);
		return 1;
	}
	else
	{
		// int zz = (c[size1-1][0]=='&' && strlen(c[size1-1])==1);
		execute_others(c,c[size1-1][0]=='&' && strlen(c[size1-1])==1);
		return 1;
	}
	// switch(i)
	// {
	// 	case 0:
	// 			execute_cd(c,prevdir);
	// 			return 1;
	// 	case 1:
	// 			printf("%s\n",path2);
	// 			return 1;
	// 	case 2:
	// 			if(c[1]!=NULL)
	// 				execute_echo(c);
	// 			return 1;
	// 	case 3:
	// 			execute_ls(c,home,path);
	// 			return 1;
	// 	case 4:
	// 			pinfo(c);
	// 			return 1;
	// 	case 5:
	// 			if(c[1]==NULL)
	// 				print_history(home,10,false);
	// 			else
	// 			{
	// 				print_history(home,(atoi(c[1])),true );
	// 			}
	// 			return 1;
	// 	case 6:
	// 			execute_nightswatch(c);
	// 			return 1;
	// 	case 7:
	// 			execute_fg(c);
	// 			return 1;
	// 	case 8:
	// 			execute_bg(c);
	// 			return 1;
	// 	case 9:
	// 			execute_setenv(c);
	// 			return 1;
	// 	case 10:
	// 			execute_unsetenv(c);
	// 			return 1;
	// 	case 11:
	// 			execute_overkill(1);
	// 			return 1;
	// 	case 12:
	// 			job();
	// 			return 1;
	// 	case 13:
	// 			execute_kjob(c);
	// 			sleep(1);
	// 			return 1;
	// 	case 14:
	// 			execute_overkill(0);
	// 			printf("\n----------------------------------------------------------------\n\n");
	// 			exit(0);
	// 			return 1;
	// 	default:
	// 			int zz = (c[size1-1][0]=='&' && strlen(c[size1-1])==1);
	// 			execute_others(c,zz);
	// 			return 1;
	// }
}