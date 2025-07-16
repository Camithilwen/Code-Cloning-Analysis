#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int hour[3];
	cin >> hour[0] >> hour[1] >> hour[2];
	int ans = 1000;
	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 3; j++) {
			ans = min(ans, hour[i] + hour[j]);
		}
	}
	cout << ans << endl;
	return 0;
}