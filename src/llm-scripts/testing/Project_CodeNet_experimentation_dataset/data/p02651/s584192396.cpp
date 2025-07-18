#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], basis[64];
string s;

bool check(ll x){
	for(int j = 0; j < 60; j++){
		if(((1ll<<j)&x) == 0) continue;
		if(!basis[j]) return false;
		x ^= basis[j];
	}
	return true;
}

void insert(ll x){
	for(int j = 0; j < 60; j++){
		if(((1ll<<j)&x) == 0) continue;
		if(basis[j]) x ^= basis[j];
		else{
			basis[j] = x;
			break;
		}
	}
}

void solve(){
	for(int i = 0; i < 60; i++) basis[i] = 0;
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	cin>>s; s = '0'+s;
	for(int i = n; i >= 0; i--){
		if(s[i] == '0') insert(a[i]);
		else if(!check(a[i])){ deb1(1) return; }
	}
	deb1(0)
}

int main(){
	GODSPEED;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}