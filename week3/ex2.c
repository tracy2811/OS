void bubble_sort(int *arr, int len) {
	char swap = 1;

	while (swap) {
		swap = 0;
		for (int i = 0; i < len-1; ++i) {
			if (arr[i] > arr[i+1]) {
				// swap arr[i] and arr[i+1]
				swap = 1;
				int temp = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = temp;
			}
		}
	}	
}
