#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define MOD 998244353
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 2500100

long long kai[N];
long long rkai[N];
long long xx[30];
int yy[30];

void kaiz(void) {
	kai[0] = 1;
	f(i, N - 1) {
		kai[i + 1] = kai[i] * (i + 1);
		kai[i + 1] = kai[i + 1] % MOD;
	}
	int x = MOD - 2;
	f(i, 30) {
		if (x % 2 == 1)yy[i] = 1;
		else yy[i] = 0;
		x = x / 2;
	}
	f(i, N) {
		xx[0] = kai[i];
		f(j, 29) {
			xx[j + 1] = xx[j] * xx[j];
			xx[j + 1] = xx[j + 1] % MOD;
		}
		rkai[i] = 1;
		f(j, 30) {
			if (yy[j] == 1) {
				rkai[i] = rkai[i] * xx[j];
				rkai[i] = rkai[i] % MOD;
			}
		}
	}
}

long long ni(long long x, long long y) {
	if (x < 0 || y<0 || y>x)return 0;
	long long re = kai[x];
	re = re * rkai[x - y];
	re = re % MOD;
	re = re * rkai[y];
	re = re % MOD;
	return re;
}


int main() {
	long long q, n, m, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	kaiz();

	scanf("%lld %lld", &n, &m);
	k = m % 2;
	s = 0;
	for (long long i = 0; i <= ((m - k) / 2); i++) {
		x = ni(n - 2 + i, n - 2);
		s = (s + x) % MOD;
	}
	ans = 0;
	while (k <= m&&k<=n) {
		x = (3 * m) - k;
      x=x/2;
		x = ni(x + n - 1, n - 1);
		y = (n * s) % MOD;
		x = (x - y + MOD) % MOD;
		y = (m - k) / 2;
		y = ni(n + y - 2, n - 2);
		y = (y*(n - k)) % MOD;
		x = (x + y) % MOD;

		z = ni(n, k);
		z = (z * x) % MOD;

		ans = (ans + z) % MOD;

		x = (m - k) / 2;
		x = ni(x + n - 2, n - 2);
		s = (s - x + MOD) % MOD;

		k += 2;
	}
	printf("%lld\n", ans);


	return 0;
}