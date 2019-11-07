#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int n_file = 0;
	int fd[argc];
	char append = 0;
	char c;

	// Read arguments
	if (argc >=2 ) {
		for (int i = 1; i < argc; ++i) {
			if (strcmp(argv[i], "-a") == 0) {
				append = 1;
			} else {
				fd[n_file] = i;
				n_file++;
			}
		}
	}

	// Read file descriptors from arguments
	for (int i = 0; i < n_file; ++i) {
		if (append) {
			fd[i] = open(argv[fd[i]], O_CREAT | O_RDWR | O_APPEND, 0664);
		} else {
			fd[i] = open(argv[fd[i]], O_CREAT | O_RDWR, 0664);
		}
		if (fd[i] == -1) {
			perror("Cannot open file(s) to write!\n");
			return -1;
		}
	}
	fd[n_file] = STDOUT_FILENO;
	
	// Read stdin, write to stdout and files
	while (read(STDIN_FILENO, &c, 1) > 0) {
		for (int i = 0; i <= n_file; ++i) {
			write(fd[i], &c, 1);
		}
	}

	// Close files
	for (int i = 0; i < n_file; ++i) {
		close(fd[i]);
	}
	return 0;
}
