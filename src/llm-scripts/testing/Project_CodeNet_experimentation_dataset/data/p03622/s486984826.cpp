#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cmath> 
#include <algorithm> 
using namespace std; 
const int Mod = 998244353; 
int fpow(int x, int y) {
	int res = 1; 
	while (y) {
		if (y & 1) res = 1ll * res * x % Mod; 
		x = 1ll * x * x % Mod; 
		y >>= 1; 
	} 
	return res; 
} 
const int MAX_N = 1e6 + 5; 
int N = 1e6, M, fac[MAX_N], ifc[MAX_N]; 
int C(int n, int m) {
	if (n < m || n < 0 || m < 0) return 0; 
	else return 1ll * fac[n] * ifc[m] % Mod * ifc[n - m] % Mod; 
} 
int main () { 
	for (int i = fac[0] = 1; i <= N; i++) fac[i] = 1ll * fac[i - 1] * i % Mod; 
	ifc[N] = fpow(fac[N], Mod - 2); 
	for (int i = N - 1; ~i; i--) ifc[i] = 1ll * ifc[i + 1] * (i + 1) % Mod; 
	cin >> N >> M; 
	if (N > M) swap(N, M); 
	int ans = 0; 
	for (int i = 1; i <= N; i++) ans = (ans + 1ll * C(i << 1, i) * C(N - i + M - i, N - i)) % Mod; 
	ans = 1ll * ans * fpow(2 * C(N + M, M) % Mod, Mod - 2) % Mod; 
	printf("%d\n", (ans + M) % Mod); 
    return 0; 
} 