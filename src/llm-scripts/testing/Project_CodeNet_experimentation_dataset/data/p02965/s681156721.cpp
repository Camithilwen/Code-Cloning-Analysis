#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=2000005;
const int mod=998244353;
int fact[Maxn],ivf[Maxn];
int qp(int x,int p){
	int ret=1;
	while (p){
		if (p&1) ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
		p>>=1; 
	}
	return ret;
}
int inv(int x){
	return qp(x,mod-2);
}
int C(int x,int y){
	return 1ll*fact[x]*ivf[y]%mod*ivf[x-y]%mod;
}
void _init(){
	fact[0]=1;
	for (int i=1;i<Maxn;i++){
		fact[i]=1ll*fact[i-1]*i%mod;
		ivf[i]=inv(fact[i]);
	}
	ivf[0]=1;
}
int main(){
	_init();
	int n,m;
	scanf("%d %d",&n,&m);
	int ans=0;
	for (int i=m;i>=0;i-=2){
		if (i>n) continue;
		int rem=(3*m-i)/2;
		ans+=1ll*C(n,i)*C(rem+n-1,n-1)%mod;
		if (ans>=mod) ans-=mod;
	}
//	cout<<ans<<endl;
	for (int i=m;i>=0;i-=2){
		if (i>n) continue;
		int rem=(3*m-i)/2;
		rem-=m;
		ans-=1ll*C(n,i)*C(rem+n-1,n-1)%mod*i%mod;
		if (ans<0) ans+=mod;
	}
	for (int i=m;i>=0;i-=2){
		if (i>n) continue;
		int rem=(3*m-i)/2;
		rem-=m+1;
		if (rem<0) continue;
		ans-=1ll*C(n,i)*C(rem+n-1,n-1)%mod*(n-i)%mod;
		if (ans<0) ans+=mod;
	}
	printf("%d\n",ans);
	return 0;
}