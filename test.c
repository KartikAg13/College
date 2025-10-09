#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_CHAIRS 5

sem_t customers;
sem_t barber;
pthread_mutex_t mutex;
int waiting_chairs;
int all_customers_served = 0;

void *barber_thread(void *arg)
{
    int total_customers = *(int *)arg;
    int served_count = 0;

    while (served_count < total_customers)
    {
        printf("Barber is sleeping...\n");
        sem_wait(&customers);

        pthread_mutex_lock(&mutex);
        waiting_chairs++;
        printf("Barber woke up. Available waiting chairs: %d\n", waiting_chairs);
        sem_post(&barber);
        pthread_mutex_unlock(&mutex);

        printf("Barber is cutting hair.\n");
        sleep(2);
        printf("Barber finished cutting hair.\n");
        served_count++;
    }
    all_customers_served = 1;
    printf("Barber is closing the shop.\n");
    return NULL;
}

void *customer_thread(void *arg)
{
    long id = (long)arg;
    sleep(rand() % 5);

    printf("Customer %ld arrived.\n", id);
    pthread_mutex_lock(&mutex);

    if (waiting_chairs > 0)
    {
        waiting_chairs--;
        printf("Customer %ld sat in a waiting chair. Available chairs: %d\n", id, waiting_chairs);

        sem_post(&customers);
        pthread_mutex_unlock(&mutex);

        sem_wait(&barber);
        printf("Customer %ld is getting a haircut.\n", id);
    }
    else
    {
        pthread_mutex_unlock(&mutex);
        printf("Customer %ld left, no chairs available.\n", id);
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    int num_customers = 10;
    if (argc > 1)
    {
        num_customers = atoi(argv[1]);
    }

    pthread_t barber_tid;
    pthread_t customer_tids[num_customers];

    waiting_chairs = MAX_CHAIRS;

    sem_init(&customers, 0, 0);
    sem_init(&barber, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    printf("Shop is open with %d waiting chairs.\n", MAX_CHAIRS);

    pthread_create(&barber_tid, NULL, barber_thread, &num_customers);

    for (long i = 0; i < num_customers; i++)
    {
        pthread_create(&customer_tids[i], NULL, customer_thread, (void *)(i + 1));
    }

    for (int i = 0; i < num_customers; i++)
    {
        pthread_join(customer_tids[i], NULL);
    }

    while (!all_customers_served)
    {
        if (sem_trywait(&customers) == 0)
        {
            // Drain any remaining signals to unblock the barber
        }
        else
        {
            sleep(1);
        }
    }

    pthread_join(barber_tid, NULL);

    sem_destroy(&customers);
    sem_destroy(&barber);
    pthread_mutex_destroy(&mutex);

    return 0;
}
