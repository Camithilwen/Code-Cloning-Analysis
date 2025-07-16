#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double db;
#define go(u) for(int i = head[u], v = e[i].to; i; i=e[i].lst, v=e[i].to)
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define pb push_back
#define re(x) memset(x, 0, sizeof x)
inline int gi() {
    int x = 0,f = 1;
    char ch = getchar();
    while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)) { x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}
template <typename T> inline bool Max(T &a, T b){return a < b ? a = b, 1 : 0;}
template <typename T> inline bool Min(T &a, T b){return a > b ? a = b, 1 : 0;}
const int N = 3e5 + 7;
int n, sz;
int a[4][N], inv[2], flip[2];
int tr[N];
int lowbit(int x) { return x & -x;}
void modify(int x, int y) { for(int i = x; i <= sz; i += lowbit(i)) tr[i] += y;}
int query(int x){ 
	int res = 0;
	for(int i = x; i; i -= lowbit(i)) res += tr[i];
	return res;
}
int main() {
#ifdef fwat
#endif
	n = gi(), sz = n * 3;
	rep(i, 1, 3)
	rep(j, 1, n) a[i][j] = gi();
	
	rep(j, 1, n) {
		int mi = min(a[1][j], min(a[2][j], a[3][j]));
		if(a[1][j] == mi) {
			if(!(a[2][j] == mi + 1 && a[3][j] == mi + 2)) return puts("No"), 0;
		}else if(a[3][j] == mi) {
			flip[j & 1] ^= 1;
			if(!(a[2][j] == mi + 1 && a[1][j] == mi + 2)) return puts("No"), 0;
		}else return puts("No"), 0;
		if(j % 2 == 1 && mi % 6 != 1) return puts("No"), 0;
		if(j % 2 == 0 && mi % 3 != 1) return puts("No"), 0;
	}
	for(int j = 1; j <= n; j += 2) {
		inv[1] ^= query(sz) - query(a[2][j]) & 1;
		modify(a[2][j], 1);
	}
	re(tr);
	for(int j = 2; j <= n; j += 2) {
		inv[0] ^= query(sz) - query(a[2][j]) & 1;
		modify(a[2][j], 1);
	}
	puts(flip[0] == inv[1] && flip[1] == inv[0] ? "Yes" : "No");
	return 0;
}