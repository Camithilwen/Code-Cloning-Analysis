#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n,m;cin>>n>>m;
  vector<int> a(n+1,0);
  vector<int> sum(n+5,0);
  map<int,int> memo;
  memo[0]=1;
  rep1(i,n){
    cin>>a[i];
    sum[i]=sum[i-1]+a[i];
    sum[i]%=m;
    memo[sum[i]]+=1;
  }
  int res=0;
  for(auto it=memo.begin();it!=memo.end();++it){
      res+=it->second*(it->second-1)/2;
  }
  cout<<res<<"\n";
  return 0;
}