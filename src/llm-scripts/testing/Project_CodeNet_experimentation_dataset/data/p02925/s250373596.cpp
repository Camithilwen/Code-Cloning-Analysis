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
const int mod = 1e9 + 7;
//const int mod = 998244353;

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    vector<int> now(n,0);
    rep(i,n) rep(j,n-1) cin >> a[i][j], a[i][j]--;
    int total = n * (n-1) / 2;
    int ans = 0;
    queue<int> q;
    set<int> se;
    rep(i,n){
        if(a[a[i][0]][0] == i){
            if(se.find(i) == se.end() && se.find(a[i][0]) == se.end()){
                q.push(i);
                se.insert(i); se.insert(a[i][0]);
            }
        }
    }
    while(total > 0){
        se.clear();
        int m = q.size();
        total -= m;
        vector<int> wait;
        rep(j,m){
            int u = q.front(); q.pop();
            int v = a[u][now[u]];
            wait.push_back(u);
            wait.push_back(v);
            now[u]++;
            now[v]++;
        }
        for(auto u : wait){
            if(se.find(u) != se.end()) continue;
            if(now[u] == n-1) continue;
            int v = a[u][now[u]];
            if(se.find(v) != se.end()) continue;
            if(now[v] == n-1) continue;
            if(a[v][now[v]] != u) continue;
            q.push(u);
            se.insert(u);
            se.insert(v);
        }
        if(!m){
            puts("-1");
            return 0;
        }
        ans++;
    }
    cout << ans << "\n";
}