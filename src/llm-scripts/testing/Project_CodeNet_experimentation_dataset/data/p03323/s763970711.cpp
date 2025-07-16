#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define  endl 			"\n"
#define  FOR(i, a, n)   for (ll i = a; i < n; i++)
#define  ROF(i, a, n)   for (ll i = a; i >= n; i--)
#define  all(x)         (x).begin(), (x).end()
#define  mset(x, val)   memset(x,val,sizeof(x))
#define  dline          cout<<"///REACHED///\n";

typedef long long ll;

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   MAXN  =  4e+5+7;



// 6




int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll a,b;
	cin>>a>>b;
	if(((16-(2*min(a,b))+1)/2+min(a,b))>= max(a,b)){
		cout<<"Yay!";
	}
	else{
		cout<<":(";
	}

	return 0;
}