#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n;
  string s;
  cin >> n >> s;
  for(ll j=0;j<4;j++) {
    vec a(n);
    a[0]=j&1;
    a[1]=(j>>1)&1;
    for(ll i=1;i<n-1;i++) {
      ll c=i%n;
      if(a[c]) {
        if(s[c]=='o') {
          a[(c+1)%n]=a[(c-1)%n];
        }
        else {
          a[(c+1)%n]=1-a[(c-1)%n];
        }
      }
      else {
        if(s[c]=='x') {
          a[(c+1)%n]=a[(c-1)%n];
        }
        else {
          a[(c+1)%n]=1-a[(c-1)%n];
        }
      }
    }
    ll f=1;
    for(ll i=0;i<2;i++) {
      if(a[(n+i-1)%n]) {
        if(s[(n+i-1)%n]=='o') {
          if(a[(n+i-2)%n]!=a[i])f=0;
        }
        else {
          if(a[(n+i-2)%n]==a[i])f=0;
        }
      }
      else {
        if(s[(n+i-1)%n]=='x') {
          if(a[(n+i-2)%n]!=a[i])f=0;
        }
        else {
          if(a[(n+i-2)%n]==a[i])f=0;
        }
      }
    }
    if(f) {
      for(ll i=0;i<n;i++) {
        if(a[i]) {
          cout << "S";
        }
        else {
          cout << "W";
        }
      }
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}