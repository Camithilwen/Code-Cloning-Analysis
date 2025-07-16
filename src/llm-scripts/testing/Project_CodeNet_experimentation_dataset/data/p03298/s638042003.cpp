#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,j,mx,t,x,ans,f[19][19],a[19],b[19];
char s[101];
int main(){
	scanf("%lld",&n);
	scanf("%s",s+1);
	mx=1ll<<n;mx--;
	for(t=0;t<=mx;t++){
		a[0]=b[0]=0;
		for(i=n*2;i>n;i--){
			x=n*2-i;
			if(t&(1ll<<x))a[++a[0]]=s[i]-'a';
			 else b[++b[0]]=s[i]-'a';
		}
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(i=1;i<=n;i++){
			for(j=0;j<=min(a[0],i-1);j++){
				if(i-1-j>b[0])continue;
				if(j<a[0]&&s[i]-'a'==a[j+1])f[i][j+1]+=f[i-1][j];
				if(i-j<=b[0]&&s[i]-'a'==b[i-j])f[i][j]+=f[i-1][j];
			}
		}
		ans+=f[n][a[0]];
	}
	printf("%lld",ans);
}