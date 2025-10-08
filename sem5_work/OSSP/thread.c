#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

long balance;
pthread_mutex_t lock;
pthread_cond_t is_ready;

void *deposit(void *args)
{
	long n = (long)args;
	pthread_mutex_lock(&lock);
	balance = balance + 200;
	printf("Balance after deposit: %ld\n", balance);
	if (balance > 1000)
		pthread_cond_signal(&is_ready);
	pthread_mutex_unlock(&lock);
	pthread_exit((void *)n);
}

void *withdraw(void *args)
{
	long n = (long)args;
	pthread_mutex_lock(&lock);
	while (balance <= 1000)
		pthread_cond_wait(&is_ready, &lock);
	balance = balance - 100;
	printf("Balance after withdraw: %ld\n", balance);
	pthread_mutex_unlock(&lock);
	pthread_exit((void *)n);
}

int main()
{
	int n;
	printf("Please enter the number of threads: ");
	scanf("%d", &n);
	pthread_t thread1[n], thread2[n];
	balance = 900;
	void *d, *w;
	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("Mutex initialization failed\n");
		exit(-1);
	}
	if (pthread_cond_init(&is_ready, NULL) != 0)
	{
		printf("Cond initialization failed\n");
		exit(-1);
	}
	for (long i = 0; i < n; i++)
	{
		pthread_create(&thread1[i], NULL, withdraw, (void *)(i + 1));
		pthread_create(&thread2[i], NULL, deposit, (void *)(i + 1));
	}
	for (int i = 0; i < n; i++)
	{
		pthread_join(thread1[i], &w);
		printf("Thread %ld withdraw complete\n", (long)w);
		pthread_join(thread2[i], &d);
		printf("Thread %ld deposit complete\n", (long)d);
	}
	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&is_ready);
	return 0;
}