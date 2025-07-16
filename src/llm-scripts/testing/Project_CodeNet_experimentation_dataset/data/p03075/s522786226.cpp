#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}



int main(){
  vector<ll> x(5);
  rep(i,5) cin >> x[i];
  ll k; cin >> k;

  if(x[4]-x[0]>k){
    cout << ":(" << endl;
    return 0;
  }

  cout << "Yay!" << endl;

  return 0;
} 

