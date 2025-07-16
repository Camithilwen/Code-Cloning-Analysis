#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

struct edge{
    int to;
    int dist;
};

vector<bool> seen(100000, false);
vector<int> pnt(100000, INF);
vector<vector<edge>> G(100000);
int n, m;
bool f = true;


void dfs(int v, int dist){
    seen[v] = true;
    if(pnt[v] == INF)pnt[v] = dist;
    else {
        if(pnt[v] != dist)f = false;
        return;
    }

    for(int i = 0; i < (int)(G[v].size()); i++){
        edge e = G[v][i];
        if(pnt[e.to] != INF && pnt[e.to] != pnt[v] + e.dist){
            f = false;
            return;
        }
        if(seen[e.to])continue;
        dfs(e.to, e.dist + pnt[v]);
    }
}

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> rui(n + 1, 0);
    rep(i, n){
        ll a;
        cin >> a;
        rui[i + 1] = rui[i] + a;
    }
    ll res = 0;
    REP(i, 1, n){
        rui[i] %= m;
        if(rui[i] == 0)res++;
    }
    map<ll, ll> mp;
    REP(i, 1, n)mp[rui[i]]++;

    for(auto m : mp){
        res += m.second * (m.second - 1) / 2;
    }
    cout << res << endl;
}
