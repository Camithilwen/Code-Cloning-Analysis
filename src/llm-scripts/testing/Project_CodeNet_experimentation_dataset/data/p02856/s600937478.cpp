#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;
//const ll MOD=998244353;

int main(){
  int M; cin>>M;
  ll sum=0,sumC=0;
  rep(i,M){
    ll d,c; cin>>d>>c;
    sum+=d*c;
    sumC+=c;
  }
  cout<<sumC-1+(sum-1)/9<<endl;
  return 0;
}