#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	ll n,a,mins = INF;
	cin >> n;
	rep(i, 5) {
		cin >> a;
		mins = min(mins, a);
	}
	cout << fixed << setprecision(0)<< ceil((double)n / mins) + 4 << endl;
	return 0;
}

