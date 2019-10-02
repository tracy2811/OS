#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// realloc function by using malloc and free
void *my_realloc(void *ptr, size_t size) {
	if (ptr == NULL) {
		// Equivalent to malloc()
		return malloc(size);

	} else if (size == 0) {
		// Equivalent to free()
		free(ptr);
		return NULL;

	} else {
		// Allocate new array 
		char *new = malloc(size);

		// Copy content to new array
		if (new) {
			memcpy(new, (char *)ptr, size);
		}

		// Free ptr
		free(ptr);
		return new;
	}
}

// Function to print array of integer, used for testing
void print_int_arr(int *arr, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Simple program to test my_realloc()
int main() {
	// Test for realloc
	printf("Ininital Array: ");
	int *arr = calloc(10, sizeof(int));
	print_int_arr(arr, 10);

	printf("Increased-size Array: "); 
	arr = my_realloc(arr, 15*sizeof(int));
	print_int_arr(arr, 15);

	printf("Decreased-size Array: ");
	arr = my_realloc(arr, 5*sizeof(int));
	print_int_arr(arr, 5);

	printf("Free Array!\n");
	arr = my_realloc(arr, 0);

	printf("Array: ");
	arr = my_realloc(NULL, 10*sizeof(int));
	print_int_arr(arr, 10);

	return 0;
}
