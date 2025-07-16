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
	int h, w,n,tmp=0;
	cin >> h >> w >> n;
	REP(i, max(h,w)) {
		tmp += max(h, w);
		if (n <= tmp) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}

