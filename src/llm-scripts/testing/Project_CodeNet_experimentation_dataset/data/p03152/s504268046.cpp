#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define inf 0x3f3f3f3f
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

int N, M, A[1005], B[1005];
ll ans = 1;

int main(){
	getint(N), getint(M);
	for(register int i = 1; i <= N; i++) getint(A[i]);
	for(register int i = 1; i <= M; i++) getint(B[i]);
	sort(A + 1, A + N + 1), sort(B + 1, B + M + 1), A[N + 1] = B[M + 1] = inf;
	for(register int i = 1; i < N; i++) if(A[i] == A[i + 1]) return puts("0"), 0;
	for(register int i = 1; i < M; i++) if(B[i] == B[i + 1]) return puts("0"), 0;
	for(register int i = 1, j = 1, k = 1; i <= N * M; i++){
		while(j <= N && A[j] < i) j++;
		while(k <= M && B[k] < i) k++;
		if(A[j] == i && B[k] != i) ans = ans * (M - k + 1) % MOD;
		else if(A[j] != i && B[k] == i) ans = ans * (N - j + 1) % MOD;
		else if(A[j] != i && B[k] != i) ans = ans * ((M - k + 1) * (N - j + 1) - (N * M - i)) % MOD;
	}
	return printf("%lld\n", ans), 0;
}