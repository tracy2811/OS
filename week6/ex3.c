#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigint_handler(int signal) {
	printf("\nYou've sent a SIGINT signal... Exit!\n");
	exit(EXIT_SUCCESS);
}

int main() {
	// New action
	struct sigaction new_sigint_action;
	new_sigint_action.sa_handler = sigint_handler;
	sigaction(SIGINT, &new_sigint_action, NULL);

	printf("Press Ctrl-C to see efect...\n");
	// Waiting for SIGINT to print message then exit
	for(;;);
}
