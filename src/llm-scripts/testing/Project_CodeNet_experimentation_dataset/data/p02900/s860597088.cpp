#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y){
  if(x%y==0) return y;
  else return gcd(y,x%y);
}
int main(){
  ll A,B,C,D,i,ans = 1;scanf("%lld%lld",&A,&B);
  C = gcd(A,B);D = C;
  for(i=2;i*i<=C;i++){
    if(D%i==0){
      ans++;
      while(D%i==0) D /= i;
    }
  }
  if(D != 1) ans++;
  printf("%lld\n",ans);
}