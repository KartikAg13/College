#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER 5
#define PRODUCERS 2
#define CONSUMERS 3
#define ITEMS 10

int buffer[BUFFER];
int in = 0, out = 0;

pthread_mutex_t lock;
sem_t empty, full;

void *producer(void *args)
{
	long id = (long)args;
	int item;
	for (int i = 0; i < ITEMS; i++)
	{
		item = rand() % 100;
		sem_wait(&empty);
		pthread_mutex_lock(&lock);
		buffer[in] = item;
		printf("Producer %ld inserted item %d at %d\n", (id + 1), item, in);
		in = (in + 1) % BUFFER;
		pthread_mutex_unlock(&lock);
		sem_post(&full);
	}
	pthread_exit(NULL);
}

void *consumer(void *args)
{
	long id = (long)args;
	int item;
	while (1)
	{
		sem_wait(&full);
		pthread_mutex_lock(&lock);
		item = buffer[out];
		printf("Consumer %ld removed item %d from %d\n", (id + 1), item, out);
		out = (out + 1) % BUFFER;
		pthread_mutex_unlock(&lock);
		sem_post(&empty);
	}
}

int main()
{
	pthread_t producers[PRODUCERS];
	pthread_t consumers[CONSUMERS];
	pthread_mutex_init(&lock, NULL);
	sem_init(&empty, 0, BUFFER);
	sem_init(&full, 0, 0);
	for (long i = 0; i < PRODUCERS; i++)
		pthread_create(&producers[i], NULL, producer, (void *)i);
	for (long i = 0; i < CONSUMERS; i++)
		pthread_create(&consumers[i], NULL, consumer, (void *)i);
	for (long i = 0; i < PRODUCERS; i++)
		pthread_join(producers[i], NULL);
	printf("Producers have finished\n");
	pthread_mutex_destroy(&lock);
	sem_destroy(&empty);
	sem_destroy(&full);
	exit(0);
}