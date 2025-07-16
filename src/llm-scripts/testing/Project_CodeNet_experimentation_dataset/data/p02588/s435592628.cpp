// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef long double LD;
typedef long long LL;

int main(int argc, char* argv[]) {
	LL n, nfc = 0, fc = 0, ans = 0;
	cin >> n;
	vector<vector<int>> sum(20, vector<int>(20));
	vector<int> two(n), five(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		bool p = false;
		LL x = 0;
		for (char c : s) {
			if (c == '.') {
				p = true;
			} else {
				x = (x * 10) + c - '0';
				two[i] -= p;
				five[i] -= p;
			}
		}
		while (x % 2 == 0) {
			++two[i];
			x /= 2;
		}
		while (x % 5 == 0) {
			++five[i];
			x /= 5;
		}
		sum[min(two[i], 9) + 10][min(five[i], 9) + 10] += 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = -10; j < 10; ++j) {
			for (int k = -10; k < 10; ++k) {
				if (j + two[i] >= 0 && k + five[i] >= 0) {
					ans += sum[j + 10][k + 10];
				}
			}
		}
		ans -= two[i] >= 0 && five[i] >= 0;
	}
	cout << ans / 2 << endl;
	return 0;
}
