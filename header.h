#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <pwd.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <grp.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <termios.h>
#include <libgen.h>
#include <string.h>

#define MIDL 1024
#define MAXL 100005
#define lli long long int
struct node
{
	int status,jobid;
	pid_t pid;
	char com[100];
};

int size,size1,jobsize;
char path[MAXL],home[MAXL],path2[MAXL],origin_home[MAXL];
char prevdir[MIDL],prevprompt[MIDL];
struct node jobs[MAXL];
void add_history(char *input, char org_home[]);
void checkbg();
int check_pipe(char **c);
int check_redirection(char **c);
int executecommand(char **c,char *path,char *path2,char *home,char *prevdir);
void execute_bg(char **c);
void execute_cd(char **c, char *prevdir);
void execute_fg(char **c);
void execute_kjob(char **args);
void execute_echo(char **c);
void execute_ls(char **args,char org_home[], char cwd[]);
void execute_others(char **c,int bg);
void execute_overkill(int f);
void execute_nightswatch(char **args);
void execute_setenv(char **c);
void execute_unsetenv(char **c);
void handler();
void handler1(int sig_num);
void handler2(int sig_num);
void job();
void trim_inp(char *inp,char **c);
int pinfo(char **args);
void print_history(char org_home[], int x, bool args);
void prompt(char path[], char org_home[], char prev_prompt[], char prevdir[]);
void read_inp(char** c,char home[]);
int redirection(char **c);
void piping(char *c,char *path,char *path2,char *home,char *prevdir);