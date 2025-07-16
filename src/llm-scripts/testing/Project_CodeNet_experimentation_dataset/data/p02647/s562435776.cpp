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
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> A(n);
	for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
	for (int i = 0; i < k; ++i) {
		vector<int> D(n + 1);
		for (int j = 0; j < n; ++j) {
			D[max(0, j - A[j])]++;
			D[min(n, j + A[j] + 1)]--;
		}
		bool no = false;
		for (int i = 0; i < n; ++i) {
			if (i) A[i] = A[i - 1];
			else A[i] = 0;
			A[i] += D[i];
			if (A[i] < n) no = true;
		}
		if (!no) break;
	}
	for (int i = 0; i < n; ++i) printf("%d ", A[i]);
}
