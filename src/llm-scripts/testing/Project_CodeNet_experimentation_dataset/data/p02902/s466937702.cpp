#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

const int n_max=1e3+10;
const int inf=INT_MAX/4;
vector<int> g[n_max];
vector<int> rg[n_max];


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >>m;

  rep(i,m){
    int a,b;
    cin >> a >> b;
    --a;--b;
    g[a].pb(b);
    rg[b].pb(a);      
  }
  int min_loop=inf;
  int min_ind=-1;
  {
  rep(i,n){
    vector<int> dp(n,inf);
    queue<int> qu;    
    dp[i]=0;
    qu.push(i);
    while(!qu.empty()){
      int v = qu.front();qu.pop();
      for(auto nv:g[v]){
	if(nv==i){
	  if(min_loop>dp[v]+1){
	    min_loop = dp[v]+1;
	    min_ind = i;
	    //	    cout << "minloop ind " << min_loop << " " << min_ind << endl;
	  }	  
	}
	if(dp[nv] > dp[v]+1){
	  dp[nv] = dp[v]+1;
	  qu.push(nv);
	}
      }
    }    
  }
  }
  if(min_ind==-1){
    cout << -1 << endl;
    return 0;
  }
  else{
    cout << min_loop << endl;
  }
  vector<int> dp(n,inf);
  queue<int> qu;
  dp[min_ind]=0;
  qu.push(min_ind);
  bool ok=true;
  while(!qu.empty()){
    int v = qu.front();qu.pop();
    for(auto nv:g[v]){
      if(nv==min_ind){
	dp[min_ind]=dp[v]+1;
	ok=false;
	break;
      }
      if(dp[nv] > dp[v]+1){
	dp[nv] = dp[v]+1;
	qu.push(nv);
      }
    }
    if(!ok) break;
  }
  //  cout << "ind dp " << min_ind << endl;
  //  cout << dp[min_ind] << endl;
  vector<int> ans;
  ans.pb(min_ind);
  while(ans.size()!=min_loop){
    for(auto i:rg[min_ind]){
      if(dp[i] == dp[min_ind]-1){
	//	cout << i << endl;
	ans.pb(i);
	min_ind = i;
	break;
      }
    }
  }
  rep(i,min_loop){
    cout << ans[i]+1 << endl;
  }

  return 0;
    

}
