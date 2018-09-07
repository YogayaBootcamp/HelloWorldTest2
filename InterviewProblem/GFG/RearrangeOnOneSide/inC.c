#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

void rearrangePosNeg(int arr[], int n) {
	int i = -1;
	for (int j = 0; j < n; j++) {
		if(arr[j] >= 0) {
			i++;
			swap(&arr[i], &arr[j]);
		}	
	}
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void printArr(int arr[], int n) {
	printf("Arr: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(int argc, char* argv[]) {
	int n = argc - 1;
	int arr[n];

	for (int i = 0; i < n; i++) {
		arr[i] = atoi(argv[i+1]);
	}
	printf("Input ");
	printArr(arr, n);
	
	rearrangePosNeg(arr, n);

	printf("Output: ");
	printArr(arr, n);
	return 0;
}
