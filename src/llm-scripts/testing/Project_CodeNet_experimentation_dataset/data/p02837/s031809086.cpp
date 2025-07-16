#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <functional>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

int main() {
    int n;
    cin >> n;
    VVI x(n), y(n);
    REP(i,n){
        int a = in();
        REP(j,a){
            x[i].push_back(in() - 1);
            y[i].push_back(in());
        }
    }
    int ans = 0;
    REP(mask,1<<n){
        bool f = true;
        int cnt = 0;
        REP(i,n) if ((mask >> i) & 1) cnt++;

        REP(i,n){
            if (((mask >> i) & 1) == 0) continue;
            REP(j,x[i].size()){
                if (((mask >> x[i][j]) & 1) != y[i][j]) f = false;
            }
        }
        if (f) chmax(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
