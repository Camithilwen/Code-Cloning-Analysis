#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

const ll MOD=1e9+7;

int main(){
  int n;
  cin>>n;
  
  vector<int> A(n);
  rep(i,n) cin>>A[i];
  
  int x=0,y=0,z=0;
  
  ll ans=1;
  rep(i,n){
    if(A[i]==x && A[i]==y && A[i]==z){
      ans=ans*3%MOD;
      x++;
    }
    else if(A[i]==x && A[i]==y){
      ans=ans*2%MOD;
      x++;
    }
    else if(A[i]==x && A[i]==z){
      ans=ans*2%MOD;
      x++;
    }
    else if(A[i]==y && A[i]==z){
      ans=ans*2%MOD;
      y++;
    }
    else if(A[i]==x) x++;
    else if(A[i]==y) y++;
    else if(A[i]==z) z++;
    else{
      cout<<0<<endl;
      return 0;
    }
  }
  cout<<ans<<endl;

  return 0;
}