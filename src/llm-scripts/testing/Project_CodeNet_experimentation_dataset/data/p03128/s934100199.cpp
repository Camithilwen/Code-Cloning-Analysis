#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N, M; cin >> N >> M;
	vector<pair<int, bool>> num(10);
	for (int a = 1; a <= 9; a++) {
		int p = 0;
		if (a == 1)p = 2;
		if (a == 7)p = 3;
		if (a == 4)p = 4;
		if (a == 2 || a == 3 || a == 5)p = 5;
		if (a == 6 || a == 9)p = 6;
		if (a == 8)p = 7;
		num[a].first = p;
	}

	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		num[a].second = true;
	}

	vector<int> dp(N + 1, -1000);
	dp[0] = 0;
	int po = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= 9; j++) {
			if (num[j].second && i + num[j].first <= N) {
				dp[i + num[j].first] = max(dp[i + num[j].first], dp[i] + 1);
				if (dp[i + num[j].first] > 0) po = max(po, i + num[j].first);
			}
		}
	}

	//cout << "after dp" << endl;
	vector<int> ans;
	while (po != 0) {
		for (int i = 9; i >= 1; i--) {
			if (po - num[i].first >= 0 && num[i].second && dp[po] - 1 == dp[po - num[i].first]) {
				ans.push_back(i);
				po -= num[i].first;
				break;
			}
		}
		//cout << "po=" << po << endl;
	}

	//reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size() ; i++) {
		cout << ans[i];
	}
	cout << endl;
}