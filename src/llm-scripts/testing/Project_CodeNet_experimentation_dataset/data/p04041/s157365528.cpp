#include<bits/stdc++.h>
#define int long long
#define rg register
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
const int mod=1e9+7;
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9') f=(c=='-')?-1:1,c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
    return f*x;
}
int f[41][262143+10];
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
main(){
    //file("");
	int n=read(),x=read(),y=read(),z=read(),len=(1<<(x+y+z))-1,res=1<<(x+y+z-1),ans=0;
    res=res|(1<<(y+z-1)),res=res|(1<<(z-1)),f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=len;j++){
			if(f[i-1][j]==0) continue;
			for(int k=1;k<=10;k++){
				int z=(j<<k)|(1<<(k-1));
				z&=len;
				if((z&res)==res) continue;
				f[i][z]=(f[i-1][j]+f[i][z])%mod;
			}
		}
	for(int i=0;i<=len;i++)
		ans=(ans+f[n][i])%mod;
	cout<<(ksm(10,n)-ans+mod)%mod;
    return 0;
}