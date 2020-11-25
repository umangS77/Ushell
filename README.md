## Overview

An interactive shell written in C with foreground/background process, redirection and piping support.

## Execution:

```bash
makefile
./a.out
```
## Supported Commands

cd < . / .. / ~ / - / directoryName / directoryPath >  
ls < . / .. / -l / -a / -la / -al >  
echo <argument>  
pinfo <pid> (argument optional)  
fg <job number>  
bg <job number>  
history <argument> (argument optional)  
nightswatch -n [time interval] interrupt  
setenv var [value]  
unsetenv var  
jobs  
kjob <job number> <signal number>  
overkill  
quit  

## Signal Handling

CTRL+Z : It pushes any currently running foreground job into the background and changes its state from running to stopped.

CTRL+C : It interrupts any currently running foreground job, by sending it the ​SIGINT​ signal.

CTRL+D : performs same function as quit command

## Description of files:

### makefile:
creates executable file.

### header.h:
contains all the header files, global variables and functions definitions used in the program.

### cd.c:
contains code to execute function of "cd" command. I used "chdir" command to get the directory address. Appropriate error message is displayed if directory is not present.

### check_bg.c:
contains code to check if any background process has ended normally or abnormally.

### echo.c:
contains code to execute function of "echo" command. Extra spaces and tabs are trimmed.exec_comms.c:### matches the command to be execute and then calls the appropriate function with required parameters.

### fgbg.c:
contains code that handles background and foreground processes. Can be used to send foreground process to background and vice-versa and change the status of any process from running to stopped and vice versa.

### history.c:
contains code to execute function of "history" command. Two functions- one to add to history_log.txt file and another to print from history_log.txt file. Handled cases if argument is > 20.

### job.c:
contains code to list all the currently running background processes.

### kjob.c:
contains code to kill a specific process, specified by its Jobid.

### ls.c:
contains code to execute function of "ls" command. Used functions like opendir(directory_address), readdir(directory_address), stat(parameters), getpwuid(parameters), getgrgid(parameters), ctime(parameters).

### nightswatch.c:
contains code to execute function which print the number of times the CPU(s) have been interrupted by keyboard controller. A line is printed every x seconds as input by user and the program is stopped if 'q' is pressed. Tokens 1 and 3 are printed from the proc/interrupt file since token 1 is CPU core number and token 3 is the value.

### others.c:
contains code to execute commands other than the ones mentioned in assignment.

### overkill.c:
contains code to kill all background processes.

### pinfo.c
contains code to print the pid of the process. Used function getpid() to get the pid and printed details of the process. Used syntax proc/[pid]/exec, proc/[pid]/stat, proc/[pid]/statm.

### pipe.c:
contains code to handle the piping of commands.

### prompt.c:
contains code to print the prompt of the shell. Prints in format: 
<username@hostname:directory_name>

### read_input.c:
contains code to accept input from the shell and execute the function accordingly. Reads line from terminal and breaks it down into tokens using ";" as delimiter by function strtok().

### redirect.c:
contains code to handle the redirection of commands.

### setenv.c:
contains code to set environment variables.

### unsetenv.c:
contains code to unset environment variables.

### shell.c:
contains the skeleton code of the shell. The shell runs till we get the command to quit.
