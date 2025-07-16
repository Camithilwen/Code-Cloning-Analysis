#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const ll p=1000000007;
int main(){
  ll n;
  cin >> n;
  ll bb=0;
  ll k[n];
  rep(i,n){
    ll a,b;
    cin >> a >> b;
    bb+=b;
    k[i]=a+b;
  }
  sort(k,k+n);
  ll ans=0;
  rep(i,n-n/2){
    ans+=k[n-1-2*i];
  }
  cout << ans-bb << endl;
}
