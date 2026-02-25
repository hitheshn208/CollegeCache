#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd = open("demo.txt", O_RDONLY);
	char buff1[50] = {'\0'}, buff2[50] = {'\0'} ;
	if(fd < 0)
	{
		fprintf(stderr, "Couldn't open file\n");
		exit(1);
	}

	int status = read(fd, buff1, 20);
	int offset = lseek(fd, 20, SEEK_SET);
	status = read(fd, buff2, 20);

	if(status < 0)
	{
		fprintf(stderr, "Couldn't read file\n");
		exit(1);
	}
	else
	{
		printf("First 20 characters : %s\n", buff1);
		printf("Next 20 characters : %s\n", buff2);
	}
	return 0;
}

