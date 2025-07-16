#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& x) {
	return os << "(" << x.first << "," << x.second << ")";
}
typedef long long ll;
typedef long double ld;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> a(m), b;
	vector<int> odds;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &a[i]);
		if (a[i] & 1) odds.push_back(i);
	}
	if (odds.size() > 2) printf("Impossible\n");
	else {
		sort(odds.begin(), odds.end());
		if (odds.size() == 1) {
			swap(a[odds[0]], a[0]);
			b = a;
			--b[0];
			b.push_back(1);
		} else if (odds.size() == 2) {
			swap(a[odds[0]], a[0]);
			swap(a[odds[1]], a[m - 1]);
			b = a;
			--b[0];
			++b[m - 1];
		} else {
			b = a;
			--b[0];
			b.push_back(1);
		}
		for (int x : a) printf("%d ", x);
		printf("\n");
		if (b[0] == 0) b.erase(b.begin());
		printf("%d\n", b.size());
		for (int x : b) printf("%d ", x);
		printf("\n");
	}
}
