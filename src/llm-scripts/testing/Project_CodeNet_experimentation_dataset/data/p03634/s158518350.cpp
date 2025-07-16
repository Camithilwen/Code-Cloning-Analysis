#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int INF = 2e6;
ll MOD = 1e9 + 7;


int main(){
    
    int n; cin >> n;
    vector<vector<pair<int,ll>>> g(n);
    rep(i,n-1){
        int a, b; ll c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].pb(make_pair(b,c));
        g[b].pb(make_pair(a,c));
    }
    
    int q, k; cin >> q >> k;
    k--;
    vector<int> x(q),y(q);
    rep(i,q) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }

    queue<int> que;
    que.push(k);
    vector<bool> vis(n,false);
    vis[k] = true;
    vector<ll> dist(n);

    while(que.size()){
        int v = que.front();
        que.pop();
        for(auto i : g[v]){
            if(!vis[i.first]){
                vis[i.first] = true;
                dist[i.first] = dist[v] + i.second;
                que.push(i.first);                
            }
        }
    }

    rep(i,q){
        cout << dist[x[i]] + dist[y[i]] << endl;
    }
}