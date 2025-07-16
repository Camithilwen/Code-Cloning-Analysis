#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

int main(){
  int n,q;
  cin>>n>>q;
  
  ll c,x,y;
  fenwick_tree<ll> fw(n);
  
  rep(i,n){
    cin>>x;
    fw.add(i,x);
  }
  
  rep(i,q){
    cin>>c>>x>>y;
    if(c==0) fw.add(x,y);
    else cout<<fw.sum(x,y)<<endl;
  }
   
  return 0;
}