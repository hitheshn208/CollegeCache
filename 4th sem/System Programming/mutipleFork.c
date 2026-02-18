#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	fork();
	fork();
	fork();

	printf("Process id : %d\n", (int)getpid());
	return 0;
}

