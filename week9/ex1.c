#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct frame {
	unsigned char age;	// 8 bits
	int page_number;
}*frames;

long n_frames;		// number of page frames
FILE *input;		// point to reference 
long hit = 0;		// number of hits
long miss = 0;		// number of misses

// Allocate memory for frames and initialize age (counter) to 0
void init_frames() {
	// Allocate memory
	frames = malloc(n_frames*sizeof(struct frame));
	if (frames == NULL) {
		exit(EXIT_FAILURE);
	}

	// Initialize age and page_number
	for (long i = 0; i < n_frames; ++i) {
		frames[i].age = 0;
		frames[i].page_number = -1;
	}
}

// Open reference file
void open_file(char *name) {
	input = fopen(name, "r");
	if (input == NULL) {
		fprintf(stderr, "Cannot open input file.\nExit!\n");
		free(frames);
		exit(EXIT_FAILURE);
	}
}

// Check parameters and get n_frames
void get_n_frames(int argc, char *argv[]) {
	char *endptr;
	errno = 0;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s number_of_frames\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	n_frames = strtol(argv[1], &endptr, 10);

	// Invalid input
	if (errno == ERANGE || endptr == argv[1]) {
		fprintf(stderr, "Usage: %s number_of_frames\n", argv[0]);
		exit(EXIT_FAILURE);
	}
}

// Aging alogrithm
void update_frames(int next_page) {
	// update ages
	long min_index = 0;
	for (long i = 0; i < n_frames; ++i) {
		if (frames[i].age < frames[min_index].age) {
			min_index = i;
		}
		frames[i].age = frames[i].age >> 1;
	}

	// check hit/miss and update
	for (long i = 0; i < n_frames; ++i) {
		if (frames[i].page_number == next_page) {
			// Hit
			frames[i].age = frames[i].age | (1 << 7);
			hit++;
			return;
		}
	}
	// Miss
	miss++;
	frames[min_index].age = 1 << 7;
	frames[min_index].page_number = next_page;
}

// print hit-miss
void print_hit_miss() {
	printf("Hits\t%ld\n", hit);
	printf("Misses\t%ld\n", miss);
	printf("Hits:Misses\t%ld\n", hit/(double)miss);
}

int main(int argc, char *argv[]) {
	// Initialize
	get_n_frames(argc, argv);
	init_frames();
	open_file("input.txt");	

	// Aging algorithm
	int next_page;
	while (fscanf(input, "%d", &next_page) != EOF) {
		update_frames(next_page);
	}

	print_hit_miss();

	// Exit
	free(frames);
	exit(EXIT_SUCCESS);
}
