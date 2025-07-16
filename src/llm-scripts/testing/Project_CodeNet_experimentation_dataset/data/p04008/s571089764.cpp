#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

vector<int> g[111111];
int p[111111];
ll ans;
ll n,k;

int dfs(int n){
  int ma=0;
  for(int i=0;i<g[n].size();i++){
    ma=max(ma,dfs(g[n][i]));
  }
  if(n==0)return 0;
  if(ma==k-1&&p[n]!=0){
    ans++;
    return 0;
  }
  return ma+1;
}

int main(){
  cin>>n>>k;

  for(int i=0;i<n;i++){
    cin>>p[i];
    p[i]--;
    if(i==0&&p[i]!=0){
	 ans++;
	 p[i]=0;
    }
    if(i){
	 g[p[i]].pb(i);
    }
  }

  dfs(0);

  cout<<ans<<endl;
  
  return 0;
}


