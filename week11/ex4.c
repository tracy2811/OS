#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
	char *src, *dest;
	struct stat buf;

	// Open ex1.txt, ex1.memcp.txt
	int srcfd = open("ex1.txt", O_RDONLY);
	int destfd = open("ex1.memcp.txt", O_CREAT | O_RDWR);
	if (srcfd == -1 || destfd == -1) {
		fprintf(stderr, "Cannot open file: %s\n", strerror(errno));
		return -1;
	}

	// get ex1.txt status
	if (fstat(srcfd, &buf)) {
		fprintf(stderr, "Cannot get file status: %s\n", strerror(errno));
		return -1;
	}

	// mmap
	src = mmap(NULL, buf.st_size, PROT_READ, MAP_SHARED, srcfd, 0);
	ftruncate(destfd, buf.st_size);
	dest = mmap(NULL, buf.st_size, PROT_WRITE, MAP_SHARED, destfd, 0);
	if (src == MAP_FAILED || dest == MAP_FAILED) {
		fprintf(stderr, "Cannot map: %s\n", strerror(errno));
		return -1;
	}

	// write to dest 
	memcpy(dest, src, buf.st_size);

	// return	
	munmap(src, buf.st_size);
	munmap(dest, buf.st_size);
	close(srcfd);
	close(destfd);
	return 0;
}
