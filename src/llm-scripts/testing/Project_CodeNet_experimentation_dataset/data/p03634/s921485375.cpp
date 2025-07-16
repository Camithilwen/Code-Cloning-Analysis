//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
//using Graph = vector<vector<int>>;
typedef long long ll;
using Graph = vector<vector<pair<ll,ll>>>;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

int main(){
    ll n; cin>>n;
    Graph G(n);
    rep(i,n-1){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    ll q,k; cin>>q>>k;
    k--;
 
    vector<ll>dist(n,0);
    queue<ll>que;
    vector<bool>seen(n,false);
    que.push(k);
    while(!que.empty()){
        ll v=que.front();que.pop();
        seen[v]=true;
        for(auto nv:G[v]){
            if(seen[nv.first]==true)continue;
            dist[nv.first]=dist[v]+nv.second;
            que.push(nv.first);
        }
    }
    vector<ll>x(q),y(q);
    rep(i,q){
        cin>>x[i]>>y[i];
        x[i]--;y[i]--;
    }
    rep(i,q){
        cout<<dist[x[i]]+dist[y[i]]<<endl;
    }


    /*rep(i,n){
        cout<<dist[i]<<" ";
    }
    cout<<endl;*/

}









