#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
	char *addr;
	struct stat buf;

	// Open ex1.txt
	int fd = open("ex1.txt", O_RDWR);
	if (fd == -1) {
		fprintf(stderr, "Cannot open file: %s\n", strerror(errno));
		return -1;
	}

	// get file status
	if (fstat(fd, &buf)) {
		fprintf(stderr, "Cannot get file status: %s\n", strerror(errno));
		return -1;
	}

	// mmap
	addr = mmap(NULL, buf.st_size, PROT_WRITE, MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED) {
		fprintf(stderr, "Cannot %s\n", strerror(errno));
		return -1;
	}

	// write "This is a nice day" to file
	strncpy(addr, "This is a nice day", buf.st_size);

	// return	
	munmap(addr, buf.st_size);
	close(fd);
	return 0;
}
