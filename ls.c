#include "header.h"
struct dirent *dp;

void lsa(char diradd[MIDL])
{
	DIR *dr = opendir(diradd);
	while((dp = readdir(dr)) != NULL)
	{
		printf("%s\n",dp->d_name);
	}
}

void lsl(char * diradd)
{
	char strdate[MIDL];
	struct stat file_stat;
	DIR *dr = opendir(diradd);
	int ln = strlen(diradd);
	// printf("%s\n",diradd);
	while ((dp = readdir(dr)) != NULL) 
  	{
  		char temp[MIDL];
  		strcpy(temp,diradd);
  		if(dp->d_name[0]=='.')
  			continue;
		
		char per_modes[11];
		temp[ln]='/';
		ln++;
		char file_name[MIDL];
		strcpy(file_name, dp->d_name);
		for(int i=0;i<strlen(file_name);i++)
		{
			temp[ln++] = file_name[i];
		}
		// printf("file is %s\n",temp);
		int kl = stat(temp,&file_stat);
		// if(kl == -1)
		// {
		// 	printf("Error : %s file or folder not accessible\n",file_name);
		// }
		per_modes[0] = ((file_stat.st_mode & S_IFDIR)? 'd':'-');
	  	per_modes[1] = ((file_stat.st_mode & S_IRUSR)? 'r':'-');
	  	per_modes[2] = ((file_stat.st_mode & S_IWUSR)? 'w':'-');
	  	per_modes[3] = ((file_stat.st_mode & S_IXUSR)? 'x':'-');
	  	per_modes[4] = ((file_stat.st_mode & S_IRGRP)? 'r':'-');
	  	per_modes[5] = ((file_stat.st_mode & S_IWGRP)? 'w':'-');
	  	per_modes[6] = ((file_stat.st_mode & S_IXGRP)? 'x':'-');
	  	per_modes[7] = ((file_stat.st_mode & S_IROTH)? 'r':'-');
	  	per_modes[8] = ((file_stat.st_mode & S_IWOTH)? 'w':'-');
	  	per_modes[9] = ((file_stat.st_mode & S_IXOTH)? 'x':'-');
	  	per_modes[10]='\0';

	  	struct passwd *pw = getpwuid(file_stat.st_uid);
		struct group *gr = getgrgid(file_stat.st_gid);
		printf("%s %u %s %s %5ld ",per_modes,(unsigned int)file_stat.st_nlink,pw->pw_name,gr->gr_name,file_stat.st_size);

		strcpy(strdate,ctime(&file_stat.st_ctime));

		strdate[7]=strdate[10]=strdate[16]='\0';
		printf("%s %s %s %s\n",strdate +4, strdate +8, strdate +11,dp->d_name);
  	}
}

void lsal(char  diradd[MIDL])
{
	char strdate[MIDL];
	struct stat file_stat;
	DIR *dr = opendir(diradd);
	int ln = strlen(diradd);
	// printf("%s\n",diradd);
	while ((dp = readdir(dr)) != NULL) 
  	{
  		char temp[MIDL];
  		strcpy(temp,diradd);
		
		char per_modes[11];
		temp[ln]='/';
		ln++;
		char file_name[MIDL];
		strcpy(file_name, dp->d_name);
		for(int i=0;i<strlen(file_name);i++)
		{
			temp[ln++] = file_name[i];
		}
		// printf("file is %s\n",temp);
		int kl = stat(temp,&file_stat);
		// if(kl == -1)
		// {
		// 	printf("Error : %s file or folder not accessible\n",file_name);
		// }
		per_modes[0] = ((file_stat.st_mode & S_IFDIR)? 'd':'-');
	  	per_modes[1] = ((file_stat.st_mode & S_IRUSR)? 'r':'-');
	  	per_modes[2] = ((file_stat.st_mode & S_IWUSR)? 'w':'-');
	  	per_modes[3] = ((file_stat.st_mode & S_IXUSR)? 'x':'-');
	  	per_modes[4] = ((file_stat.st_mode & S_IRGRP)? 'r':'-');
	  	per_modes[5] = ((file_stat.st_mode & S_IWGRP)? 'w':'-');
	  	per_modes[6] = ((file_stat.st_mode & S_IXGRP)? 'x':'-');
	  	per_modes[7] = ((file_stat.st_mode & S_IROTH)? 'r':'-');
	  	per_modes[8] = ((file_stat.st_mode & S_IWOTH)? 'w':'-');
	  	per_modes[9] = ((file_stat.st_mode & S_IXOTH)? 'x':'-');
	  	per_modes[10]='\0';

	  	struct passwd *pw = getpwuid(file_stat.st_uid);
		struct group *gr = getgrgid(file_stat.st_gid);
		printf("%s %u %s %s %5ld ",per_modes,(unsigned int)file_stat.st_nlink,pw->pw_name,gr->gr_name,file_stat.st_size);

		strcpy(strdate,ctime(&file_stat.st_ctime));

		strdate[7]=strdate[10]=strdate[16]='\0';
		printf("%s %s %s %s\n",strdate +4, strdate +8, strdate +11,dp->d_name);
  	}

}

void execute_ls(char **args,char org_home[], char cwd[])
{
	int a=0,l=0,i;
	int errflag=0;
	char pathname[MIDL]={'\0'};

	for(i=1;i<size1;i++)
	{
		// printf("i= %d & args= %s\n",i,args[i]);
		if(strcmp(args[i],"-a")==0)
			a=1;
		else if(strcmp(args[i],"-l")==0)
			l=1;
		else if(strcmp(args[i],"-al")==0 || strcmp(args[i],"-la")==0)
			a=l=1;
		else
		{
			if(args[i][0]=='-')
			{
				errflag=1;
				break;
			}
			else
			{
				strcpy(pathname, args[i]);
			}
		}
	}

	if(errflag)
	{
		printf("No such command exists\n");
			return;
	}
	// printf("pathname= %s\n",pathname);
	if(strcmp(pathname,"")==0)
	{
		if(a==1 && l==1)
		{
			lsal(".");
		}
		else if(a==1 && l!=1)
		{
			lsa(".");
		}
		else if(l==1 && a!=1)
		{
			lsl(".");
		}
		else
		{
			DIR *list = opendir(".");
			while((dp = readdir(list)) != NULL)
			{
				if(dp->d_name[0]!='.')
					printf("%s\n", dp->d_name);
			}
		}
		return;
	}

	char realpath[MIDL]={'\0'};
	if (pathname[0] == '~')
	{
		strcpy(realpath,org_home);
		int k = strlen(realpath);
		for(i=1;i<strlen(pathname);i++)
		{
			realpath[k++] = pathname[i];
		}
	}
	else
	{
		strcpy(realpath,cwd);
		int k = strlen(realpath);
		if(pathname[0] != '/' && realpath[k-1]!='/')
			realpath[k++]='/';
		
		for(i=0;i<strlen(pathname);i++)
			realpath[k++]=pathname[i];
	}
	// printf("path = %s\n",realpath);

	if(a==1 && l==1)
	{
		lsal(realpath);
	}
	else if(a==1 && l!=1)
	{
		lsa(realpath);
	}
	else if(l==1 && a!=1)
	{
		lsl(realpath);
	}
	else
	{
		DIR *list = opendir(realpath);
		while((dp = readdir(list)) != NULL)
		{
			if(dp->d_name[0]!='.')
				printf("%s\n", dp->d_name);
		}
	}
	return;

}


