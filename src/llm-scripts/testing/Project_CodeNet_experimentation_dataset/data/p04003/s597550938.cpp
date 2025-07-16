#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;

vector< pair<int,int> > V;
vector< pair< pair<int,int>,int> > E;
vector<pair<int,int> > G[500005];
int dist[500005];

map<pair<int,int>,int> mp;
int main(){
    int N,M;
    cin>>N>>M;
    for(int i = 0;i < M;i++){
        int p,q,c;
        cin>>p>>q>>c;
        E.push_back(make_pair(make_pair(p,q),c));
        V.push_back(make_pair(p,c));
        V.push_back(make_pair(q,c));
    }
    for(int i = 1;i <= N;i++){V.push_back(make_pair(i,0));}
    for(int i = 0;i<500005;i++)dist[i]=-1;
    sort(V.begin(),V.end());
    V.resize(unique(V.begin(),V.end()) -V.begin());
    int vsize = V.size();
    for(int i = 0;i < vsize;i++){
        mp[V[i]]=i;
    }
    for(int i = 0;i < E.size();i++){
        int p,q,c;
        p=E[i].first.first;
        q=E[i].first.second;
        c=E[i].second;
        G[mp[make_pair(p,c)]].push_back(make_pair(0,mp[make_pair(q,c)]));
        G[mp[make_pair(q,c)]].push_back(make_pair(0,mp[make_pair(p,c)]));
        G[mp[make_pair(p,c)]].push_back(make_pair(0,mp[make_pair(p,0)]));
        G[mp[make_pair(p,0)]].push_back(make_pair(1,mp[make_pair(p,c)]));
        G[mp[make_pair(q,c)]].push_back(make_pair(0,mp[make_pair(q,0)]));
        G[mp[make_pair(q,0)]].push_back(make_pair(1,mp[make_pair(q,c)]));
    }
    priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > pq;
    pq.push(make_pair(0,mp[make_pair(1,0)]));
    while(!pq.empty()){
        pair<int,int> top = pq.top();
        pq.pop();
        int d = top.first;
        int v = top.second;
        //cout<<"a: "<<d<<" "<<V[v].first<<" "<<V[v].second<<" "<<endl;
        if(dist[v]==-1||dist[v] > d){
            dist[v] = d;
            for(int i = 0; i < G[v].size(); i++){
                pq.push(make_pair(G[v][i].first + d, G[v][i].second));
            }
        }
    }
    cout<<dist[mp[make_pair(N,0)]]<<endl;
}
