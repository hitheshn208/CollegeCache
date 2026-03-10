#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int size, char* path[])
{
	if(size < 2)
	{
		printf("Enter the file path!!!\n");
		exit(1);
	}

	struct stat stats;
	int fd = stat(path[1], &stats);
	if(fd == -1)
	{
		printf("File not found\n");
		exit(1);
	}
	else
	{
		printf("File Size : %ld bytes \nOwner UID : %d \nGroup UID : %d \nPermission : %o\n",stats.st_size,stats.st_uid, stats.st_gid, stats.st_mode);
	}
	return 0;
}


