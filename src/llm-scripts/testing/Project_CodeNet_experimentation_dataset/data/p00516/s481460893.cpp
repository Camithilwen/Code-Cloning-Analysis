#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> ItemInfo, PersonInfo;

void solve() {
	int curValue;
	int total[1000];

	memset(total, 0, sizeof(total));
	for (int i = 0; i < M; ++i) {
		curValue = PersonInfo[i];
		for (int j = 0; j < N; ++j) {
			if (ItemInfo[j] <= curValue) {
				//cout << "=" << j + 1 << endl;
				++total[j];
				break;
			}
		}
	}

	cout << max_element(total, total + N) - total + 1 << endl;
}

int main() {
	int num;

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		ItemInfo.push_back(num);
	}
	for (int i = 0; i < M; ++i) {
		cin >> num;
		PersonInfo.push_back(num);
	}
	solve();

	return 0;
}
