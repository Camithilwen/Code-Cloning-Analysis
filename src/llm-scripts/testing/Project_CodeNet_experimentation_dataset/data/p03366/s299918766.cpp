#include<bits/stdc++.h>
#define lowbit(i) ((i)&(-(i)))
#define lson(i) ((i)<<1)
#define rson(i) ((i)<<1|1)
#define sqr(x) ((x)*(x))
#define fi first
#define se second
#define mp(x,y) make_pair((x),(y))
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef pair<int,int> pii;
typedef vector<int> vii;
typedef vector<pii> vpi;
typedef queue<int> qii;

const int inf=0x3f3f3f3f;
const int maxn=100007;

ll n,s;
struct node{
	ll x,p;void init(){scanf("%lld%lld",&x,&p);}
}a[maxn];

pair<ll,ll> solve(ll l,ll r){
	if(a[r].x<s) {
		return mp(-1,s-a[l].x);
  	}else if(a[l].x>s) {
  		return mp(1,a[r].x-s);
    }
  	if(l==r){
		if(a[l].x<s) return mp(-1,s-a[l].x);
		else return mp(1,a[l].x-s);
	}
	if(a[l].p<a[r].p){
		a[r].p+=a[l].p;
		pair<ll,ll> t=solve(l+1,r);
		// cout<<l<<' '<<r<<' '<<a[l].p<<' '<<a[r].p-a[l].p<<' ';
		// cout<<t.fi<<' '<<t.se<<'\n';
		if(t.fi==-1) return mp(-1,t.se+a[l+1].x-a[l].x);
		else return mp(-1,t.se+a[r].x-a[l].x);
	}else{
		a[l].p+=a[r].p;
		pair<ll,ll> t=solve(l,r-1);
		// cout<<l<<' '<<r<<' '<<a[l].p-a[r].p<<' '<<a[r].p<<' ';
		// cout<<t.fi<<' '<<t.se<<'\n';
		if(t.fi==1) return mp(1,t.se+a[r].x-a[r-1].x);
		else return mp(1,t.se+a[r].x-a[l].x);
	}
}

int main(){
// 	freopen("","r",stdin);5
// 	freopen("","w",stdout);
	scanf("%lld%lld",&n,&s);
	for(int i=1;i<=n;i++) a[i].init();
	// for(int i=1;i<=n;i++) cout<<a[i].p<<' ';cout<<'\n';
	printf("%lld\n",solve(1,n).se);
	return 0;
}
/*
3 2
1 3
3 4
4 2
*/