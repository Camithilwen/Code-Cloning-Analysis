#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
#include <unordered_map>
#include <fstream>
#include <ctime>
#include <complex>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef pair<int,int> pii;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(int i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {1,-1,0,0,1,-1,1,-1};
ll dx[8] = {0,0,1,-1,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T> inline void print(T &a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << "\n";
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << "\n";}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
ll pcount(ll x) {return __builtin_popcountll(x);}
//const int mod = 1e9 + 7;
const int mod = 998244353;

int main(){
	int h,w; cin >> h >> w;
	vs s(h); rep(i,h) cin >> s[i];
	vvl dist(h+1,vl(w,0));
	rep(j,w) rep(k,2) dist[0][j] = w-j;
	int ans = w;
	rep(j,w){
		vector<pii> st;
		st.emplace_back(0,0);
		REP(i,1,h+1){
			if(i < h){
				if(j==0 || dist[i][j-1] == 1){
					int d = 0;
					bool rev = s[i][j] != s[i-1][j];
					REP(k,j,w){
						if(rev == (s[i][k] != s[i-1][k])) d++;
						else break;
					}
					dist[i][j] = d;
				}else{
					dist[i][j] = dist[i][j-1] - 1;
				}
			}
			if(st.empty() || st.back().first < dist[i][j]){
				st.emplace_back(dist[i][j],i);
			}else{
				int pos = i;
				while(!st.empty()){
					if(st.back().first >= dist[i][j]){
						pii p = st.back();
						chmax(ans, p.first*(i-p.second)+p.first);
						pos = p.second;
						st.pop_back();
					}else{
						st.emplace_back(dist[i][j], pos);
						break;
					}
				}
			}
		}
	}
	cout << ans << "\n";
}