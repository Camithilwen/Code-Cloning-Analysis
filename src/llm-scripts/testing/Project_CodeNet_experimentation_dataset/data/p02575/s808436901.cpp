#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <tuple>
#include <math.h>
#include <set>
#include <map>
using namespace std ;
using ll = long long ;
using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using vc = vector<char> ;
using vvc = vector<vc> ;
using vb = vector<bool> ;
using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end() 
const ll INF = 1e18 ;
const ll mod = 1e9+7 ;
const double pie = acos(-1); 
vll dx4 = {-1,0,1,0} ;
vll dy4 = {0,-1,0,1} ;
vll dx8 = {-1,0,1,1,1,0,-1,-1} ;
vll dy8 = {-1,-1,-1,0,1,1,1,0} ; 

void fix_cout(){cout << fixed << setprecision(20) ; }
ll gcd(ll a,ll b){if(b==0) return a ; return gcd(b,a%b) ; }
ll lcm(ll a,ll b){return a/gcd(a,b)*b ; }
void chmax(ll &a,ll b){if(a<b) a = b ; }
void chmin(ll &a,ll b){if(a>b) a = b ; }

int main(){
	ll h,w ;
	cin >> h >> w ;
	map<ll,ll> gs,dis ;
	for(int i=1;i<=w;i++) gs[i] = i ;
	gs[w+10] = -1 ;
	dis[0] = w ;
	for(int i=1;i<=h;i++){
		ll a,b ;
		cin >> a >> b ;
		ll mx = -1 ;
		for(auto it=gs.lower_bound(a);it->first<=b+1;it=gs.erase(it)){
			ll g = it->first ;
			ll s = it->second ;
			chmax(mx,s) ;
			if(dis.count(g-s)){
				dis[g-s]-- ;
				if(dis[g-s]==0) dis.erase(g-s) ;
			}
		}
		if(mx>=0&&b<w){
			gs[b+1] = mx ;
			dis[b+1-mx]++ ;
		}
		ll ans = -1 ;
		if(!dis.empty()){
			ans = i+dis.begin()->first ;
		}
		cout << ans << endl ;
	}
}
