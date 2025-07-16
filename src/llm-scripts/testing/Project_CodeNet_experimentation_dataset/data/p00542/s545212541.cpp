#include <iostream>
using namespace std;

int main() {
	int numberA[4], b, c, i, min, ans=0;
	for (i = 0; i <= 3; i++) {
		cin >> numberA[i];
		if (i == 0) {
			min = numberA[0];
		}
		if (i > 0) {
			if (numberA[i] < min) {
				min = numberA[i];
			}
			else if (numberA[i] > min) {
				min = min;
			}
			else {
				min = min;
			}
		}
	}
	ans = (numberA[0] + numberA[1] + numberA[2] + numberA[3]) - min;

	cin >> b;
	cin >> c;
	if (b > c) {
		ans += b;
	}
	else if (b < c) {
		ans += c;
	}
	else {
		ans += b;
	}

	cout << ans << endl;

	return 0;
}
