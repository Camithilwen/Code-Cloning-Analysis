#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void dfs(vector<vector<int>> &g, vector<bool> &used, int v, vector<int> &ans) {
    used[v] = true;
    for(int nv: g[v]) {
        if(!used[nv])  {
            dfs(g, used, nv, ans);
        }
    }
    ans.push_back(v);
}
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    vector<vector<int>> from(n);
    rep(i,n-1+m) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        to[a].push_back(b);
        from[b].push_back(a);
    }
    vector<bool> used(n, false);
    vector<int> topo_sort(0);
    rep(v,n) {
        if(!used[v]) dfs(to, used, v, topo_sort);
    }
    vector<int> inv_topo(n);
    rep(i,n) {
        inv_topo[topo_sort[i]] = i;
    }
    rep(i,n) {
        if(from[i].size() == 0) {
            cout << 0 << endl;
            continue;
        }
        int ans = from[i][0];
        for(int v :from[i]) {
            if(inv_topo[v] < inv_topo[ans]) {
                ans = v;
            }
        }
        cout << ans+1 << endl;
    }
}
