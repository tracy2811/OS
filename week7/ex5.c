/* 
Segmentation fault caused by using pointer to pointer (s) before allcating memory for it
Every change in the code goes with comment
*/

#include <stdio.h>
#include <stdlib.h> 	// Lib for malloc

int main() {
	char **s;
	char foo[] = "Hello World";

	/* we must allocate memory for s before we can use */
	s = malloc(sizeof(char *));

	*s = foo;

	/* 
		printf("s is %s\n", s);
	will print s and will not cause segmentation fault.
	However, the output will be unreadble, so change %s to %p (standard)
	*/
	printf("s is %p\n", s);

	/*string pointed by *s also can be printed out by using */
	printf("*s is %s\n", *s);

	s[0] = foo;
	printf("s[0] is %s\n", s[0]);
	return(0);
}
