#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string S;
	cin >> S;
	long long streaks = 0;
	long long max_streaks = 0;
	for (auto s : S) {
		if (s == 'R') {
			++streaks;
		}
		else {
			max_streaks = max(streaks, max_streaks);
			streaks = 0;
		}
	}
	max_streaks = max(streaks, max_streaks);

	cout << max_streaks << endl;
	return 0;
}