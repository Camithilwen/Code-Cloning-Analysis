#include "bits/stdc++.h"
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, a, b) for(int i=(b-1);i>=(a);i--)
#define REP(i, n) for(int i=0; i<(n); i++)
#define RREP(i, n) for(int i=(n-1); i>=0; i--)
#define REP1(i, n) for(int i=1; i<=(n); i++)
#define RREP1(i, n) for(int i=(n); i>=1; i--)
#define ALL(a) (a).begin(),(a).end()
#define UNIQUE_SORT(l) sort(ALL(l)); l.erase(unique(ALL(l)), l.end());
#define CONTAIN(a, b) find(ALL(a), (b)) != (a).end()
#define out(...) printf(__VA_ARGS__)
#if DEBUG
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...) /* ... */
#endif
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

void solve();
signed main()
{
#if DEBUG
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
/*================================*/
#if DEBUG
#define SIZE 1000
#else
#define SIZE 423450
#endif

int N,Q,K;

set<int> um[2][SIZE],dm[2][SIZE];
int BASE = SIZE/2;

struct Item2 {
    int x,y;
    char u;
};
vector<Item2> V;

set<int> ds[SIZE],ls[SIZE];

void solve() {
    cin>>N;
    int x,y;
    char u;
    REP(i,N) {
        cin>>x>>y>>u;
        if (u=='D') {
            dm[0][y-x+BASE].insert(x);
            dm[1][y+x].insert(x);
        }
        if (u=='U') {
            um[0][y-x+BASE].insert(x);
            um[1][y+x].insert(x);
        }
        V.push_back({x,y,u});
        if (u=='D') ds[x].insert(y);
        if (u=='L') ls[y].insert(x);
    }
    int ans = INT_MAX;
    REP(i,N) {
        auto p = V[i];
        if (p.u=='R') {
            {
                auto s = &dm[0][p.y-p.x+BASE];
                auto it = s->upper_bound(p.x);
                if (it != s->end()) chmin(ans, (*it - p.x) * 10);
            }
            {
                auto s = &um[1][p.y+p.x];
                auto it = s->upper_bound(p.x);
                if (it != s->end()) chmin(ans, (*it - p.x) * 10);
            }
            {
                auto s = &ls[p.y];
                auto it = s->upper_bound(p.x);
                if (it != s->end()) {
                    chmin(ans, (*it - p.x) * 5);
                }
            }
        }
        if (p.u=='L') {
            {
                auto s = &um[0][p.y-p.x+BASE];
                auto it = s->lower_bound(p.x);
                if (it != s->begin()) chmin(ans, (p.x - *(--it))*10);
            }
            {
                auto s = &dm[1][p.y+p.x];
                auto it = s->lower_bound(p.x);
                if (it != s->begin()) chmin(ans, (p.x - *(--it))*10);
            }
        }
        if (p.u=='U') {
            auto s = &ds[p.x];
            auto it = s->upper_bound(p.y);
            if (it != s->end()) {
                chmin(ans, (*it - p.y)*5);
            }
        }
    }
    
    if (ans==INT_MAX) {
        cout << "SAFE" << endl;
    } else {
        cout << ans << endl;
    }
}

