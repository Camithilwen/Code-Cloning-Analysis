#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n; cin >> n;
  string s; cin >> s;
  vi txt(n);
  rep(i,n){
    if(s[i] == 'R') txt[i] = 0;
    if(s[i] == 'G') txt[i] = 1;
    if(s[i] == 'B') txt[i] = 2;
  }
  vi rgb(3);
  rep(i,n) rgb[txt[i]]++;
  ll ans = 1;
  rep(i,3) ans *= rgb[i];
  rep(j,n){
    rep(i,j){
      if(2*j-i < n && txt[i] != txt[j] && txt[j] != txt[2*j-i] && txt[2*j-i] != txt[i]) ans--;
    }
  }
  cout << ans;
  cout << "\n";
  return 0;
}
