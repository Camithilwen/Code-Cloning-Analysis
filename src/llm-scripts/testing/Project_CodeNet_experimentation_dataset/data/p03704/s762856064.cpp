//marico el que lo lea
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <assert.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;

void fastIO() {
	std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

#define FOR(i,f,t) for(int i=f; i<(int)t; i++)
#define FORR(i,f,t) for(int i=f; i>(int)t; i--)
#define FORE(i,c) for(auto i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define all(obj) obj.begin(), obj.end()
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ms2(obj, val, sz) memset(obj, val, sizeof(obj[0])*sz)

#define fst first
#define snd second

template<typename T, typename U> inline void mnze(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void mxze(T &x, U y) { if(x < y) x = y; }

void _scan( int &x ) { scanf("%d",&x); }
void _scan( long long &x ) { scanf("%lld",&x); }
void _scan( double &x ) { scanf("%lf",&x); }
void _scan( char &x ) { scanf(" %c",&x); }
void _scan( char *x ) { scanf("%s",x); }
void scan() {}
template<typename T, typename... U>
void scan( T& head, U&... tail ) { _scan(head); scan(tail...);}

template<typename T> void _dbg(const char* sdbg, T h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename T, typename... U> void _dbg(const char* sdbg, T h, U... t) {
	while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(_i, (x)) cerr <<*_i <<", "; cerr <<"\n"; }}
#define debuga(x, sz) {{cerr <<#x <<" = "; FOR(_i, 0, sz) cerr << x[_i] <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define debuga(x, sz)
#define cerr if(0)cout
#endif

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

int dig, D[46];

ll dp[50][2][2];

ll f(int d, int cl, int cr){
	int d2 = dig-1-d;
	if(d2 < d) return cl==cr;
	if(d2 == d) return (10*cl-cr == D[d])*10;
	ll &ret = dp[d][cl][cr];
	if(ret!=-1) return ret;
	ret = 0;
	FOR(dl,0,10) FOR(dr,0,10) FOR(ncl,0,2) FOR(ncr,0,2){
		if(dr - cr + 10*ncr - dl == D[d] && dl + 10*cl - ncl - dr == D[d2]){
			if(!d && !dr) continue;
			//debug(dl, dr, ncl, ncr);
			ret += f(d+1, ncl, ncr);
		}
	}
	return ret;
}

int main(){
	int d, mnd=0; scan(d);
	FOR(_,0,49){
		if(d) mnd = _+1;
		D[_] = d%10;
		d/=10;
	}
	ll ans = 0;
	FOR(i,mnd,49){
		ms(dp,-1);
		dig = i;
		ans += f(0,0,0);
	}
	printf("%lld\n", ans);
}