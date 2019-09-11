#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

// Create a child process and print message
int main(int argc, char *argv[]) {
	// Create a child process
	long id = fork();

	if (id == -1)	// Failed to create child process
		printf("Fork failed: %s\n", strerror(errno));
	else if (id == 0)	// Child process
		printf("Hello from child %ld\n", (long)getpid());
	else
		printf("Hello from parent %ld\n", (long)getpid());

	return EXIT_SUCCESS;
}

/* To run program 10 times, use the following code:
for i in {1..10}
do
	./program_name
done
*/
