#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int writedata = 678;
	int readdata;
	
	int fd[2];
	pipe(fd);

	pid_t pid = fork();
	
	if(pid<0)
	{
		printf("Failed to create child process\n");
		exit(1);

	}else if(pid > 0){

		close(fd[0]);
		for(int i = 0; i < 5; i ++)
		{
			write(fd[1], &writedata, sizeof(int));
			printf("Producer wrote %d into the buffer\n", writedata);
			writedata++;
			sleep(1);
		}
		close(fd[1]);
		wait(NULL);

	}else{
		close(fd[1]);
		for(int i = 0; i < 5; i++)
		{
			read(fd[0], &readdata, sizeof(int));
			printf("Consumer consumed %d from the buffer\n", readdata);
			sleep(1);
		}
		close(fd[0]);
	}

	return 0;
}
