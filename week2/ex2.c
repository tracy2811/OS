#include <stdio.h>
#include <string.h>

#define MAX_LEN 500

// Prompt for string, print its reverse
int main(void) {
	// Variable to store string
	char s[MAX_LEN];

	// Read string from stdin
	if (fgets(s, MAX_LEN, stdin) != NULL) {
		// Print reverse of string s
		for (int i = strlen(s) - 1; i >=0 ; --i) 
			putchar(s[i]);
		return 0;
	}

	// Reading error
	return 1; 	
}
