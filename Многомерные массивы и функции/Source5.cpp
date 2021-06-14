
/*Напишите программу, в которой объявляется массив размером 5х10 и массив размером 5х5.
Первый массив заполняется случайными числами, в диапазоне от 0 до 50. Второй массив
заполняется по следующему принципу : первый элемент второго массива равен сумме первого и
второго элемента первого массива, второй элемент второго массива равен сумму третьего и
четвертого элемента первого массива.*/
#include <random>
#include <iostream>
#include <iomanip>
using namespace std;
class Random {
public:
	Random() {
		random_device device;
		random_generator_.seed(device());
	}
	int next(int first, int last) {
		uniform_int_distribution<int> range(first, last);
		return range(random_generator_);
	}
	double next(double first, double last) {
		uniform_real_distribution<double> range(first, last);
	}
private:
	mt19937 random_generator_;
};
int main() {
	const auto five = 5U;
	const auto ten = 10U;
	Random rand;
	int ma[five][ten];
	for (auto& row : ma) for (auto& value : row) value = rand.next(0, 50);
	for (const auto& row : ma) {
		for (auto value : row) cout << setw(4U) << value;
		cout.put('\n');
	}
	cout.put('\n');
	int mb[five][five];
	auto beg = &mb[0U][0U];
	for (auto i = 0U; i < five; ++i) {
		for (auto j = 1U; j < ten; j += 2U) {
			*beg = ma[i][j - 1U] + ma[i][j];
			++beg;
		}
	}
	for (const auto& row : mb) {
		for (auto& value : row) cout << setw(8U) << value;
		cout.put('\n');
	}
	system("pause > nul");
}