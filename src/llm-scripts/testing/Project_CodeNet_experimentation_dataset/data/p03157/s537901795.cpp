#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>
#define int ll

char grid[410][410];
bool seen[410][410];
vector<P> gr[1001001];
int ans;
int h,w;

void dfs(int i, int j, int &g, int pi=-1, int pj=-1){
  if(seen[i][j]==1) return;
  if(i<0 || i>=h || j<0 || j>=w) return;
  if(pi!=-1 && grid[pi][pj]==grid[i][j]) return;
  seen[i][j]=1;
  gr[g].push_back(make_pair(i,j));
  dfs(i+1,j,g,i,j);
  dfs(i-1,j,g,i,j);
  dfs(i,j+1,g,i,j);
  dfs(i,j-1,g,i,j);
}

main(){
  cin>>h>>w;
  rep(i,h)rep(j,w){
    cin>>grid[i][j];
    seen[i][j]=0;
  }
  int tmp=0;
  rep(i,h)rep(j,w){
    if(seen[i][j]) continue;
    else{
      dfs(i,j,tmp);
      tmp++;
    }
  }
  ans=0;
  rep(i,tmp){
    int b=0, w=0;
    for(auto p : gr[i]){
      int hi=p.first, wi=p.second;
      if(grid[hi][wi]=='#') b++;
      else w++;
    }
    ans+=b*w;
  }
  cout<<ans<<endl;
}