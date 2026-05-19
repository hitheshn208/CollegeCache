#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
	int pid = fork();
	if(pid < 0)
	{
		printf("Error when creating a process\n");
		exit(0);
	}else if(pid == 0){
		printf("Hello from child process %d\n",(int)getpid());
		char *args[3];
		args[0] = strdup("ls");
		args[1] = strdup("-l");
		args[2] = NULL;
		execvp(args[0], args);
		printf("If this line prints the execvp() failed\n");
	}else{
		int cpid = wait(NULL);
		printf("Hello from parent process (%d) waiting for child(%d)\n", (int)getpid(), pid);
	}
	return 0;
}	
