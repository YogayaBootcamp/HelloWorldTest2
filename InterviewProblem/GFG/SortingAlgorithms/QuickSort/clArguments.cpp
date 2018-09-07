#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	cout << "You have entered " << argc
	     << " arguments:" << "\n";

	for (int i = 0; i < argc; ++i)
		cout << argv[i] << "\n";
	int size = argc - 1;	
	int arr[size];

	for (int i = 0; i < size; ++i)
		arr[i] = atoi(argv[i+1]);
	
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	
	cout << "\n";
	return 0;
}
