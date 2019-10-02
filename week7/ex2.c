#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;
	int *arr;

	// Prompt for n
	do {
		printf("Enter N: ");
		scanf("%d", &n);
		printf("\n");
 	} while (n <= 0);

	// Allocate and initialize arr
	arr = malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i) {
		arr[i] = i;
	}

	// Print array
	printf("Our array: ");
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	// Deallocate memory
	free(arr);

	exit(EXIT_SUCCESS);
}
