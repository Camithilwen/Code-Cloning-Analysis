#include <iostream>


using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;
	int max = a + b;
	if (a - b > max)
		max = a - b;
	if (a*b > max)
		max = a * b;
	cout << max;
}