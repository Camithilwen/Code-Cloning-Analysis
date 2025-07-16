#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  ll n,a,b,c,d,e;
  cin>>n>>a>>b>>c>>d>>e;
  
  ll mi=min({a,b,c,d,e});
  ll x=(n+mi-1)/mi-1;
  
  cout<<x+5<<endl;
    
  return 0;
}