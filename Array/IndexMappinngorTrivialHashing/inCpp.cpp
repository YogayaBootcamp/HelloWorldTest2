// CPP program to implement direct indnex mappinng with negative values allowed.
#include <iostream>
using namespace std;
#define MAX 10

// Since array is global, it is initialized as 0.
bool has[MAX + 1][2];

bool search(int x) {
	if (x >= 0) {
		if (has[x][0] == 1)
			return true;
		else
			return false;
	}
	// x is negative. take the absolute value of x
	x = abs(x);
	if (has[x][1] == 1)
		return true;

	return false;
}

void insert(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i] >= 0)
			has[arr[i]][0] = 1;
		else
			has[abs(arr[i])][1] = 1;
	}
}

int main(int argv, char* argc[]) {
	// cout << argv << "\n";
	int size = argv - 2;
	int arr[size];

	for (int i = 0; i < size; i++)
		arr[i] = atoi(argc[i + 1]);

	int num = atoi(argc[argv - 1]);
	
	cout << "Array: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
        
	cout << "\n" << num << "\n";
	
	insert(arr, size);
	for(int i = 0; i < MAX + 1; i++)
		cout << i << " " << has[i][0] << " " << has[i][1] << "\n";
	
	search(num) ? cout << "Present!\n" : cout << "Not Present!\n"; 

	return 0;
}
