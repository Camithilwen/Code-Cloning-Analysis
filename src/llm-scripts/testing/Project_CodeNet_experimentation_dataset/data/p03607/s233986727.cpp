#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
 
int main() {
  int n;
  cin>>n;
  map<int,int> mp;
  rep(i,n){
    int a;
    cin>>a;
    if(mp[a]!=1){
      mp[a]=1;
    }else{
      mp[a]=0;
    }
  }
  int ans=0;
  for(auto x:mp){
    if(x.second==1){
      ans++;
    }
  }
  cout<<ans<<endl;
}