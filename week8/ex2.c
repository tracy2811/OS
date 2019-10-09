#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define	MEM_SIZE 10485760	// 10MB

int main() {
	for (int i = 0; i < 10; ++i) {
		// Allocate 10MB
		void *ptr = malloc(MEM_SIZE);
		if (ptr != NULL) {
			// Fill allocated memmory with zeros
			memset(ptr, 0, MEM_SIZE); 
		} else {
			// Failed to callocate memory
			fprintf(stderr, "Cannot allocate memory\n");
			exit(EXIT_FAILURE);
		}
		sleep(1);
	}
	exit(EXIT_SUCCESS);
}
