#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define DIR_PATH "./tmp/"
#define OUT_FILE "ex4.txt" 
#define MAX_SIZE 255

int main(int argc, char *argv[]) {
	errno = 0;
	DIR *dirp = opendir(DIR_PATH);
	if (dirp == NULL) {
		fprintf(stderr, "Can not open directory %s: %s\n", DIR_PATH, strerror(errno));
		return errno;
	}
	struct dirent *dp;
	struct stat sb;
	char full_name[MAX_SIZE];
	FILE *fp = fopen(OUT_FILE, "w");
	if (fp == NULL) {
		fprintf(stderr, "Cannot open output file %s: %s\n", OUT_FILE, strerror(errno));
		return errno;
	}
	while ((dp = readdir(dirp)) != NULL) {
		snprintf(full_name, sizeof(full_name), "%s%s", DIR_PATH, dp->d_name); 
;
		if (stat(full_name, &sb) == -1) {
			fclose(fp);
			fprintf(stderr, "Cannot retrieve information about %s: %s\n", full_name, strerror(errno));
			return errno;
		} else if (sb.st_nlink >= 2) {
			fprintf(fp, "%s\n", full_name);
		}
	}
	fclose(fp);
	if (errno) {
		fprintf(stderr, "Cannot read directory %s: %s\n", DIR_PATH, strerror(errno));
		return errno;
	}
	return 0;
}
