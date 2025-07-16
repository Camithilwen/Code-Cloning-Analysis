#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std; typedef long long ll;
typedef pair<string,string> P; const int INF = 1e9+1;
int main() {
  int n; cin>>n;
  string s; cin>>s;

  map<P, ll> mp;
  for(int i=0;i<(1<<n);i++) {
    string s1, s2;
    for(int j=0;j<n;j++) {
      if (i & (1<<j)) s1+=s[j];
      else s2+=s[j];
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    mp[make_pair(s1,s2)]++;
  }
  ll an=0;
  for(int i=0;i<(1<<n);i++) {
    string s1, s2;
    for(int j=0;j<n;j++) {
      if (i & (1<<j)) s1+=s[n+j];
      else s2+=s[n+j];
    }
    an += mp[make_pair(s1,s2)];
  }
  cout<<an<<endl;
}