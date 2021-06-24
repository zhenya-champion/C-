#include <iostream>
#include "queue.h"
#include <time.h>

int main() {
	srand(time(0));
	Queue Q(25);
	for (size_t i = 0; i < 10; i++) {
		Q.Add(rand() % 100, rand()%3);
	}
	Q.Show();
	auto temp = Q.Extract(1);
	if (temp)
	std::cout << "extracted element is " << *temp << '\n';
	else
	std::cout << "extracted element is " << *temp << '\n';
	Q.Show();
}