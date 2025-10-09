#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define VEHICLES 11
#define LOCATIONS 5

sem_t spots;

void *vehicle(void *args)
{
	long id = (long)args;
	printf("Vehicle %ld waiting\n", (id + 1));
	sem_wait(&spots);
	printf("Vehicle %ld parked\n", (id + 1));
	sem_post(&spots);
	printf("Vehicle %ld left\n", (id + 1));
	pthread_exit(NULL);
}

int main()
{
	pthread_t vehicles[VEHICLES];
	sem_init(&spots, 0, LOCATIONS);
	for (long i = 0; i < VEHICLES; i++)
		pthread_create(&vehicles[i], NULL, vehicle, (void *)i);
	for (int i = 0; i < VEHICLES; i++)
		pthread_join(vehicles[i], NULL);
	sem_destroy(&spots);
	return 0;
}