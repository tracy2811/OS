#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5	// Number of threads to create

int global = 10;	// Global variabe to observe when thread executes

// Function for thread
void *thread_func(void *threadid) {
	long tid = (long)threadid;
	int private = 10;	// Thread's private variable
	
	// Observe behavior of global and private variables
	global++; 
	private++;

	printf("Hello from thread #%ld\n", tid);
	printf("Global: %d\tPrivate: %d\n\n", global, private);

	pthread_exit(NULL);
}

// Create threads, print text and integer, exit
int main() {
	pthread_t threads[NUM_THREADS];	// To save thread id

	for (int i = 0; i < NUM_THREADS; i++) {
		// Create thread
		if (pthread_create(threads+i, NULL, thread_func, (void *)i)) {
			printf("Error: unable to create thread\n");
			exit(EXIT_FAILURE);
		}
		
		// Join thread to force it to execute in order as created
		if (pthread_join(threads[i], NULL)) {
			printf("Error: unable to join thread\n");
			exit(EXIT_FAILURE);
		}
	}

	pthread_exit(NULL);
	exit(EXIT_SUCCESS);
}
