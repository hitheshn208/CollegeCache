#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty;
sem_t full;
sem_t mutex;

void *producer(void *args)
{
	int item = 0;

	for(int i = 0; i < 5; i++)
	{
		sem_wait(&empty);
		sem_wait(&mutex);

		buffer[in] = item;

		printf("Producer produced %d at position %d\n", item, in);

		item++;
		in = (in + 1)%5;

		sem_post(&mutex);
		sem_post(&full);

		sleep(1);
	}
}

void *consumer(void *args)
{
	int item;

	for(int i = 0; i<5; i++)
	{
		sem_wait(&full);
		sem_wait(&mutex);

		item = buffer[out];

		printf("Consumer consumed %d at position %d\n", item, out);

		out = (out+1)%5;

		sem_post(&mutex);
		sem_post(&empty);

		sleep(1);
	}
}

int main()
{
	pthread_t p, c;
	
	sem_init(&empty, 0, BUFFER_SIZE);
	sem_init(&full, 0, 0);
	sem_init(&mutex, 0, 1);

	pthread_create(&p, NULL, producer, NULL);
	pthread_create(&c, NULL, consumer, NULL);

	pthread_join(p, NULL);
	pthread_join(c, NULL);

	sem_destroy(&empty);
	sem_destroy(&full);
	sem_destroy(&mutex);

	return 0;
}
