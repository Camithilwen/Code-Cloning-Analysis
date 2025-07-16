#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXB=65;
typedef long long ll;
int n;
ll a[MAXN],p[MAXN],sum;
bool vis[MAXB];
void ins(ll x){
	for (ll i=60;i>=0;i--){
		if (!vis[i]) continue;
		if (x&(1ll<<i)){
			if (!p[i]) p[i]=x;
			x^=p[i];
		}
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum^=a[i];
	}
	for (int i=0;i<=60;i++){
		if (!(sum&(1ll<<i))) vis[i]=1;
	}
	for (int i=1;i<=n;i++) ins(a[i]);
	ll res=0;
	for (int i=60;i>=0;i--){
		if (vis[i]&&(!(res&(1ll<<i)))) res^=p[i];
	}
	printf("%lld\n",res+(sum^res));
	return 0;
}
