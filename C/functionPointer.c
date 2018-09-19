#include <stdio.h>

// A normal function with an int paramter and void return type
void fun(int a) {
	printf("Value of a is %d\n", a);
}

int main() {
	// fun_ptr is a pointer to function fun()
	/* or
		void (*fun_ptr)(int);
		fun_ptr = &fun;
	*/
	void (*fun_ptr)(int) = &fun; // bracket is needed. void *fun_ptr(int) becomes declaration of a function that return void pointer as operator () takes precedence over *.
	
	(*fun_ptr)(10);
	return 0;
}
