#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
	// Declare i, f and d as int, float and double variables
	int i;
	float f;
	double d;

	// Assign maximum value for i, f d
	i = INT_MAX;
	f = FLT_MAX;
	d = DBL_MAX;

	// Print sizes and values of i, f and d
	printf("INT_MAX = %d\t size = %lu\n", i, sizeof(i));
	printf("FLT_MAX = %g\t size = %lu\n", f, sizeof(f));
	printf("DBL_MAX = %g\t size = %lu\n", d, sizeof(d)); 
	
	return 0;
}
