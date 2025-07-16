//52行目から編集
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
///////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////
/*
 * 強連結成分分解
 */
struct StronglyConnectedComponents{
    int V;//頂点数
    vector<vector<int> > G; // グラフの隣接リスト表現
    vector<vector<int> > rG; //辺の向きを逆にしたグラフ
    vector<int> vs; // 帰りがけ順の並び
    vector<bool> used; // すでに調べたか
    vector<int> cmp; // 属する今日連結成分のトポロジカル順序

    StronglyConnectedComponents(int V):V(V){
        G = vector<vector<int> >(V,vector<int>(0)); rG = vector<vector<int> >(V,vector<int>(0)); 
        vs = vector<int>(V,0); used = vector<bool>(V,0); cmp = vector<int>(V,0); 
    }

    void add_edge(int  from,int to){ G[from].push_back(to); rG[to].push_back(from); }
    void dfs(int v){
        used[v] = 1;
        for(int i = 0;i < G[v].size();i++){ if(!used[G[v][i]])dfs(G[v][i]); }
        vs.push_back(v);
    }
    void rdfs(int v,int k){
        used[v] = 1; cmp[v] = k;
        for(int i = 0;i < rG[v].size();i++){ if(!used[rG[v][i]]) rdfs(rG[v][i],k); }
    }
    int calc(){
        for(int i = 0;i < V;i++)used[i] = 0;
        vs.clear();
        for(int v = 0;v < V;v++){ if(!used[v])dfs(v);}
        for(int i = 0;i < V;i++)used[i] = 0;
        int k = 0;
        for(int i = vs.size() - 1;i >= 0;i--){ if(!used[vs[i]]) rdfs(vs[i],k++); }
        return k;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(20);
    int n,m;cin >> n >> m;
    StronglyConnectedComponents scc(n);
    rep(i,m){
        int a,b;cin >> a >> b;
        scc.add_edge(a,b);
    }
    int q;cin >> q;
    scc.calc();
    //rep(i,n)cout << i << " : " << scc.cmp[i] << '\n';
    rep(i,q){
        int a,b;cin >> a >> b;
        cout << (scc.cmp[a] == scc.cmp[b]) << '\n';
    }
    return 0;
}


