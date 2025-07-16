#include<bits/stdc++.h>
using namespace std;
#define INF 100010
typedef pair<int,int> P;
vector<int> G[100010];
vector<int> GG[100010];
int V,E,n;
int ord[100010];
int low[100010];
int par[100010];

int lowlink(int x,int p){
  ord[x]=n++,par[x]=p;
  int ans=ord[x];
  for(int i=0;i<G[x].size();i++){
    if(G[x][i]==p)continue;
    if(ord[G[x][i]]!=INF)ans=min(ord[G[x][i]],ans);
    else {
      ans=min(ans,lowlink(G[x][i],x));
      GG[x].push_back(G[x][i]);
    }
  }
  return low[x]=ans;
}

int main(){
  for(int i=0;i<100010;i++)
    low[i]=ord[i]=INF;
  cin>>V>>E;
  P p[100010];
  for(int i=0;i<E;i++){
    int s,t;
    cin>>s>>t;
    G[s].push_back(t);
    G[t].push_back(s);
    if(s>t)swap(s,t);
    p[i]=P(s,t);
  }
  sort(p,p+E);
  lowlink(0,-1);
  for(int i=0;i<V;i++){
    int f=0;
    if(i==0&&GG[0].size()>1)f=1;
    if(i!=0)
      for(int j=0;j<GG[i].size();j++){
	if(GG[i][j]==par[i])continue;
	if(low[GG[i][j]]>=ord[i])f=1;
	//cout<<i<<" "<<G[i][j]<<" "<<low[i]<<" "<<low[G[i][j]]<<" "<<f<<endl;
      }
    //cout<<low[i]<<endl;
    if(f)cout<<i<<endl;
  }
  return 0;
}

