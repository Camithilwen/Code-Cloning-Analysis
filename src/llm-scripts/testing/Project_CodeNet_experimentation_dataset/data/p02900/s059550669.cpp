#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007
ll gcd (ll x, ll y){
	ll r = x % y ;
	if(r == 0) return y ;
	return gcd(y, r) ;
}
bool isprime(ll x){
	ll s = sqrt((double) x) ;
	for(ll i = 2; i <= s ; i++){
		if(x % i == 0) return false ; 
	}
	return true ;
}
int main (){
	ll a, b ;
	cin >> a >> b ;
	ll k = gcd(a, b) ;
	ll s = sqrt((double)k) ;
	vector<ll> y ;
	for(ll i = 1; i <= s; i++){
		if(k % i == 0){
			y.push_back(i) ;
			if(i != k/i){
				y.push_back(k/i) ;
			}
		}
	}
	sort(y.begin(), y.end()) ;
	ll num = y.size() ;
	ll ans = 0 ;
	rep(i, num){
		if(isprime(y[i])) ans++ ;
	}
	cout << ans << endl ;
}