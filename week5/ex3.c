#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 32		// Maximum value to produce

int top = 0;		// point to top of buf
int buf[MAX];		// buffer to consume/produce

pthread_mutex_t mutex;
pthread_cond_t cond;

// Produce function: increase top by 1
void *producer_func(void *tid) {
	while (1) {
		// Lock mutex
		pthread_mutex_lock(&mutex);

		// Wait for consumer when full
		while (top >= MAX)
			pthread_cond_wait(&cond, &mutex);

		// Produce
		buf[top] = rand()%100;
		printf("Produce: %d\n", buf[top]);
		top++;

		sleep(1); 	// Sleep for 1 sec
		
		// Send signal, release lock
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

// Consumer function: decrease top by 1
void *consumer_func(void *tid) {
	while(1) {
		// Lock mutex
		pthread_mutex_lock(&mutex);

		// Wait for producer when nothing to consume
		while (top <= 0)
			pthread_cond_wait(&cond, &mutex);

		// Consume
		--top;
		printf("Consume: %d\n", buf[top]);

		// Sent signal, release lock
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

// Main function
int main() {
	// Create variables for pthread_t and pthread_attr_t
	pthread_t consumer, producer;
	pthread_attr_t attr;

	// Initialize mutex, cond
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);

	// Create joinable consumer and producer thread
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	pthread_create(&consumer, &attr, consumer_func, (void *)&consumer);
	pthread_create(&producer, &attr, producer_func, (void *)&producer);

	// Join consumer and producer
	pthread_join(consumer, NULL);
	pthread_join(producer, NULL);

	// Clean up
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	pthread_exit(NULL);

	return EXIT_SUCCESS;
}
