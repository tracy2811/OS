#include <stdio.h>
#include <stdlib.h>

#define TRI_1 1
#define TRI_2 2
#define REC 3

// Print right-side-up triangle
void triangle1(int n) {
	for (int i = 1; i < n; ++i) {
		int n_spaces, n_stars;
		n_spaces = n - i;
		n_stars = 2*i - 1;

		while (n_spaces--) 
			putchar(' ');
		while (n_stars--)
			putchar('*');
		putchar('\n');
	}
}

// Print right triangle
void triangle2(int n) {
	for (int i = 1; i < n; ++i) {
		for (int k = 0; k < i; ++k)
			putchar('*');
		putchar('\n');
	}
}

// Print rectangle
void rectangle(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <=n; ++k) 
			putchar('*');
		putchar('\n');
	}
}

// Handle error function
void error_msg(void) {
	printf("usage: program number [1|2|3]\n");
	exit(EXIT_FAILURE);
}

// Main function
int main(int argc, char *argv[]) {
	// Read n and option o from command line
	int n, o = TRI_1; 	// TRI_1 is default option;
	// Check error
	if (argc != 3 && argc != 2)
		error_msg();
	if (argc == 3 && sscanf(argv[2], "%d", &o) != 1)
		error_msg();
	if (sscanf(argv[1], "%d", &n) != 1)
		error_msg();

	// Print as requested
	switch(o) {
		case TRI_1:
			triangle1(n);
			break;
		case TRI_2:
			triangle2(n);
			break;
		case REC:
			rectangle(n);
			break;
		default:
			error_msg();	
	}

	return EXIT_SUCCESS;
}
