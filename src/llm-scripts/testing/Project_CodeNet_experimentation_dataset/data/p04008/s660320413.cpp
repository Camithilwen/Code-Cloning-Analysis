#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;
int N,K,maxi=0,ans=0;
vector<int> G[MAX],dis(MAX);

void DFS(int u,int p){
    for(int i=0;i<G[u].size();i++){
        int a=G[u][i];
        if(a==p) continue;
        DFS(a,u);
        dis[u]=max(dis[u],dis[a]+1);
    }
    if(u==0) return;
    
    if(p==0){
        if(dis[u]==K){
            ans++;
            dis[u]=-1;
        }
    }else{
        if(dis[u]==K-1){
            ans++;
            dis[u]=-1;
        }
    }
}

int main(){
    
    cin>>N>>K;
    int a;cin>>a;
    if(a!=1) ans++;
    for(int i=1;i<N;i++){
        int a;cin>>a;
        a--;
        G[a].push_back(i);
    }
    DFS(0,-1);
    
    cout<<ans<<endl;
    
    
}



