#include<cstdio>
#include<cstring>
#include<algorithm>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
typedef long long ll;
ll a[MAXN];
int n,now,cnt0,cnt1;
ll gcd(ll x,ll y){
	if(y==0)
		return x;
	return gcd(y,x%y);	
}
bool solve(){
	int cnt0=0,cnt1=0,now=0;
	for(int i=1;i<=n;i++){
		if(a[i]%2ll==0)
			cnt0++;
		else{
			cnt1++;
			now=i;
		}
	}
	if(cnt1==1&&a[now]!=1){
		ll g=0;
		a[now]--;
		for(int i=1;i<=n;i++)
			g=gcd(g,a[i]);
		for(int i=1;i<=n;i++)
			a[i]/=g;
		if(solve()==0)
			return 1;
	}
	if(cnt0%2==1)
		return 1;
	else
		return 0;
}
int main(){
	//freopen("game.in","r",stdin);
	//freopen("game.out","w",stdout);
	SF("%d",&n);
	for(int i=1;i<=n;i++)
		SF("%lld",&a[i]);
	if(solve())
		PF("First");
	else
		PF("Second");
}