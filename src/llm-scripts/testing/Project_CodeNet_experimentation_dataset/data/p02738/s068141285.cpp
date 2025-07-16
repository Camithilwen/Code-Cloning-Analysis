#include<bits/stdc++.h>
#define re register
int f[6010][9030],mod;
int main()
{
	re int n;
	scanf("%d%d",&n,&mod);
	f[0][6010]=1;
	for(re int i=0;i<3*n;i++)
	{
		for(re int j=-i;j<=i/2;j++)
		if(f[i][j+6010]){
			f[i+1][j-1+6010]=(f[i+1][j-1+6010]+f[i][j+6010])%mod;
			f[i+2][j+1+6010]=(f[i+2][j+1+6010]+1ll*f[i][j+6010]*(i+1))%mod;
			f[i+3][j+6010]=(f[i+3][j+6010]+1ll*(i+2)*(i+1)*f[i][j+6010])%mod;
		}
	}
	re int ans=0;
	for(re int i=-3*n;i<=0;i++)ans=(ans+f[3*n][i+6010])%mod;
	printf("%d\n",ans);
}