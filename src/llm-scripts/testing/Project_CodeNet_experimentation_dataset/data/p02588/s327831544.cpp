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
#define TE 2e6+5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N; cin >> N;
	vector<vector<ll>> cnt(64, vector<ll>(30));
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		ll temp = 0;
		int len = s.size(), tens = 0;
		bool flag = false;
		for (int j = 0; j < len; j++) {			
			if (s[j] != '.') {
				temp *= 10;
				temp += s[j] - '0';
				if (flag) tens++;
			}
			else flag = true;
			
		}
		
		for (int i = 0; i < 9 - tens; i++)temp *= 10;
		//cout << "temp=" << temp << endl;
		int two = 0, five = 0;
		while (temp % 2 == 0) {
			two++, temp /= 2;
		}
		while (temp % 5 == 0) {
			five++, temp /= 5;
		}
		cnt[two][five]++;
		//cout << "two=" << two << " five=" << five << endl;
	}

	ll ans = 0;
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 30; j++) {
			for (int a = max(0,18 - i); a < 64; a++) {
				for (int b = max(0,18 - j); b < 30; b++) {
					ans += cnt[i][j] * (cnt[a][b] + (i == a && j == b ? -1 : 0));
					//if (cnt[i][j] > 0 && cnt[a][b])
						//cout << "i=" << i << " j=" << j << " a=" << a << " b=" << b << " ans=" << ans << endl;
				}
			}

		}
	}
	cout << ans / 2 << endl;

}
