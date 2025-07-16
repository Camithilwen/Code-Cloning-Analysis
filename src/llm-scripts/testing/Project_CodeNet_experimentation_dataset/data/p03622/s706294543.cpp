#include <cstdio>
#include <algorithm>
using namespace std;

#define iter(i, n) for (int i = 1; i <= n; ++i)
#define iter_r(i, n) for (int i = n; i >= 1; --i)

const int mod = 998244353;

#define NR 1010000
const int N = 1e6 + 10;
int n, m;

struct Int {
	int v;

	Int(int v = 0) : v(v) {}

	void operator+=(Int b) { v = (v + b.v) % mod; }
	void operator-=(Int b) { v = (v - b.v + mod) % mod; }
	void operator*=(Int b) { v = 1ll * v * b.v % mod; }
};

Int fac[NR], inv[NR];

Int operator+(Int a, Int b) { return (a.v + b.v) % mod; }
Int operator-(Int a, Int b) { return (a.v - b.v + mod) % mod; }
Int operator*(Int a, Int b) { return 1ll * a.v * b.v % mod; }

Int F(int n, int m) {
	return fac[n + m] * inv[n] * inv[m];
}

Int pr(Int a, int z) {
	Int s = 1;
	while (z > 0) {
		if (z % 2 == 1) s *= a;
		a *= a;
		z /= 2;
	}
	return s;
}

Int get_inv(Int a) { return pr(a, mod - 2); }

int main() {
	fac[0] = inv[0] = 1;
	iter(i, N) fac[i] = fac[i - 1] * i;
	inv[N] = get_inv(fac[N]);
	iter_r(i, N - 1) inv[i] = inv[i + 1] * (i + 1);

	scanf("%d%d", &n, &m); ++n; ++m;
	if (n > m) swap(n, m);
	Int last = 0, speed = 0, ans = 0;
	int _x = -1;
	const Int tot = F(n - 1, m - 1), tmp0 = F(n - 1, m - 2);
	iter(q, n + m - 2) {
	//	if (q > n - 1 && _x < n - 1) last -= n - 1;
	//	if (q > m - 1) last -= m - 1;		
		if (_x < n - 1) {
			if (q % 2 == 1) {
				++_x;
				int y = q - _x;

				if (_x == 0) {
					speed += F(n - 2, m - 1);
					speed += F(n - 1, m - 2);
				} else {
					//printf("!!\n");
					speed += F(_x, y - 2) * F(n - _x - 1, m - y - 1);
					speed += F(y - 2, _x) * F(m - _x - 1, n - y - 1);
				}
			} else {

				int y = q - _x;
			//	printf("c[%d %d]\n", _x, y);
				speed -= F(_x, y - 2) * F(n - _x - 2, m - y);
				speed -= F(y - 2, _x) * F(m - _x - 2, n - y);
			}
		} else speed = tmp0;
		last += speed;
	//	printf("c%d %d (%d %d %d %d)\n" ,last.v, speed.v, q, n, m, _x);



//		printf("[%d %d]\n", _x, q-_x);
//		printf("!%d %d\n", last.v, tot.v);
		ans += last * get_inv(q);
	}
	printf("%d\n", (ans * get_inv(tot)).v);
	return 0;
}