#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main() {
	// Strings to pipe
	char string1[] = "I'm not an empty string.\n";
	char string2[100];
	// file descriptors to the ends of pipe
	int fd[2];
	// child process id
	pid_t cpid;

	// create pipe
	if (pipe(fd) != 0) {
		fprintf(stderr, "Pipe Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	cpid = fork();
	if (cpid == -1) {
		fprintf(stderr, "Fork Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	if (cpid == 0) {	// Child reads from pipe 
		close(fd[1]);	// close unused write end
		read(fd[0], string2, sizeof(string2));
		printf("Received string: %s", string2);
		_exit(EXIT_SUCCESS);

	} else {		// Parent writes to pipe
		close(fd[0]);	// Close unused read end
		write(fd[1], string1, (strlen(string1)+1));
		printf("Sent string: %s", string1);
		wait(NULL);	// Wait for child reading string
		exit(EXIT_SUCCESS);
	}
}	
