#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	ll N; cin >> N;
	bool isPrime = true;
	vector<ll> div;
	for(ll i = 1; i * i <= N; i++) {
		if(N % i == 0) {
			if(i != 1) isPrime = false;
			div.push_back(i);
		}
	}
	ll n = div.back(), m = N / n;
	string ans = to_string(m);
	cout << ans.size() << endl;
	return 0;
}