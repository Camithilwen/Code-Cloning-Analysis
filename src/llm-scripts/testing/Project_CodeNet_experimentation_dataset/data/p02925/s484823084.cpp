#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,a[1010][1010],h[1000100],dist[1000100];
vector<int>to[1000100];

int encode(int i, int j){
  if(i>j)swap(i,j);
  return i*n+j;
}

int main(){
  cin>>n;
  rep(i,n)rep(j,n-1){
    cin>>a[i][j];
    a[i][j]--;
  }
  rep(i,n)rep(j,n-2){
    int v=encode(i,a[i][j]);
    int u=encode(i,a[i][j+1]);
    to[v].push_back(u);
    h[u]++;
  }
  stack<int>st;
  rep(i,n*n)if(h[i]==0)st.push(i),dist[i]=1;
  while(st.size()){
    int v=st.top(); st.pop();
    for(int u:to[v]){
      h[u]--;
      if(h[u]==0)st.push(u);
      dist[u]=max(dist[u],dist[v]+1);
    }
  }
  int mx=0,in=0;
  rep(i,n*n)mx=max(mx,dist[i]);
  rep(i,n*n)in=max(in,h[i]);
  if(in!=0)cout<<-1<<endl;
  else cout<<mx<<endl;
}