#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>

#define	MEM_SIZE 10485760	// 10MB

int main() {
	struct rusage usage;
	for (int i = 0; i < 10; ++i) {
		// Allocate 10MB
		void *ptr = malloc(MEM_SIZE);

		if (ptr != NULL) {
			// Allocated successfully
			// Fill allocated memmory with zeros
			memset(ptr, 0, MEM_SIZE); 

			// Print memory usage
			if (getrusage(RUSAGE_SELF, &usage) == 0) {
				printf("%ldKB\n", usage.ru_maxrss);
			} else {
				fprintf(stderr, "Cannot get memory usage: %s\n", strerror(errno));
				exit(EXIT_FAILURE);
			} 

		} else {
			// Failed to callocate memory
			fprintf(stderr, "Cannot allocate memory\n");
			exit(EXIT_FAILURE);
		}
		sleep(1);
	}
	exit(EXIT_SUCCESS);
}
