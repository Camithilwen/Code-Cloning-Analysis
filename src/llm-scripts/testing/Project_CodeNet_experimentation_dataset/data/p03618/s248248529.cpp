
// B - Reverse and Compare

#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1000000007;
// using mint = modint1000000007;
// const ll MOD = 998244353;
// using mint = modint998244353;

int main() {
	string A;
	cin >> A;

	unordered_map<char, int> cnt;

	for (char c : A) {
		cnt[c]++;
	}

	ll N = A.size();
	ll ans = N * (N-1) / 2 + 1;

	for (auto itr : cnt) {
		ll n = itr.second;
		ans -= n * (n-1) / 2;
	}

	cout << ans << endl;

	return 0;
}