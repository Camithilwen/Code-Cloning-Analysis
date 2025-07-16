#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
ll mod=1e9+7;

bool* sieve(ll n){
	bool* a=new bool[n+1];
	for(ll i=0;i <n+1;i++) a[i]=true;
	for(ll i=2;i<n/2;i++){
		if(a[i]==false) continue;
		ll k=2;
		while(i*k <=n){
			a[i*k]=false;
			k++;
		}
	}
	
	return a;
}

int main(){
	ll n;
	cin >> n;
	bool* b=sieve(n);
	ll ans=1;
	for(ll i=2; i <n+1;i++){
		if(b[i]){
			ll j=i;
			ll count=0;
			while(j<=n){
				count+=n/j;
				j*=i;
			}
			ans*=count+1;
			ans%=mod;
		}
	} 
	cout << ans;
	return 0;
}