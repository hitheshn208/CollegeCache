#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int global = 100;

int main()
{
	int var = 10;
	pid_t pid;
	printf("Before fork\n");
	
	if((pid = fork())<0)
	{
		fprintf(stderr, "Fork failed");
	}
	else if(pid == 0)
	{
		global++;
		var++;
	}
	else
	{
		sleep(2);
	}
	printf("pid = %d, global = %d, local = %d\n", (int)getpid(), global, var);
	return 0;
}	
