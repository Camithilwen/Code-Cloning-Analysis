#include<bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
struct dish{
  ll A,B;
  bool operator<(const dish &o) const {return A+B < o.A+o.B;}
  bool operator>(const dish &o) const {return A+B > o.A+o.B;}
};
int main(){
  ll N,i,ans = 0;scanf("%lld",&N);
  dish D[N];
  for(i=0;i<N;i++) scanf("%lld%lld",&D[i].A,&D[i].B);
  sort(D,D+N,greater<dish>());
  for(i=0;i<N;i++){
    if(i&1) ans -= D[i].B;
    else ans += D[i].A;
  }
  printf("%lld\n",ans);
}