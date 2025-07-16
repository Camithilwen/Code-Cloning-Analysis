#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
#include <numeric>
#include<stdio.h>
#include <queue>
#include <iomanip>
#include <float.h>
#include <set>
#include<functional>
#include <stack>
#include <time.h>
#include <climits>
#include <bitset>
using namespace std;
int  gcd(int a, int b) {
	if (a < b) gcd(b, a);
	int r;
	while ((r = a%b)) {
		a = b;
		b = r;
	}
	return b;
}
long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

long long modinv(long long a, long long mod) {
	long long b = mod, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t*b; swap(a, b);
		u -= t*v; swap(u, v);
	}
	u %= mod;
	if (u < 0) u += mod;
	return u;
}
namespace NTT {
	const int MOD = 998244353;  // to be set appropriately
	const long long PR = 3;     // to be set appropriately

	void trans(vector<long long> &v, bool inv = false) {
		int n = (int)v.size();
		for (int i = 0, j = 1; j < n - 1; j++) {
			for (int k = n >> 1; k >(i ^= k); k >>= 1);
			if (i > j) swap(v[i], v[j]);
		}
		for (int t = 2; t <= n; t <<= 1) {
			long long bw = modpow(PR, (MOD - 1) / t, MOD);
			if (inv) bw = modinv(bw, MOD);
			for (int i = 0; i < n; i += t) {
				long long w = 1;
				for (int j = 0; j < t / 2; ++j) {
					int j1 = i + j, j2 = i + j + t / 2;
					long long c1 = v[j1], c2 = v[j2] * w % MOD;
					v[j1] = c1 + c2;
					v[j2] = c1 - c2 + MOD;
					while (v[j1] >= MOD) v[j1] -= MOD;
					while (v[j2] >= MOD) v[j2] -= MOD;
					w = w * bw % MOD;
				}
			}
		}
		if (inv) {
			long long inv_n = modinv(n, MOD);
			for (int i = 0; i < n; ++i) v[i] = v[i] * inv_n % MOD;
		}
	}

	// C is A*B
	vector<long long> mult(vector<long long> A, vector<long long> B) {
		int size_a = 1; while (size_a < A.size()) size_a <<= 1;
		int size_b = 1; while (size_b < B.size()) size_b <<= 1;
		int size_fft = max(size_a, size_b) << 1;

		vector<long long> cA(size_fft, 0), cB(size_fft, 0), cC(size_fft, 0);
		for (int i = 0; i < A.size(); ++i) cA[i] = A[i];
		for (int i = 0; i < B.size(); ++i) cB[i] = B[i];

		trans(cA); trans(cB);
		for (int i = 0; i < size_fft; ++i) cC[i] = cA[i] * cB[i] % MOD;
		trans(cC, true);

		vector<long long> res((int)A.size() + (int)B.size() - 1);
		for (int i = 0; i < res.size(); ++i) res[i] = cC[i];
		return res;
	}
};
template<class V, int ME> class BIT {
public:
	V bit[1 << ME];
	V operator()(int e) { if (e<0) return 0; V s = 0; e++; while (e) s += bit[e - 1], e -= e&-e; return s; }
	void add(int e, V v) { e++; while (e <= 1 << ME) bit[e - 1] += v, e += e&-e; }
};
typedef pair<int, int>p;
vector<int>graph[100005];
int nyuuji[100005] = { 0 };
int parent[100005];
void dfs(int now) {
	vector<int>child;
	for (int i = 0; i < graph[now].size(); i++) {
		nyuuji[graph[now][i]] -= 1;
		if (nyuuji[graph[now][i]] == 0) {
			child.push_back(graph[now][i]);
			parent[graph[now][i]] = now;
		}
	}
	for (int i = 0; i < child.size(); i++) {
		dfs(child[i]);
	}
}
int doubutu[100005];
int next( int now,int prev,int ans) {
	if (doubutu[now]) {
		ans = 1 - ans;
	}
	if (ans) {
		return doubutu[prev];
	}
	else return 1 - doubutu[prev];
}
long long mod = 1e9 + 7;
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	long long vsum = 0;
	long long hsum = 0;
	long long tmp1, tmp2;
	cin >> tmp1;
	for (int i = 2; i <= n; i++) {
		cin >> tmp2;
		long long nagasa = tmp2 - tmp1;
		vsum += ((nagasa*(i - 1)) % mod)*(n - i + 1);
		vsum %= mod;
		tmp1 = tmp2;
	}
	cin >> tmp1;
	for (int i = 2; i <= m; i++) {
		cin >> tmp2;
		long long nagasa = tmp2 - tmp1;
		hsum += ((nagasa*(i - 1)) % mod)*(m - i + 1);
		hsum %= mod;
		tmp1 = tmp2;
	}
	cout << (hsum*vsum) % mod;
}