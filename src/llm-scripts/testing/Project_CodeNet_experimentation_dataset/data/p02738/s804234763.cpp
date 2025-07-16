//Let's join Kaede Takagaki Fun Club !!
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
ll mod;
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

ll dp[6005][9005];
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[10005],R[10005];
ll rev2[10005];
ll rev3[10005];
void make(){
	F[0] = 1;
	for(int i=1;i<10005;i++) F[i] = F[i-1]*i%mod;
	for(int i=0;i<10005;i++) R[i] = modpow(F[i],mod-2);
	for(int i=0;i<10005;i++) {
		rev2[i] = modpow(modpow(2LL,i),mod-2);
		rev3[i] = modpow(modpow(3LL,i),mod-2);
	}
}
ll C(int a,int b){
	return F[a]*R[b]%mod*R[a-b]%mod;
}
int main(){
	int n, m; g(n); g(m);
	mod = m;
	make();
	ll ans = 0;
	for(int one=0;one<=3*n;one++){
		for(int two=0;two<=one;two++){
			int zan = 3*n-one-two-two;
			if(zan >= 0 && zan%3 == 0){
				int thr = zan / 3;
				add(ans, C(3*n, one) * C(3*n-one, two*2) % mod * F[two*2] % mod * R[two] % mod * rev2[two] % mod * F[thr*3] % mod * R[thr] % mod * rev3[thr] % mod);
			}
			//o(one,1); o(two,1); o(ans);
		}
	}
	o(ans);
}