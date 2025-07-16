#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <assert.h>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <complex>
#include <iomanip>
#include <stack>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
ll mod=1e9+7;
double eps=1e-7;
ll exp(ll x,ll y){if(y<0) return 0; ll ret=1;for(;y;y>>=1,x=(x*x)%mod){if(y&1)ret=(ret*x)%mod;}return ret;}
ull pexp(ull x,ull y){if(y<0) return 0; ull ret=1; for(;y;y>>=1,x=(x*x)){if(y&1)ret=(ret*x);}return ret;}
ll gcd(ll x,ll y){if(!x||!y) return x+y; return x%y==0?y:gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
ll bsum(ll u,ll b){ll ret=0;if(u<b)return u;while(u){ret+=u%b;u/=b;}return ret;}
ll prival(ll u,ll p){ll cn=0;while(u%p==0){cn++;u=u/p;}return cn;}
ll minv(ll a,ll b){return 1<a?b-minv(b%a,a)*b/a:1;}
ll extm(ll a,ll b){ll ret=0;while(a!=0){if(a%2==1){ret+=b;ret%=mod;}a>>=1;b=(2*b)%mod;}return ret;}   
ll eaphi(ll x){ll t=x,ret=x,i;for(i=2;i*i<=x;i++){if(t%i==0){ret-=ret/i;while(t%i==0) t/=i;}}if(t!=1) ret-=ret/t;return ret;}
ll eadivc(ll x){ll ret=0;ll i;for(i=1;i*i<=x;i++){if(x%i==0 && i*i!=x) ret+=2;if(x%i==0 && i*i==x) ret+=1;}return ret;}
ll eadivs(ll x){ll ret=0;ll i;for(i=1;i*i<=x;i++){if(x%i==0 && i*i!=x) ret+=i+x/i;if(x%i==0 && i*i==x) ret+=i;}return ret;}
ll ndig(ll x, ll b){ll ret=0;while(x){x/=b; ret++;}return ret;}
ll rev(ll n, ll b){ll ret=0;while(n){ret=b*ret+n%b; n/=b;}return ret;}
ll sq(ll x){ll t=(ll)sqrt(x); for(ll i=t-2 ; i<=t+2 ; i++) if(i*i==x) return abs(i); return -1;}
ll extexp(ll x,ll y){if(y<0) return 0; ll ret=1;for(;y;y>>=1,x=extm(x,x)){if(y&1)ret=extm(ret,x);}return ret;}
bool isprime(ll x){if(x<=1) return false; for(ll i=2;i*i<=x;i++){if(x%i==0){return false;}}return true;}
pair<ll, int> x[111111];
pair<ll, int> y[111111];
vector< pair< ll, pair<int, int> > > edge;
int par[111111]; ll ans, n;

int find(int x)
{
	if(par[x]==x) return x;
	return par[x]=find(par[x]);
}

void unite(int u, int v)
{
	if(find(u)==find(v)) return;
	par[find(u)]=v;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n; int i, j;
	for(i=1 ; i<=n ; i++) par[i]=i;
	for(i=1 ; i<=n ; i++) cin>>x[i].first>>y[i].first;
	for(i=1 ; i<=n ; i++) x[i].second=y[i].second=i;
	sort(x+1,x+n+1); sort(y+1,y+n+1);
	for(i=1 ; i<=n-1 ; i++) edge.push_back(make_pair(x[i+1].first-x[i].first,make_pair(x[i].second,x[i+1].second)));
	for(i=1 ; i<=n-1 ; i++) edge.push_back(make_pair(y[i+1].first-y[i].first,make_pair(y[i].second,y[i+1].second)));
	sort(edge.begin(),edge.end());
	for(i=0 ; i<edge.size() ; i++)
	{
		int u=edge[i].second.first;
		int v=edge[i].second.second;
		if(find(u)==find(v)) continue;
		unite(u,v); ans+=edge[i].first;
	}
	cout<<ans; return 0;
}

// 제출하기 전에 생각햇나요?
// it may be easier/harder than you think
// ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);