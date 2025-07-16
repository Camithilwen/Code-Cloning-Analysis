#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long ll;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

inline int fastpow(int bas, int ex){
	register int res = 1;
	for(; ex; ex >>= 1, bas = bas * (ll)bas % MOD) if(ex & 1) res = res * (ll)bas % MOD;
	return res;
}

inline int kazu(int a, const int &b) {return (a += b) >= MOD ? a - MOD : a;}
inline int hiku(int a, const int &b) {return (a -= b) < 0 ? a + MOD : a;}

int N, A = 0, a[500005], sum0[500005], ans = 0;
int nxt[1 << 20], head[1 << 20], id[500005], top, cnt0[1000005], f[1000005][2];

inline int calc_even(const int &x){
	if(head[x] > N) return 0; id[top = 1] = head[x];
	while(nxt[id[top]] <= N) id[top + 1] = nxt[id[top]], top++;
	register int M = 0;
	for(register int i = 1; i <= top; i++){
		cnt0[++M] = -1;
		if(i < top) cnt0[++M] = sum0[id[i + 1]] - sum0[id[i]];
	}
	f[0][0] = 1, f[0][1] = 0;
	for(register int i = 1; i <= M; i++){
		if(cnt0[i] == -1) f[i][0] = f[i - 1][0], f[i][1] = kazu(f[i - 1][1], f[i - 1][0]);
		else f[i][1] = f[i - 1][1], f[i][0] = kazu(f[i - 1][0], f[i - 1][1] * (ll)cnt0[i] % MOD);
	}
	return f[M][1];
}

inline int calc_odd(const int &x){
	if(head[x] > N) return 0; id[top = 1] = head[x];
	while(nxt[id[top]] <= N) id[top + 1] = nxt[id[top]], top++;
	register int M = 0;
	for(register int i = 1; i < top; i++){
		cnt0[++M] = -1;
		cnt0[++M] = sum0[id[i + 1]] - sum0[id[i]];
	}
	f[0][0] = 1, f[0][1] = 0;
	for(register int i = 1; i <= M; i++){
		if(cnt0[i] == -1) f[i][0] = f[i - 1][0], f[i][1] = kazu(f[i - 1][1], f[i - 1][0]);
		else f[i][1] = f[i - 1][1], f[i][0] = kazu(f[i - 1][0], f[i - 1][1] * (ll)cnt0[i] % MOD);
	}
	return f[M][0];
}

int main(){
	getint(N);
	for(register int i = 1; i <= N; i++) getint(a[i]), A = max(A, a[i] ^= a[i - 1]);
	for(register int i = 1; i <= N; i++) sum0[i] = sum0[i - 1] + (a[i] == 0);
	for(register int i = 0; i <= A; i++) head[i] = N + 1;
	for(register int i = N; i; i--) nxt[i] = head[a[i]], head[a[i]] = i;
	if(a[N]) ans = calc_odd(a[N]);
	else{
		ans = fastpow(2, sum0[N] - 1);
		for(register int i = 1; i <= A; i++) ans = kazu(ans, calc_even(i));
	}
	return printf("%d\n", ans), 0;
}