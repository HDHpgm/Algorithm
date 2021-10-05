#include <stdio.h>

void main() {
	int arr[] = { 6, 0, 8, 2, 3, 0, 4, 0, 1 };
	int arrSize = sizeof(arr) / sizeof(int);

	int j = 0;

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] != 0) {
			arr[j] = arr[i];
			j++;
		}
	}

	for (int i = j; i < arrSize; i++)
		arr[i] = 0;

	for (int i = 0; i < arrSize; i++) {
		printf("%d ", arr[i]);
	}
}