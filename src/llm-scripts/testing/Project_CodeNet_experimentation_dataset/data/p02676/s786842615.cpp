#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll unsigned long long

const ll MOD = 1000000000000000000;

int main() {
	//入力
	int k;
	string s;
	cin >> k >> s;

	//処理
	string ans = s;
	if (s.size() > k) {
		ans = s.substr(0, k) + "...";
	}

	//出力
	cout << ans << endl;

	return 0;
}
