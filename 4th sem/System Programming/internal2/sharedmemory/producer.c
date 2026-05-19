#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
	key_t key = 1234;
	int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
	int *data = (int *)shmat(shmid, NULL, 0);

	for(int i = 0; i < 10; i++)
	{
		*data = i;
		printf("Producer produced: %d\n",i);
		sleep(1);
	}

	shmdt(data);
	return 0;
}
