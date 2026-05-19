#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex;
sem_t wrt;

int readcount = 0;
int data = 0;

void *reader(void *args)
{
	int id = *(int*)args;

	sem_wait(&mutex);
	readcount++;
	if(readcount == 1)
		sem_wait(&wrt);
	sem_post(&mutex);

	printf("Reader %d is reading %d\n", id, data);

	sem_wait(&mutex);
	readcount--;
	if(readcount == 0)
		sem_post(&wrt);
	sem_post(&mutex);

	return NULL;
}

void *writer(void *args)
{
	int id = *(int*)args;

	sem_wait(&wrt);
	data++;
	printf("Writer %d is writing data = %d\n", id, data);
	sleep(1);
	sem_post(&wrt);
	
	return NULL;
}

int main()
{
	pthread_t r[3], w[2];

	int rid[3] = {1,2,3};
	int wid[2] = {1,2};


	sem_init(&mutex, 0,1);
	sem_init(&wrt, 0, 1);


	pthread_create(&w[0], NULL, writer, &wid[0]);

	for(int i = 0; i < 3; i++){
		pthread_create(&r[i], NULL, reader, &rid[i]);
	}

	pthread_create(&w[0], NULL, writer, &wid[0]);

	for(int i = 0; i < 3; i++)
		pthread_join(r[i], NULL);

	for(int i = 0; i < 2; i++)
		pthread_join(w[i], NULL);

	sem_destroy(&mutex);
	sem_destroy(&wrt);


	return 0;
}
