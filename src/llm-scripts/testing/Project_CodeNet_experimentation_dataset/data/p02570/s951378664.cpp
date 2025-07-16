#include <iostream>
#include <string>

using namespace std;

int main() {

	int d, t, s, minute;
	cin >> d >> t >> s;

	if (d % s) {
		minute = d / s + 1;
	}
	else {
		minute = d / s;
	}

	if (minute <= t)
		std::cout << "Yes\n";
	else
		std::cout << "No\n";

	return 0;
}