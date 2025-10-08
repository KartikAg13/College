#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define PHILOSOPHERS 5

sem_t chopsticks[PHILOSOPHERS];

void *philosopher(void *args)
{
	long id = (long)args;
	int l;
	do
	{
		printf("Philosopher %ld is thinking\n", (id + 1));
		l = (id + 1) % PHILOSOPHERS;
		sem_wait(&chopsticks[l]);
		sem_wait(&chopsticks[id]);
		printf("Philosopher %ld is eating with chopsticks %d and %d\n", (id + 1), id, l);
		sem_post(&chopsticks[l]);
		sem_post(&chopsticks[id]);
	} while (1);
}

int main()
{
	pthread_t philosophers[PHILOSOPHERS];
	for (int i = 0; i < PHILOSOPHERS; i++)
		sem_init(&chopsticks[i], 0, 1);
	for (long i = 0; i < PHILOSOPHERS; i++)
		pthread_create(&philosophers[i], NULL, philosopher, (void *)i);
	sleep(5);
	printf("Simulation Finished\n");
	for (int i = 0; i < PHILOSOPHERS; i++)
		sem_destroy(&chopsticks[i]);
	exit(0);
}