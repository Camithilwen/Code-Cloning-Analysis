#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9 * 2;

int main() {
	int a[3];
	rep(i, 3) cin >> a[i];
	int k;
	cin >> k;
	sort(a, a + 3, greater<int>());
	ll out = a[0] * pow(2, k) + a[1] + a[2];
	cout << out << endl;
}
