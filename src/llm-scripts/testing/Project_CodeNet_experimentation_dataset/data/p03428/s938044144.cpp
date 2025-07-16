#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<complex>
#define rep(i, a, n) for(int i=a;i<n;i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define R long double 
#define P complex<R>
using namespace std;
const int mod = 1000000007;
const int INF = 1e12;
template<class T>bool chmax(T &a, const T &b) { return (a < b) ? (a = b, 1) : 0;}
template<class T>bool chmin(T &a, const T &b) { return (b < a) ? (a = b, 1) : 0;}
const R PI = acos(-1.0L);
const R inf = 1e13;
int x[110], y[110];
R ans[110];
inline R dist(int i, P q) {
   P p = P(x[i], y[i]);
   return norm(p - q);
}
signed main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
    }
    int limit = 200000;
    rep(i, 0, limit){
        R cur = 2.0 * PI / limit * i;
        P point = polar(inf, cur);
        R d = 1e130;
        int idx = -1;
        rep(j, 0, n) if(chmin(d, dist(j, point))) idx = j;
        ans[idx] += 1.0;
    }
    cout.precision(20);
	rep(i, 0, n) cout << fixed << 1.0 * ans[i] / limit << endl;
	return 0;
}

