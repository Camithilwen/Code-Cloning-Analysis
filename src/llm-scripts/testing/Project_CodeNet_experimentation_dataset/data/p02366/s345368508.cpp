#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
int v = 100005,e;
int c = 0;
vector<vector<int>> graph(v,vector<int>());
vector<bool> seen(v,false);
vector<int> ord(v);
vector<int> low(v);
vector<bool> isart(v,false);

void dfs(int i,int par=-1){
    seen[i] = true;
    ord[i] = low[i] = c++;
    int count = 0;

    for(int j:graph[i]){
        if(!seen[j]){
            dfs(j,i);
            ++ count;
            low[i] = min(low[i],low[j]);
            if(par != -1 && ord[i] <= low[j]) isart[i] = true;
        }else if(j!=par){
            low[i] = min(low[i],ord[j]);
        }
    }

    if(par==-1 && count>1) isart[i] = true;
    return;
}

int main(){
    cin >> v >> e;
    rep(i,e){
        int s,t;
        cin >> s >> t;
        graph[s].push_back(t);
        graph[t].push_back(s);
    }
    dfs(0);
    rep(i,v){
        if(isart[i]) cout << i << endl;
    }
    return 0;
}
