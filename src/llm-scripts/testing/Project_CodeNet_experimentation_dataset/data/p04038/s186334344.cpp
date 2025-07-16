#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0; char c=getchar(); int flag=1;
	while(!isdigit(c)) { if(c=='-') flag=-1; c=getchar(); }
	while(isdigit(c)) { x=((x+(x<<2))<<1)+(c^48); c=getchar(); }
	return x*flag;
}

const int mod=1e9+7;

int n,k;
int dp[2005][2005];//i个白球，j种颜色 

int fac[4000005],Inv[4000005]; 

int C(int n,int m){
	if(m<0||n<m) return 0;
    return 1ll*(1ll*fac[n]*Inv[m]%mod)*Inv[n-m]%mod; 
}

void exgcd(int a,int b,int &x,int &y){
    if(b==0) { x=1; y=0; return ; }
    exgcd(b,a%b,y,x); y-=a/b*x;
}

int inv(int a){
    int x=0,y=0;
    exgcd(a,mod,x,y);
    return (x%mod+mod)%mod;
}

signed main(){
	fac[0]=1;
	for(int i=1;i<=4000000;i++) fac[i]=1ll*fac[i-1]*i%mod;
	Inv[4000000]=inv(fac[4000000]);
	for(int i=3999999;i>=0;i--) Inv[i]=1ll*Inv[i+1]*(i+1)%mod;
	
    n=read(),k=read();
    if(k==1) { puts("1"); return 0; } 
	dp[0][0]=1;
    
    for(int i=1;i<=n;i++){ 
	    dp[i][0]=1;
		for(int j=1;j<=i;j++){
			dp[i][j]=(dp[i-1][j]+1ll*(1ll*dp[i][j-1]*C(n*k-(j-1)*(k-1)-i-1,k-2))%mod*(n-j+1)%mod)%mod; 
		} 
	}
	
	printf("%d\n",dp[n][n]);
    return 0;
}
