#include <stdio.h>

using ll = long long;
const int MX = 1000005, MM = 998244353;

ll F[MX], I[MX], IF[MX];

ll C(int x,int y){return F[x+y]*IF[x]%MM*IF[y]% MM;}

int main()
{
	int N, M, i;
	I[1]=F[0]=IF[0]=F[1]=IF[1]=1;
	for(i = 2; i < MX; i++){
		I[i] = (MM - MM/i) * I[MM%i] % MM;
		F[i] = F[i-1] * i % MM;
		IF[i] = IF[i-1] * I[i] % MM;
	}

	scanf("%d%d", &N, &M);
	if( N > M ) N^=M^=N^=M;
	ll ans = M, tot = IF[N+M] * F[N] % MM * F[M] % MM;
	for(i = 1; i <= N; i++){
		ans = (ans + tot * C(N-i, M-i) % MM * C(i, i) % MM * I[2]) % MM;
	}
	printf("%lld\n", ans);
}

