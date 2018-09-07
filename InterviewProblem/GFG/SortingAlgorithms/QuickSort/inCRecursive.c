/* C implementation QuickSort */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A utility function to swap two elements
void swap (int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places the pivot element at its correct position in sorted array,
 * and places all smaller (smaller than pivot) elements to left of pivot
 * and places all greater (greater than pivot) elements to right of pivot */
int partition (int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1); // index of smaller element

	for (int j = low; j <= high - 1; j++) {
		// If current element is smaller than or equal to pivot
		if (arr[j] <= pivot) {
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
 * arr[] --> Array to be sorted
 * low   --> Starting index
 * high  --> Ending index */
void quickSort (int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


// A utility function to check whether x is numeric
bool isNumericChar(char x) {
	return (x >= '0' && x <= '9') ? true : false;
}

/* A simple atoi() function. If the given string contains any invalid character, then this function returns 0. 
 * Time complexity: O(n) where n is the number of characters in input string.
 * */
int myAtoi(char *str) {
	if (*str == NULL)
		return 0;

	int res = 0;
	int sign = 1;
	int i = 0;

	if(str[0] == '-') {
		sign = -1;
		i++;
	}

	for(; str[i] != '\0'; ++i) {
		if(isNumericChar(str[i]) == false)
			return 0;
		res = res*10 + str[i] - '0';
	}
	
	return sign * res; 
}

/* Command line arguments in C/C++
 * argc: (ARGument Count) number of command line arguments passed by user including the name of the program. Value of argc should be non negative.
 * argv: (ARGument Vector) array of character pointers listing all the arguments. If argc is greater than zero, the array elements from 
 * argv[0] to argv[argc - 1] will contain pointer to strings.
 * argv[0] is the name of the program, after that till argv[argc - 1] every element is command line argument.
 * 
 * int main(int argc, char** argv)
 * */
int main(int argc, char *argv[]) {
	int n = argc - 1;
	int arr[n];
	for(int i = 0; i < n; i++)
		arr[i] = myAtoi(argv[i+1]); //arr[i] = atoi(argv[i+1]);

	quickSort(arr, 0, n-1);
	printf("Sorted array: ");
	printArray(arr, n);
	return 0;
}
