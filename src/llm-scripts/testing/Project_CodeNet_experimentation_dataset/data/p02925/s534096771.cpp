#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int mod=1e9+7;

int id[1005][1005];
vector<int>to[1000005];
bool visited[1000005];
int dp[1000005];
bool calculated[1000005];

int toid(int i,int j){
  if(i>j){swap(i,j);}
  return id[i][j];
}

int dfs(int v){
  if(visited[v]){
    if(!calculated[v]){
      return -1;
    }
    return dp[v];
  }
  visited[v]=1;
  dp[v]=1;
  for(int u:to[v]){
    int res=dfs(u);
    if(res==-1){return -1;}
    dp[v]=max(dp[v],res+1);
  }
  calculated[v]=1;
  return dp[v];
}

int main() {
  int N;
  cin>>N;
  vector<vector<int>>A(N,vector<int>(N-1));
  for(int i=0;i<N;i++){
    for(int j=0;j<N-1;j++){
      cin>>A[i][j];
      A[i][j]--;
    }
  }
  int v=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
       if(i<j){
         id[i][j]=v++;
       }
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N-1;j++){
      A[i][j]=toid(i,A[i][j]);
    }
    for(int j=0;j<N-2;j++){
      to[A[i][j+1]].push_back(A[i][j]);
    }
  }
  int ans=0;
  for(int i=0;i<v;i++){
    int res=dfs(i);
    if(res==-1){
      cout<<-1<<endl;return 0;
    }
    chmax(ans,res);
  }
  cout<<ans<<endl;
  return 0;  
}