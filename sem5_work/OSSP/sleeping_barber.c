#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#define CHAIRS 5
#define CUSTOMERS 8

sem_t customer, barber;
pthread_mutex_t lock;
int nfree = CHAIRS;

void *myCustomer(void *args)
{
	long id = (long)args;
	pthread_mutex_lock(&lock);
	if (nfree > 0)
	{
		nfree = nfree - 1;
		sem_post(&customer);
		printf("Seats Available: %d\n", nfree);
		pthread_mutex_unlock(&lock);
		sem_wait(&barber);
		printf("Customer %ld is getting haircut\n", (id + 1));
	}
	else
	{
		printf("Customer %ld arrived but shop is full\n", id);
		pthread_mutex_unlock(&lock);
	}
}

void *myBarber(void *args)
{
	while (1)
	{
		printf("Barber is sleeping\n");
		sem_wait(&customer);
		pthread_mutex_lock(&lock);
		nfree = nfree + 1;
		sem_post(&barber);
		pthread_mutex_unlock(&lock);
	}
}

int main()
{
	pthread_t barbers;
	pthread_t customers[CUSTOMERS];
	sem_init(&customer, 0, 0);
	sem_init(&barber, 0, 0);
	pthread_mutex_init(&lock, NULL);
	pthread_create(&barbers, NULL, myBarber, NULL);
	for (long i = 0; i < CUSTOMERS; i++)
		pthread_create(&customers[i], NULL, myCustomer, (void *)i);
	sleep(5);
	printf("Simulation Finished\n");
	pthread_mutex_destroy(&lock);
	sem_destroy(&barber);
	sem_destroy(&customer);
	exit(0);
}