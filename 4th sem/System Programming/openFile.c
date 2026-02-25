#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd = open("demo.txt", O_CREAT | O_WRONLY, 0644);
	if(fd == -1)
	{
		fprintf(stderr, "Couldn't create file\n");
		exit(1);
	}
	else
	{
		printf("File Created\n");
		close(fd);
	}
	return 0;
}
	
