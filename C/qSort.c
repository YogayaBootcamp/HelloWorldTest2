// An example for qsort and comparator
#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b) {
	return ( *(int *)a - *(int *)b );
}

void printArr(int arr[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);

	printf("\n");
}

int main(int argv, char *argc[]) {
	int size = argv - 1;
	int arr[size];
	for(int i = 0; i < size; i++)
		arr[i] = atoi(argc[i + 1]);
	
	printArr(arr, size);

	qsort (arr, size, sizeof(int), compare);

	printArr(arr, size);

	return 0;
}
