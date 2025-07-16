#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define pi std::pair<int, int>
#define mkp std::make_pair
#define ll long long
#define pb push_back
#define fi first
#define se second

//{{{IO
namespace IO{
	template <class I> void read(I &x){
		x = 0; char ch = getchar(); bool f = false;
		for(; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for(; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + ch - '0';
		return ;
	}

	int read_int(){ int x; return read(x), x;}
	ll read_ll(){ ll x; return read(x), x;}
	template <class I>
		void chmax(I &x, I y){x = x > y ? x : y;}
	template <class I>
		void chmin(I &x, I y){x = x < y ? x : y;}
#define ri read_int()
#define rl read_ll()
}
using IO::read_int;
using IO::read_ll;
using IO::chmax;
using IO::chmin;
//}}}

//{{{Mod
namespace Mod{
//	const int mod = 1e9 + 7;
//	const int mod = 1004535809;
	const int mod = 998244353;
	
	inline void MOD(int &x){ x -= x >= mod ? mod : 0;}
	inline void add(int &x, int y){ x = x + y >= mod ? x + y - mod : x + y;}
	inline int Add(int x, int y){ return x + y >= mod ? x + y - mod : x + y;}
	inline void mul(int &x,  int y){ x = 1ll * x * y % mod;}
	inline int Mul(int x, int y){ return 1ll * x * y % mod;}
}
//}}}

#define N 100005

int n, s, cnt;
int x[N], num[N];
ll a[N];

void solve(int l, int r){
	if(l > r) return ;
	if(l == r) return num[++cnt] = l, void();
	if(x[l] > s){
		while(r >= l) num[++cnt] = r--;
		return ;
	}
	if(x[r] < s){
		while(r >= l) num[++cnt] = l++;
		return ;
	}
	if(a[l] >= a[r]){
		num[++cnt] = r; a[l] += a[r]; solve(l, r - 1);
	}
	else{
		num[++cnt] = l; a[r] += a[l]; solve(l + 1, r);
	}
	return ;
}

int main(){
	n = ri; s = ri;
	for(int i = 1; i <= n; ++i)
		x[i] = ri, a[i] = ri;
	solve(1, n); ll res = 0;
//	for(int i = cnt; i >= 1; --i)
//		debug("%d ", num[i]);
	for(int i = cnt; i >= 1; --i) 
		res += abs(x[num[i]] - s), s = x[num[i]];
	printf("%lld\n", res);
	return 0;
}