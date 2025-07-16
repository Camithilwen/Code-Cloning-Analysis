#include<functional>
#include<algorithm>
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define pf push_front
#define pb push_back
#define int long long
using namespace std;
const int INF=1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const int N=101;

int cost[N][N];
int tim[N][N];

int bfs(int n,int p,int q,int graph[N][N]){
  vector<int> v(n);
  queue<int> que;
  rep(i,n)v[i]=INF;
  v[p]=0;
  que.push(p);
  int u;
  while(!que.empty()){
    u=que.front(),que.pop();
   
    rep(i,n){
      if(v[i]>v[u]+graph[u][i]){
        v[i]=v[u]+graph[u][i];
        que.push(i);
      }
    }
  }
  return v[q];
}


signed main(){
  int n,m;
  while(cin>>n>>m,n!=0){ 
    rep(i,m)rep(j,m){
      cost[i][j]=(i==j?0:INF);
      tim[i][j]=(i==j?0:INF);
    }
    rep(i,n){
      int a,b,c,t;
      cin>>a>>b>>c>>t;
      a--;b--;
      cost[a][b]=cost[b][a]=c;
      tim[a][b]=tim[b][a]=t;
    }
    int k;
    cin>>k;
    rep(i,k){
      int p,q,r;
      cin>>p>>q>>r;
      p--;q--;
      int ans;
      if(r==0){
        ans=bfs(m,p,q,cost);
      }else{
        ans=bfs(m,p,q,tim);
      }
      cout<<ans<<endl;
    }
  }
  return 0;
}