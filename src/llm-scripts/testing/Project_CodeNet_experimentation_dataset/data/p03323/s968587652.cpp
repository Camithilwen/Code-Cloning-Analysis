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
	int x, y;
	cin >> x >> y;
	if (x <= 8 && y <= 8) {
		cout << "Yay!" << endl;
	}
	else {
		cout << ":(" <<endl;
	}

	return 0;
}

