#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// Create a child process
int main(int argc, char *argv[]) {
	for (int i = 0; i < 5; ++i) {
		fork();
		sleep(5);
	}
}
