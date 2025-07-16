#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long ans = 0, before;
	cin >> before;
	bool HasNoAns = (before > 0);
	for (int i = 1; i < N; i++) {
		int now;
		cin >> now;
		if (now == 0) {
			before = now;
			continue;
		}
		if (now == before + 1) ans++;
		else {
			if (now <= before) ans += now;
			else HasNoAns = true;
		}
		before = now;
	}
	cout << (HasNoAns ? -1 : ans) << endl;
}