#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
const int inf=1000000007;
const int MOD=1000000007;
int n,m;
struct Map{
  vector<vector<int>> map;
  void mkmap(vector<int> const& a,vector<int> const& b,vector<int>& num){
    //num.resize(n*m+1,0);
    rep(i,n){
      map.push_back(vector<int> (m,inf));
    }
    rep(i,n){
      rep(j,m){
        map[i][j]=min(a[i],b[j]);
        if(a[i]==b[j])map[i][j]=999;
      }
    }
  }
  void show_map(){
    rep(i,n){
      rep(j,m){
        cout<<map[i][j]<<" ";
      }
      cout<<endl;
    }
  }
};
signed main(){
  cin>>n>>m;
  vector<int> a(n);
  vector<int> b(m);
  vector<int> sum;
  vector<int> memo(n*m+1,0);
  vector<int> num(n*m+1,0);
  vector<int> list;
  rep(i,n)cin>>a[i];
  rep(i,m)cin>>b[i];
  //Map grid;
  //grid.mkmap(a,b,num);
  rep(i,n){
    rep(j,m){
      if(a[i]==b[j]){
        sum.push_back(inf);
        ++num[a[i]];
        list.push_back(a[i]);
      }
      else{
        sum.push_back(min(a[i],b[j]));
      }
    }
  }
  sort(ALL(sum));
  rep1(i,n*m){
    memo[i]=memo[i-1];
    if(num[i]==1)++memo[i];
    else if(num[i]>1){
      cout<<0<<endl;
      return 0;
    }
  }
  int cur=1;
  int res=1;
  sum.push_back(inf);
  sum.push_back(inf);
  int last=sum[0];

  rep1(i,n*m){
    if(last==sum[i]){
      cur++;
      continue;
    }
    else{
      if(num[last]==1){
        rep1(k,cur){
          res*=last-1-memo[last]-i+k+1;
          res%=MOD;
        }
      }
      else{
        res*=cur;
        rep1(k,cur-1){
          res*=last-1-memo[last]-i+k+1;
          res%=MOD;
        }
      }
      cur=1;
    }
    //cout<<sum[i]-memo[sum[i]]-i<<endl;
    if(res<0)res=0;
    res%=MOD;
    last=sum[i];
    if(sum[i]==inf){
      break;
    }
  }

  cout<<res<<endl;
  //grid.show_map();
  /*rep(i,list.size()){
    cout<<list[i]<<endl;
  }*/
  //cout<<memo[182]<<endl;
  return 0;
}
