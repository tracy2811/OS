// Quick sort: Lomuto partition scheme

int partition(int *arr,int lo,int hi) {
	int pivot = arr[hi], temp;
	int i = lo;
	for (int j = lo; j <= hi; ++j)
		if (arr[j] < pivot) {
			// swap arr[i] with arr[j]
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			++i;
		}
	// swap arr[i] with arr[hi]
	temp = arr[hi];
	arr[hi] = arr[i];
	arr[i] = temp;
	return i;
}

void quicksort(int *arr, int lo, int hi) {
	if (lo < hi) {
		int p = partition(arr, lo, hi);
		quicksort(arr, lo, p-1);
		quicksort(arr, p+1, hi);
	}
}

// Test quicksort implementation
#include <stdio.h>
int main() {
	int arr[] = {0, 7, 1, 9, -12, -3, 14, 5};
	quicksort(arr, 0, 7);
	for (int i = 0; i <= 7; ++i)
		printf("%d ", arr[i]);
	return 0;
}
