#include<bits/stdc++.h> 
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
typedef long long ll;
using namespace std;
int d,k,L,i,j,ten[15],a[25];
int s[25],mx,f[25];ll ans,an;
void dfs(int x,ll now){
	if (L-x>=k-1&&abs(now)>=10) return;
	if (now<0) return;
	int i;
	if (x>mx){
		an=a[s[1]+9]-(s[1]<=0);
		if (L&1) an*=10-(L==1);
		s[L]=-s[1];
		fo(i,2,mx) an*=a[s[i]+9],s[L-i+1]=-s[i];
		ll p=0;
		fd(i,L,1){
			p=p*10+s[i];
			if (p>d) return;
		}if (p==d) ans+=an;
		return;
	}
	fo(i,-9,9) s[x]=i,dfs(x+1,now*10-i);
}
int main(){
	ten[0]=1;
	fo(i,1,9) ten[i]=ten[i-1]*10;
	scanf("%d",&d);
	fo(i,1,9) if (d<ten[i]) break;
	k=i+1;
	fo(i,0,9)
	fo(j,0,9) a[i-j+9]++;
	fo(L,2,k<<1){
		mx=L>>1;
		memset(s,0,sizeof(s));
		dfs(1,0);
	}
	printf("%lld\n",ans);
}