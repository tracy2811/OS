#include <stdio.h>

// swap function
void swap(int *a, int *b) {
	int t = *b;
	*b = *a;
	*a = t;
}

// read 2 integers and swaps
int main(void) {
	int a, b;
	// Read a and b
	if (scanf("%d %d", &a, &b) == 2) {
		// Swap a and b
		swap(&a, &b);
		// Print a and b
		printf("%d %d\n", a, b);
		return 0;
	}
	// Reading error
	return 1;	
}
