#include <stdio.h>

int main() {
	char buf[21];

	// Open /dev/random and ex1.txt 
	FILE *in = fopen("/dev/random", "r");
	FILE *out = fopen("./ex1.txt", "w");
	if (in == NULL || out == NULL) {
		perror("Cannot open file(s)\n");
		return -1;
	}

	// Copy 20 characters from /dev/random to ex1.txt and stdout
	fgets(buf, 21, in);
	fprintf(out, "%s", buf);
	printf("%s", buf);

	// Close /dev/random and ex1.txt
	fclose(in);
	fclose(out);

	// return
	return 0;
}
