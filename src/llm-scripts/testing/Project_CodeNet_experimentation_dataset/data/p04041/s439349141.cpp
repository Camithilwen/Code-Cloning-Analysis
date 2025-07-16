#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int mod=1000000007;
int f[42][1<<18],n,x,y,z,i,j,k,lim,tmp;
signed main()
{
	cin>>n>>x>>y>>z;
	tmp=(1<<(x+y+z-1));
	tmp|=(1<<(y+z-1));
	tmp|=(1<<(z-1));
	lim=(1<<(x+y+z))-1;
	f[0][0]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<=lim;j++){
			if(f[i-1][j]==0) continue;
			for(k=1;k<=10;k++){
				int now=((j<<k)|(1<<(k-1)));
				now&=lim;
				if((now&tmp)!=tmp) f[i][now]=(f[i][now]+f[i-1][j])%mod;
			}
		}
	}
	int ans=1;
	for(i=1;i<=n;i++) ans=ans*10%mod;
	for(i=0;i<=lim;i++) ans=(ans-f[n][i]+mod)%mod;
	cout<<ans<<endl;
	return 0;
}
