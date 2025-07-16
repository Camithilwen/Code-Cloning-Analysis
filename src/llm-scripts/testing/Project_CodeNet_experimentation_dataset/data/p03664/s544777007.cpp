#include <bits/stdc++.h> 
using namespace std;

#define sz(x) (int)x.size() 
#define pb push_back 
#define mp make_pair 
#define fi(a, b) for(int i=a; i<=b; i++) 
#define fj(a, b) for(int j=a; j<=b; j++) 
#define fo(a, b) for(int o=a; o<=b; o++) 
#define fdi(a, b) for(int i=a; i>=b; i--) 
#define fdj(a, b) for(int j=a; j>=b; j--) 
#define fdo(a, b) for(int o=a; o>=b; o--) 

#ifdef LOCAL
#define err(...) fprintf(stderr, __VA_ARGS__)
#else
#define err(...) while(false) {}
#endif

typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef vector<int> vi; 
typedef vector<ll> vll;
typedef vector<pii> vpii; 
typedef vector<pll> vpll; 
typedef long double ld;
typedef unsigned long long ull;

/////////////////////////////////

int const MAX = 15;

int n, m;
int e[MAX][MAX];

int d1[(1 << MAX)];
int d2[(1 << MAX)][MAX];

bool bit(int m, int i) {
	return (1 & (m >> i));
}

void init() {
	for (int mask = 0; mask < (1 << n); mask++) {
		fi(0, n - 1) {
			fj(i + 1, n - 1) {
				if (bit(mask, i) && bit(mask, j)) {
					d1[mask] += e[i][j];
				}
			}
		}
	}

	for (int mask = 0; mask < (1 << n); mask++) {
		fo(0, n - 1) {
			fi(0, n - 1) {
				if (bit(mask, i)) {
					d2[mask][o] += e[i][o];
				}
			}
		}
	}
}

int d[(1 << MAX)][MAX];
int const INF = 1e9 + 41;

int ans;
int sum;

int getbest(int comp, int path) {
	int res = 0;

	fi(0, n - 1) {
		if (bit(path, i)) {
			res = max(res, d2[comp][i]);
		}
	}
	
	res += d1[comp];
	return res;
}

void solve() {
	init();
	for (int mask = 0; mask < (1 << n); mask++) {
		fo(0, n - 1) {
			d[mask][o] = -INF;
		}
	}
	d[(1 << (n - 1)) - 1][n - 1] = 0;

	for (int mask = (1 << n) - 1; mask > 0; mask--) {
		fo(0, n - 1) {
			if (d[mask][o] < 0) continue;
			fi(0, n - 1) {
				if (e[i][o] && bit(mask, i)) {
					int nmask = (mask ^ (1 << i));
					d[nmask][i] = max(d[nmask][i], d[mask][o] + e[i][o]);
				}
			}
			int sm = mask;
			while (sm > 0) {
				int nmask = (mask ^ sm);
				int pathmask = ( ((1 << n) - 1) ^ mask);
				int bs = getbest(sm, pathmask);
				d[nmask][o] = max(d[nmask][o], d[mask][o] + bs);
				sm = ((sm - 1) & mask);
			}
		}
	}

	ans = sum - d[0][0];
	err("d = %d sum = %d\n", d[0][0], sum);
	printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

  scanf("%d %d", &n, &m);
  fi(1, m) {
  	int x, y, w;
  	scanf("%d %d %d", &x, &y, &w);
  	x--;
  	y--;
  	e[x][y] = e[y][x] = w;
  	sum += w;
  }
	solve();		

	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}