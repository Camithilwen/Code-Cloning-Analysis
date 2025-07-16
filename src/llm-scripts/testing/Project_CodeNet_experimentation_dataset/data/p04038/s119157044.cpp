#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define ll long long
#define ld double
#define inf 2001
#define infm inf*inf
#define mod ((ll)1e9+7)
#define INF (int)(1e9) 
#define pi acos(-1)
#define rd(n) {n=0;char ch;int f=0;do{ch=getchar();if(ch=='-'){f=1;}}while(ch<'0'||ch>'9');while('0'<=ch&&ch<='9'){n=(n<<1)+(n<<3)+ch-48;ch=getchar();}if(f)n=-n;}
using namespace std;

ll getinv(ll x){
	ll k=mod-2,ans=1;
	while (k){
		if (k&1){
			ans=ans*x%mod;
		}
		x=x*x%mod;
		k/=2;
	}
	return ans;
}

ll fact[infm],invf[infm];

void prework(int N){
	fact[0]=1;
	for (int i=1;i<=N;i++){
		fact[i]=fact[i-1]*i%mod;
	}
	invf[N]=getinv(fact[N]);
	for (int i=N-1;i>=0;i--){
		invf[i]=invf[i+1]*(i+1)%mod;
	}
	return;
}

ll C(int x,int y){
	return fact[x]*invf[y]%mod*invf[x-y]%mod;
}

ll cal(int x,int y){
	return C(x+y,x);
}

int n,K;
int f[inf][inf];

int main(){
	rd(n) rd(K)
	if (K==1){
		puts("1");
		return 0;
	}
	prework(n*K);
	f[0][0]=1;
	for (int i=1;i<=n;i++){
		ll sum=0;
		for (int j=i;j>=1;j--){
			sum=(sum+f[i-1][j-1])%mod;
			f[i][j]=sum*cal((i-1)*K-j+1,K-2)%mod;
		}
	}
	ll ans=0;
	for (int i=0;i<=n;i++){
		ans=(ans+f[n][i])%mod;
	}
	printf("%lld\n",ans*fact[n]%mod);
	return 0;
}

