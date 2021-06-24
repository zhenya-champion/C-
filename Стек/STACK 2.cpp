#include "STACK.h"
#include <iostream>
#include <time.h>

using namespace std;

int main() {
	srand(time(0));
	Stack<int> ST(100);
	char c;
	//пока стек не заполнился
	while (!ST.IsFull()) {
		c = rand() % 29 + 65;
		ST.Push(c);
	}
	//пока стек не освободиться
	std::unique_ptr<int> ptr;
	while (ptr = ST.Pop()) {
		cout << *ptr << " ";
	}
	cout << "\n\n";
}