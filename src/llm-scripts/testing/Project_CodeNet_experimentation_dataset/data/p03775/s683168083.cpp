#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
ll MOD=1000000007;

ll ReturnDigit(ll n){
  int keta=1;
  while(n/10!=0){
    n /= 10;
    keta++;
  }
  return keta;
}

int main(){
  ll n; cin>>n;
  ll ans = 100000000000;
  for (ll i=1; i*i<=n; i++){
    if (n%i==0){
      ll A = i;
      ll B = n/i;
      //cout << "A" << A << endl;
      //cout << "B" << B << endl;
      ans = min(ans, max(ReturnDigit(A),ReturnDigit(B)));
    }
  }
  cout << ans << endl;
  return 0;
}