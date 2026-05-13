#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define N 5

sem_t chopstick[N];

void *philosopher(void *args)
{
	int id = *(int*)args;
	
	printf("Philosopher %d is thinking \n", id);
	sleep(1);
	sem_wait(&chopstick[id]);
	printf("Philosopher %d picked LEFT chopstick %d\n", id, id);

	sem_wait(&chopstick[(id+1)%N]);
	printf("Philosopher %d picked RIGHT chopstick %d\n", id, (id+1)%N);

	printf("Philosopher %d is eating\n", id);

	sleep(2);

	sem_post(&chopstick[id]);
	sem_post(&chopstick[(id+1)%N]);

	printf("Philosopher %d finished eating\n", id);
	sleep(1);
}

int main()
{
	for(int i = 0; i<N; i++)
		sem_init(&chopstick[i],0,1);
	
	pthread_t pt[N];
	int id[N];

	for(int i = 0; i < N; i++)
	{
		id[i] = i;
		pthread_create(&pt[i], NULL, philosopher, &id[i]);
	}

	for(int i = 0; i<N; i++)
		pthread_join(pt[i], NULL);

	for(int i = 0; i<N; i++)
		sem_destroy(&chopstick[i]);

	return 0;
}
