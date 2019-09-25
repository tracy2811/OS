#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main() {
	struct sigaction new_action;
	// Declare signal handlers for SIGKILL, SIGSTOP, SIGUSR1;
	sigaction(SIGKILL, &new_action, NULL);
	sigaction(SIGSTOP, &new_action, NULL);
	sigaction(SIGUSR1, &new_action, NULL);

	for(;;);
	exit(EXIT_SUCCESS);
}
