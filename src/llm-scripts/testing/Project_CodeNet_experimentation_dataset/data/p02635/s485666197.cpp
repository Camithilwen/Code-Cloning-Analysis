#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

const int mod=998244353,N=305;
int nm,m,n,f[N][N][N],ans,sum[N],a[N];
char s[N];

signed main(){
	scanf("%s",s+1);read(m);
	n=strlen(s+1);s[++n]='0';
	for(int i=1;i<=n;i++){
		if(s[i]=='0') nm++;
		else a[nm+1]++;
	}
	for(int i=1;i<=nm;i++) sum[i]=sum[i-1]+a[i];
	m=min(m,sum[nm]);
	f[0][0][0]=1;
	for(int i=1;i<=nm;i++) 	for(int j=sum[i];j<=sum[nm];j++){
		int lim=min(j,sum[nm]-sum[i-1]);
		for(int k=0;k<=m;k++) for(int bi=0;bi<=lim;bi++) if(max(0,bi-a[i])<=k)
			f[i][j][k]=(f[i][j][k]+f[i-1][j-bi][k-max(0,bi-a[i])])%mod;
	}
	for(int i=0;i<=m;i++) ans=(ans+f[nm][sum[nm]][i])%mod;
	write(ans);
}