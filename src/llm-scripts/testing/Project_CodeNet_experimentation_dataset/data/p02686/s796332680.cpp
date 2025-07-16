#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  string s;
  vector<pair<ll,ll> > p;

  for(ll i=0; i<n; i++) {
    cin >> s;
    ll x=0, d=0;
    for(ll j=0; j<(ll)s.size(); j++) {
      if (s[j]=='(') x++;
      if (s[j]==')') {
        x--;
        d = min(d, x);
      }
    }
    if(x<0) d-=x;
    p.push_back(make_pair(-d,x));
  }
  
  sort(p.begin(), p.end());
  
  ll h=0;
  for(ll i=0; i<n; i++) {
    if(p[i].second>=0) {
      if(h-p[i].first<0) {
        cout << "No" << '\n';
        return 0;
      }
      h += p[i].second;
    }
  }
  for(ll i=n-1; i>=0; i--) {
    if(p[i].second<0) {
      if(h-p[i].first+p[i].second<0) {
        cout << "No" << '\n';
        return 0;
      }
      h += p[i].second;
    }
  }
  if(h!=0) {
    cout << "No" << '\n';
    return 0;
  }
  
  cout << "Yes" << '\n';
  return 0;
}