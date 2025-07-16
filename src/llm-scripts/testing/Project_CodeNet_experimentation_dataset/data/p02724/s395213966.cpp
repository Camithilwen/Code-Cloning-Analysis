#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;
double condition = 0.0;

void func()
{
	int X;
	cin >> X;
	int Y, Z;
	Y = X / 500;
	Z = (X % 500) / 5;

	cout << 1000 * Y + Z * 5 << endl;
}

int main() {
//	while(1)
	func();
	return 0;
}
