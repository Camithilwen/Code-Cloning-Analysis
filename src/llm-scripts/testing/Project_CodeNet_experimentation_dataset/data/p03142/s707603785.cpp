/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>
#include <cassert>

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 60;
const ll MOD = 1e9 + 7;
 
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll conbinationMemo[100][100];

void cmemoInit(){
    rep(i, 100){
        rep(j, 100){
            conbinationMemo[i][j] = -1;
        }
    }
}
 
ll nCr(ll n, ll r){
    if(conbinationMemo[n][r] != -1) return conbinationMemo[n][r];
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return conbinationMemo[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
//-----------------------ここから-----------
ll n, m;
vector<vector<ll>> g;
vector<vector<ll>> rg;
vector<ll> t;
void dfs(ll now, vector<int> &visited){
    visited[now] = 1;
    rep(i, g[now].size()){
        ll next = g[now][i];
        if(visited[next]) continue;
        dfs(next, visited);
    }
    t.push_back(now);
}
int main(void){

    cin >> n >> m;
    g.resize(n);
    rg.resize(n);
    vector<int> appeared(n, 0);
    rep(i, n - 1 + m){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        rg[b].push_back(a);
        appeared[b] = 1;
    }
    ll root = 0;
    rep(i, n){
        if(!appeared[i]){
            root = i;
            break;
        }
    }

    vector<int> visited(n, 0);
    dfs(root, visited);

    reverse(all(t));

    map<ll,ll> mp;
    rep(i, t.size()){
        mp[t[i]] = i;
    }

    rep(i, n){
        sort(all(rg[i]), [&mp](const ll &f, const ll &s){
            return mp[f] > mp[s];
        });
    }
    vector<ll> ans(n);
    rep(i, n){
        if(rg[i].size() == 0){
            ans[i] = 0;
        } else {
            ans[i] = rg[i][0] + 1;
        }
    }

    rep(i, ans.size()){
        cout << ans[i] << endl;
    }

    
}
