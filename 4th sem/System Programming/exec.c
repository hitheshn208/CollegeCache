#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	printf("Hello world (pid: %d)\n", (int)getpid());
	int rc = fork();
	if(rc < 0)
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}
	else if( rc == 0)
	{
		printf("Hello, i am child(pid %d)\n", (int)getpid());
		char* myargs[3];
		myargs[0] = strdup("wc");
		myargs[1] = strdup("test.txt");
		myargs[2] = NULL;
		execvp(myargs[0], myargs);
		printf("This shouldn't print\n");
	}
	else
	{
		int rc_wait = wait(NULL);
		printf("Hello, i am parent of %d (rc_wait %d)(pid %d)\n", rc, rc_wait, getpid());
	}
	return 0;
}
