#include<stdio.h>
#include<unistd.h>
int global = 10;
int main()
{
	int local = 100;
	int pid =  fork();
    	if(pid < 0)
    	{
        	printf("error while creating the process");
        	return 0;
    	}
    	else if(pid == 0)
    	{
		global++;
		local++;
        	printf("In Child process\n");
    	}
    	else if(pid > 0)
    	{
		sleep(2);
        	printf("In Parent process\n");
    	}

	printf("Pid : %ld global var : %d local var : %d\n",(long)getpid(), global, local); 
}
