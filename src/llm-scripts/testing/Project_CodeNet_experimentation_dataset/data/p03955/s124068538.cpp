#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MN = 100010;

int N;
int a[3][MN];
pii b[MN];
ll flip[2], inv[2];

template<class T>
class BIT {
	T bit[MN];
	int n;

public:
	BIT() {
		n = N + 10;
		memset(bit, 0, sizeof(bit));
	}

	T sum(int i) {
		++i;
		T s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}

	void add(int i, T x) {
		++i;
		while (i < n) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int main() {
	cin >> N;

	rep(i, 3) {
		rep(j, N) {
			cin >> a[i][j];
			--a[i][j];
		}
	}

	rep(i, N) {
		if (a[1][i] == a[0][i] + 1 && a[2][i] == a[0][i] + 2) {
			b[i] = mp(a[0][i] / 3, 0);
		} else if (a[1][i] == a[0][i] - 1 && a[2][i] == a[0][i] - 2) {
			b[i] = mp(a[0][i] / 3, 1);
		} else {
			puts("No");
			return 0;
		}
		if (i % 4 >= 2) {
			b[i].se ^= 1;
		}
		if (b[i].fi % 2 != i % 2) {
			puts("No");
			return 0;
		}
	}

	BIT<int> T[2];

	rep(i, 2) { //parity
		for (int j = i; j < N; j += 2) {
			flip[i] += (b[j].se != (b[j].fi % 4 >= 2));
			inv[i] += T[i].sum(N) - T[i].sum(b[j].fi);
			T[i].add(b[j].fi, 1);
		}
	}

	puts(inv[0] % 2 == flip[1] % 2 && inv[1] % 2 == flip[0] % 2 ? "Yes" : "No");

	return 0;
}