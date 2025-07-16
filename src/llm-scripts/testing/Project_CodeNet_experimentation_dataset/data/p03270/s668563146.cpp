#include<cstdio>
#include<algorithm>
using std::max;
#define int long long
const int mod=998244353;
int K,n,_2[5010],C[5010][5010];
signed main(){
	scanf("%lld%lld",&K,&n);
	C[0][0]=1;
	for(int i=1;i<=5000;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	_2[0]=1;
	for(int i=1;i<=5000;i++)
		_2[i]=_2[i-1]*2%mod;
	for(int i=2;i<=2*K;i++)
		if(i&1){
			int y=abs(K-i+1),x=(K-y)/2,ans=0;
			for(int j=0;j<=x;j++)
				(ans+=C[x][j]*_2[j]%mod*C[n+y-1][j+y-1]%mod)%=mod;
			printf("%lld\n",ans);
		}
		else{
			int y=abs(K-i+1),x=(K-y)/2,ans=0;
			for(int j=0;j<=x;j++)
				(ans+=C[x][j]*_2[j]%mod*(C[n+y-1][j+y-1]+C[n+y-2][j+y-1])%mod)%=mod;
			printf("%lld\n",ans);
		}
}