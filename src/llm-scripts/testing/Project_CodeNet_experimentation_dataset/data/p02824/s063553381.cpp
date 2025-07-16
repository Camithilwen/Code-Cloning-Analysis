#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
//#include <deque>
//#include <bitset>
//#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n,m,v,p ;
	cin >> n >> m >> v >> p ;
	vll a(n) ;
	for(auto &i:a) cin >> i ;
	sort(all(a)) ;
	reverse(all(a)) ;
	ll l,r,mid ;
	l = p-1 ;
	r = n ;
	while(l+1<r){
		mid = (l+r)/2 ;
		if(a.at(p-1)>a.at(mid)+m){
			r = mid ;
			continue ;
		}
		ll cnt = 0 ;
		cnt += m*(p-1+n-mid) ;
		for(int i=p-1;i<mid;i++) cnt += a.at(mid)+m-a.at(i) ;
		if(cnt>=m*v) l = mid ;
		else r = mid ;
	}
	cout << l+1 << endl ;
}
