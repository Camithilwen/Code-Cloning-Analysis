#include <iostream>
#include <iomanip>
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
//#define all(v) v.begin(),v.end()
//ll mod = 1e9+7 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n,k ;
	cin >> n >> k ;
	vll a(n) ;
	for(auto &i:a) cin >> i ;
	ll sum = 0 ;
	ll now = 0 ;
	for(int i=0;i<k;i++) now += a.at(i) ;
	sum = now ;
	for(int i=k;i<n;i++){
		now = now-a.at(i-k)+a.at(i) ;
		sum = max(sum,now) ;
	}
	fix_cout() ;
	cout << (sum+k)/2.0 << endl ;
}
