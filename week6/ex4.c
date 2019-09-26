#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int signal) {
	printf("\nSignal catched! Exit!\n");
	exit(EXIT_SUCCESS);
}

int main() {
	struct sigaction new_action;
	new_action.sa_handler = handler;
	// Declare signal handlers for SIGKILL, SIGSTOP, SIGUSR1;
	sigaction(SIGKILL, &new_action, NULL);
	sigaction(SIGSTOP, &new_action, NULL);
	sigaction(SIGUSR1, &new_action, NULL);

	// Waiting for signals
	for(;;);
}
