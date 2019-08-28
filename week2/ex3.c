#include <stdio.h>

// Print right-side-up triangle
int main(int argc, char *argv[]) {
	// Read n from command line
	int n;
	if (argc != 2 || sscanf(argv[1], "%d", &n) != 1) {
		printf("usage: program_name number");
		return 1;
	}

	// Print triangle
	for (int i = 1; i <=n; ++i) {
		// Number of spaces and stars to print
		int n_spaces, n_stars;
		n_spaces = n - i;
		n_stars = 2*i - 1;

		// Print spaces and stars to stdout
		while (n_spaces--)
			putchar(' ');
		while (n_stars--)
			putchar('*');
		putchar('\n');
	}

	return 0;
}
