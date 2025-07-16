#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
#define rint register int
#define gc() getchar()
inline int read(rint ans = 0, rint sgn = ' ', rint ch = gc())
{
	for(; ch < '0' || ch > '9'; sgn = ch, ch = gc());
	for(; ch >='0' && ch <='9';(ans*=10)+=ch-'0', ch = gc());
	return sgn-'-'?ans:-ans;
}
char T[305]; int n, K, f[305][305][305]; inline int Cmax(int &x, int v){x < v ? x = v : 0;}
int main()
{
	scanf("%s",T+1), n = strlen(T+1), K = read();
	for(rint i = 1, k; i <= n; i++) for(k = 0; k <= K; f[i][i][k] = 1, k++);
	for(rint d = 2, l, r, k; d <= n; d++)
		for(l = 1, r = d; r <= n; l++, r++)
			for(k = 0; k <= K; k++)
			{
				Cmax(f[l][r][k],f[l][r-1][k]);
				Cmax(f[l][r][k],f[l+1][r][k]);
				T[l]==T[r] ? Cmax(f[l][r][k],f[l+1][r-1][k]+2) : 0;
				k ? Cmax(f[l][r][k],f[l+1][r-1][k-1]+2) : 0;
				k ? Cmax(f[l][r][k],f[l][r][k-1]) : 0;
			}	printf("%d\n",f[1][n][K]); return 0;
}