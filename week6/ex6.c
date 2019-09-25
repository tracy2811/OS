#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main() {
	int fd[2];	// file descriptors to pipe
	pid_t cpid1;	// 1st child pid

	// create pipe
	if (pipe(fd) != 0) {
		fprintf(stderr, "Pipe Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	// Fork two chill processes
	printf("Fork 1st child...\n");
	if ((cpid1 = fork()) == -1) {
		fprintf(stderr, "Fork Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	if (cpid1 == 0) {	// Child 1 
		// Read cpid2 from pipe
		pid_t cpid2;
		close(fd[1]);	// close unused write end
		read(fd[0], &cpid2, sizeof(cpid2));
		printf("1st child received 2nd child's pid (%d)\n", (int)cpid2);

		// Wait for 10s
		printf("1st child waiting for 10s...\n");
		sleep(10);

		// Send SIGSTOP to 2nd child
		printf("1st child sending SIGSTOP to the 2nd child...\n");
		kill(cpid2, SIGSTOP);
		_exit(EXIT_SUCCESS);

	} else {		// parent
		// Create 2nd child
		printf("Fork 2nd child...\n");
		pid_t cpid2;
		if ((cpid2 = fork()) == -1) {
			fprintf(stderr, "Fork error: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}

		if (cpid2 == 0) {	// Child 2
			printf("2nd child running...\n");
			for(;;);

		} else {		// Parent
			// Parent writes cpid2 to pipe
			close(fd[0]);	// Close unused read end
			write(fd[1], &cpid2, sizeof(cpid2));
			printf("Parent sent 2nd child's pid (%d) to 1st child\n", (int)cpid2);

			// Wait for 2nd child stop
			printf("Parent waiting for 2nd child...\n");
			waitpid(cpid2, NULL, WUNTRACED);

			// 2nd child changed state
			printf("2nd child stopped. Exit!\n");
			exit(EXIT_SUCCESS);
		}
	}
}	
