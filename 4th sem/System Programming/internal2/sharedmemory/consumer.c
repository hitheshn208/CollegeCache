#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>

int main()
{
	key_t key = 1234;
	int shmid = shmget(key, sizeof(int), 0666);
	int *data = (int*)shmat(shmid, NULL, 0);

	for(int i = 0; i < 10; i++)
	{
		printf("Consumer consumed: %d\n", *data);
		sleep(1);
	}

	shmdt(data);
	shmctl(shmid, IPC_RMID, NULL);
	return 0;

}
