#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5 + 2, LOG = 17, INF = 1e8;
char s[MN];
int wot[MN];
int main () { 
	int n;
	scanf ("%d",&n);
	auto nxt = [&] (int a) {int x = a + 1; return x > n ? 1 : x;};
	auto lst = [&] (int a) {int x = a - 1; return x < 1 ? n : x;};
	scanf ("%s",s+1);
	for (int a = 0; a < 2; a++) {
		for (int b = 0; b < 2; b++) {
			wot[1] = a; wot[2] = b;
			for (int i = 3; i <= n; i++) {
				if ((s[i-1] == 'o' && wot[i-1] == 0) || (s[i-1] == 'x' && wot[i-1] == 1)) wot[i] = wot[i-2];
				else wot[i] = wot[i-2] ^ 1;
			}
			bool ok = 1;
			for (int i = 1; i <= n; i++) {
				if ((s[i] == 'o' && wot[i] == 0) || (s[i] == 'x' && wot[i] == 1)) ok &= wot[nxt(i)] == wot[lst(i)];
				else ok &= wot[nxt(i)] != wot[lst(i)];
			}
			if (ok) {
				for (int i = 1; i <= n; i++) putchar(wot[i]?'W':'S');
				return 0;
			}
		}
	}
	printf ("-1\n");
    return 0;
}
