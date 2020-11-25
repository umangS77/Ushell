#include "header.h"
void prompt(char path[], char org_home[], char prev_prompt[], char prevdir[])
{
  char username[MIDL], hostname[MIDL], cwd[MIDL], dirname[MIDL];
  char tempdir[MIDL];
  if(strcmp(home,"")==0)
  strcpy(home,origin_home);
  strcpy(tempdir,org_home);
  getcwd(cwd,MIDL);
  strcpy(path, cwd);
  if(strcmp(prevdir,"")==0)
    strcpy(prevdir,"~");


  lli l1,l2,i;
  bool f = true;
  l1=strlen(cwd);
  l2=strlen(org_home);
  for (i=0;i<l2 && i<l1;i++)
  {
    if(cwd[i]!=org_home[i])
      {
        f=false;
        break;
      }
  }
  if(i==l2 && f)
  {
    dirname[0]='~';
    for (;i<=l1;i++)
    {
      dirname[i-l2+1]=cwd[i];
    }
  }
  else
  {
    strcpy(dirname,cwd);
  }
  if(strcmp(prev_prompt, dirname) !=0)
  {
    strcpy(prevdir,prev_prompt);
  }
  getlogin_r(username, MIDL);
  gethostname(hostname, MIDL);
  printf("\n<%s@%s:%s> ",username, hostname,dirname);
  strcpy(prev_prompt, dirname);
  fflush(stdout);
}