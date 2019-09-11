#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define BUF 200

int main(int argc, char *argv[]) {
	// User command 
	char command[BUF+1];

	printf("> ");
	// Read command and execute
	while (fgets(command, BUF, stdin) != NULL) {
		// Remove newline
		if (command[strlen(command)-1] == '\n')
			command[strlen(command)-1] = '\0';

		// Create new process
		pid_t pid = fork();
		int status;

		if (pid == -1) {	// fork failed
			printf("\nFork failed");
		} else if (pid == 0) {	// child
			execlp(command, command, (char *) 0);
		} else {		// parent
			if (command[strlen(command)-1] == '&') {	//Background
				printf("> ");
				continue;
			}
			waitpid(pid, &status,0);
			printf("> ");
		}
	}

	return 0;
}	
