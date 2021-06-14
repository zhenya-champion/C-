#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d, e, f, g, max;

	cin >> a >> b >> c >> d >> e >> f >> g;

	max = a;

	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;
	if (e > max) max = e;
	if (f > max) max = f;
	if (g > max) max = g;

	cout << max;

	return 0;
}