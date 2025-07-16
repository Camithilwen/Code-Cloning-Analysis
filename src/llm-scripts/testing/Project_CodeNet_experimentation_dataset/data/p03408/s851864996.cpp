#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;

	map<string, int>ma;

	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		ma[tmp]++;
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		ma[tmp]--;
	}

	int ans = 0;

	for (auto itr : ma) {
		ans = max(itr.second, ans);
	}

	cout << ans << endl;
}