#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1000000007
/*
void dijkstra(vector<vector<pair<ll,int>>> &graph, vll &dist, int s){
    priority_queue<pair<ll,int>> que;
    dist[s]=0;
    que.push({0,s});
    while(!que.empty()){
        auto x=que.top(); que.pop();
        if(dist[x.second]<x.first) continue;
        for(auto v:graph[x.second]){
            if(dist[v.second]<dist[x.second]+v.first) continue;
            dist[v.second]=dist[x.second]+v.first;
            que.push({dist[v.second],v.second});
        }
    } 
}
*/

void bfs(vector<vector<pair<ll,int>>> &graph, vll &dist, int s){
    queue<pair<ll,int>> que;
    dist[s]=0;
    que.push({0,s});
    while(!que.empty()){
        auto x=que.front(); que.pop();
        for(auto v:graph[x.second]){
            if(dist[v.second]!=-1) continue;
            dist[v.second]=dist[x.second]+v.first;
            que.push({dist[v.second],v.second});
        }       
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<pair<ll,int>>> graph(n);
    rep(i,n-1){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back({c,b});
        graph[b].push_back({c,a});
    }    
    vll dist(n,-1);
    int q,k;
    cin >> q >> k; k--;
    //dijkstra(graph,dist,k);
    bfs(graph,dist,k);
    rep(i,q){
        int x,y;
        cin >> x >> y;
        x--; y--;
        cout << dist[x]+dist[y] << endl;
    }



}