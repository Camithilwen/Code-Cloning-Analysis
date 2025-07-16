#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int D,l,cnt[100];
ll pw[100],v[100];

int getlen(ll x){
	int len=0;
	while(x)++len,x/=10;
	return len;
}

ll dfs(int i,ll now){
	if(i==l/2)return now==D;
	ll ret=0;
	for(int d=-9;d<=9;++d){
		ll nxt=now+v[i]*d;
		if(abs(nxt-D)>v[i])continue;
		ret+=(cnt[d+9]-(i==0&&d>=0))*dfs(i+1,nxt);
	}
	return ret;
}

int main(){
	scanf("%d",&D);
	for(int i=pw[0]=1;i<19;++i)pw[i]=10*pw[i-1];
	for(int i=0;i<=9;++i)for(int j=0;j<=9;++j)++cnt[i-j+9];
	int ld=getlen(D);
	ll ans=0;
	for(l=ld;l<=2*ld;++l){
		for(int i=0;i<=(l-1)/2;++i)v[i]=pw[l-i-1]-pw[i];
		ll tmp=dfs(0,0);
		if(l%2)tmp*=10;
		ans+=tmp;
	}
	printf("%lld\n",ans);
	return 0;
}
