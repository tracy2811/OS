#include <stdio.h>
#include <stdlib.h>

#define BUF 200

int main(int argc, char *argv[]) {
	// User command 
	char command[BUF+1];

	printf("> ");
	// Read command and execute
	while (fgets(command, BUF, stdin) != NULL) {
		system(command);
		printf("> ");
	}

	return 0;
}	
