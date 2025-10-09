#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#define POTASSIUMS 10
#define OXYGENS 5

sem_t k_ready, o_ready;
pthread_mutex_t lock;
int kc = 0, oc = 0;

void *potassium(void *args)
{
	long id = (long)args;
	printf("Potassium %ld is ready\n", (id + 1));
	pthread_mutex_lock(&lock);
	kc = kc + 1;
	if (kc >= 2 && oc >= 1)
	{
		sem_post(&k_ready);
		sem_post(&k_ready);
		sem_post(&o_ready);
		printf("K = %d and O = %d\n", kc, oc);
		kc = kc - 2;
		oc = oc - 1;
	}
	pthread_mutex_unlock(&lock);
	sem_wait(&k_ready);
	pthread_exit(NULL);
}

void *oxygen(void *args)
{
	long id = (long)args;
	printf("Oxygen %ld is ready\n", (id + 1));
	pthread_mutex_lock(&lock);
	oc = oc + 1;
	if (kc >= 2 && oc >= 1)
	{
		sem_post(&k_ready);
		sem_post(&k_ready);
		sem_post(&o_ready);
		printf("K = %d and O = %d\n", kc, oc);
		kc = kc - 2;
		oc = oc - 1;
	}
	pthread_mutex_unlock(&lock);
	sem_wait(&o_ready);
	pthread_exit(NULL);
}

int main()
{
	pthread_t potassiums[POTASSIUMS];
	pthread_t oxygens[OXYGENS];
	sem_init(&k_ready, 0, 0);
	sem_init(&o_ready, 0, 0);
	pthread_mutex_init(&lock, NULL);
	for (long i = 0; i < POTASSIUMS; i++)
		pthread_create(&potassiums[i], NULL, potassium, (void *)i);
	for (long i = 0; i < OXYGENS; i++)
		pthread_create(&oxygens[i], NULL, oxygen, (void *)i);
	for (int i = 0; i < POTASSIUMS; i++)
		pthread_join(potassiums[i], NULL);
	for (int i = 0; i < OXYGENS; i++)
		pthread_join(oxygens[i], NULL);
	sem_destroy(&k_ready);
	sem_destroy(&o_ready);
	pthread_mutex_destroy(&lock);
	return 0;
}