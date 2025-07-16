#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	map<string, int>mp;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		mp[s]++;
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		string s;
		cin >> s;
		mp[s]--;
	}
	int ans = 0;
	for (auto x : mp) {
		ans = max(ans, max(0, x.second));
	}
	cout << ans << endl;
	return 0;
}
