#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#define READERS 5
#define WRITERS 3

pthread_mutex_t lock;
sem_t wrt;
int rc = 0;
int data = 0;

void *writer(void *args)
{
	long id = (long)args;
	while (1)
	{
		sem_wait(&wrt);
		data = rand() % 100;
		printf("Writer %ld wrote %d\n", id, data);
		sem_post(&wrt);
	}
}

void *reader(void *args)
{
	long id = (long)args;
	while (1)
	{
		pthread_mutex_lock(&lock);
		rc = rc + 1;
		if (rc == 1)
			sem_wait(&wrt);
		pthread_mutex_unlock(&lock);
		printf("Reader %ld read %d\n", id, data);
		pthread_mutex_lock(&lock);
		rc = rc - 1;
		if (rc == 0)
			sem_post(&wrt);
		pthread_mutex_unlock(&lock);
	}
}

int main()
{
	pthread_t readers[READERS];
	pthread_t writers[WRITERS];
	pthread_mutex_init(&lock, NULL);
	sem_init(&wrt, 0, 1);
	for (long i = 0; i < WRITERS; i++)
		pthread_create(&writers[i], NULL, writer, (void *)i);
	for (long i = 0; i < READERS; i++)
		pthread_create(&readers[i], NULL, reader, (void *)i);
	sleep(5);
	printf("Simulation Finished\n");
	pthread_mutex_destroy(&lock);
	sem_destroy(&wrt);
	exit(0);
}