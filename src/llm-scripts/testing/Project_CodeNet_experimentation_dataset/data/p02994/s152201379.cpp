#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int N, L;
	cin >> N >> L;
	int applepie = 0;
	for (int i = 1; i <= N; i++) {
		applepie += L + i - 1;
	}
	int ans;
	int diff = abs(L + 1 - 1);
	for (int i = 2; i <= N; i++) {
		diff = min(diff, abs(L + i - 1));
	}
	for (int i = 1; i <= N; i++) {
		if (abs(L + i - 1) == diff) ans = applepie - (L + i - 1);
	}
	cout << ans << endl;
	return 0;
}