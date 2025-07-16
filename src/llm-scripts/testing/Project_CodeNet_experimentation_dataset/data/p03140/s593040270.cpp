#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n;
  cin >> n;
  vector<string> s(3);
  for(ll i=0;i<3;i++) {
    cin >> s[i];
  }
  ll ans=0;
  for(ll i=0;i<n;i++) {
    set<char> ss;
    for(ll j=0;j<3;j++) {
      ss.insert(s[j][i]);
    }
    ans+=ss.size()-1;
  }
  cout << ans << endl;
}