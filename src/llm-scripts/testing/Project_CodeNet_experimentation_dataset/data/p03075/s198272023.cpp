#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int antennas[5];
	for (int i = 0; i < 5; i++) cin >> antennas[i];
	int k;
	cin >> k;
	string ans = "Yay!";
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (antennas[j] - antennas[i] > k) ans = ":(";
		}
	}
	cout << ans << endl;
	return 0;
}