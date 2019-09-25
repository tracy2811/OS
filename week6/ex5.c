#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

int main() {
	pid_t cpid;

	cpid = fork();
	if (cpid == -1) {
		fprintf(stderr, "Fork Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	if (cpid == 0) {	// Child runs infinite loop 
		for(;;) {
			printf("I'm alive\n");
			sleep(1);
		}
	} else {		// Parent waits for 10s then send childs SIGTERM
		sleep(10);
		kill(cpid, SIGTERM);
		exit(EXIT_SUCCESS);
	}
}	
