#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int v, e;
const int MAX_N = 100010;
// 隣接リスト
vector<int> g[MAX_N];
bool used[MAX_N];
// トポロジカルソートされた数列
vector<int> ans;
bool head[MAX_N];
void dfs(int u) {
  if(used[u]) return;
  used[u] = true;
  for(auto& i: g[u]) dfs(i);
  // 帰りがけ順で追加
  ans.push_back(u);
}

void tsort() {
  for(int i=0; i<v; ++i) dfs(i);
  reverse(ans.begin(), ans.end());
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> v >> e;
    e += v - 1;
    rep(i, v) head[i] = true;
    for(int i=0; i<e; ++i) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        g[s].push_back(t);
    }
    tsort();
    //for(int i: ans) cout << i + 1 << endl;
    vector<pair<int, int>> p;
    rep(i, v) p.push_back({i, ans[i]});
    rep(i, v) ans[i] = -1;
    sort(p.begin(), p.end());
    for(auto& e: p) {
        int u = e.second;
        //cerr << "*" << e.first << " " << e.second << endl;
        for(auto to: g[u]) {
            ans[to] = u;
        }
    }
    for(int i: ans) cout << i + 1 << endl;

    return 0;
}
