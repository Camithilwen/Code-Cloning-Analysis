#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2000+10,mod=1e9+7;
ll f[maxn][maxn];
ll s[maxn*maxn+10],invs[maxn*maxn+10];
int n,m;
inline void read(int &x){
	char c=getchar();
	int f=1;
	x=0;
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
inline long long ksm(ll x,int y){
	ll sum=1;
	while(y){
		if(y&1){sum=(sum*x)%mod;}
		y/=2;
		x=(x*x)%mod;
	}
	return sum%mod;
}
inline ll cal(int x,int y){
	//cout<<s[x]<<" "<<s[y]<<endl;
	ll sum2=1,sum1=1,sum=0;
	//for(register int i=1;i<=y;i++)sum1=(sum1*i)%mod;
	//for(register int i=x-y+1;i<=x;i++)sum2=(sum2*i)%mod;
	//sum2=s[x];sum1=(s[x-y]*s[y])%mod;
	//sum=(sum2*ksm(sum1,mod-2))%mod;
	sum=((s[x]*invs[y])%mod*invs[x-y])%mod;
	//cout<<sum<<endl;
	return sum%mod;
}
int main(){
	int i,j,k;
	read(n);read(m);
	//cout<<n<<" "<<m<<endl;
	if(m==1){cout<<1<<endl;return 0;}
	f[0][0]=1;
	s[0]=1;
	//for(register int i=1;i<=n;i++)f[i][0]=1;
	for(register int i=1;i<=maxn*maxn;i++){s[i]=(s[i-1]*i)%mod;}
	invs[maxn*maxn]=ksm(s[maxn*maxn],mod-2);
	for(register int i=maxn*maxn-1;i>=0;i--)invs[i]=(invs[i+1]*(i+1))%mod;
	for(register int i=1;i<=n;i++)
		for(register int j=0;j<=i;j++){
			if(!j)f[i][j]=f[i-1][j]%mod;
			else f[i][j]=(f[i-1][j]+((f[i][j-1]*(n-j+1))%mod*cal(n*m-(j-1)*(m-1)-i-1,m-2)))%mod;
		}
	cout<<f[n][n]<<endl;
	return 0;
}