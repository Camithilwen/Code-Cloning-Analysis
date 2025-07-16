#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int n,k;

int f(int x,vector<int>v){
  int ans=0;
  for(int i=min(x-1,n-1);i>=0;i--){
    int res=0;
    int p=x-1-i;
    vector<int> t(i+1);
    rep(j,i+1) t[j]=v[j];
    sort(t.begin(),t.end());
    rep(j,i+1){
      if(p>0&&t[j]<0){
        p--;
      }else res+=t[j];
    }
    ans=max(ans,res);
  }
  return ans;
}

int main(){
  cin>>n>>k;
  vector<int> v(n);
  rep(i,n) cin>>v[i];
  
  vector<int> u(n);
  rep(i,n) u[i]=v[i];
  reverse(u.begin(),u.end());
  
  int ans=0;
  if(k>=n){
    ans=f(k,u);
  }else{
    rep(i,k){
   	  ans=max(f(i,u)+f(k-i,v),ans);
    }
  }
  cout<<ans<<endl;
}