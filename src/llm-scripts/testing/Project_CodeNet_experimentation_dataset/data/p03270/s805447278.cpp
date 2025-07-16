#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 998244353
using namespace std;
typedef long long ll;

ll ppow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=(res*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
ll C[5000][5000];

int main(){
	for(int i=0;i<5000;i++){
		for(int j=0;j<=i;j++){
			if(j==0||j==i)C[i][j]=1;
			else C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
		}
	}
	int k,n;scanf("%d%d",&k,&n);
	for(int i=2;i<=2*k;i++){
		int cnt1=0,cnt2=0;
		for(int j=1;j<=k;j++){
			if(j<i&&j<i-j&&i-j<=k)cnt1++;
			if(j>=i||i-j>k)cnt2++;
		}
		ll ans=0;
		for(int j=0;j<=cnt1;j++){
			if(j+cnt2==0)continue;
			(ans+=C[n-j+(j+cnt2-1)][j+cnt2-1]*ppow(2,j)%MOD*C[cnt1][j]%MOD)%=MOD;
			if(i%2==0)(ans+=C[n-j+(j+cnt2-1)-1][j+cnt2-1]*ppow(2,j)%MOD*C[cnt1][j]%MOD)%=MOD;
		}
		printf("%lld\n",ans);
	}
}