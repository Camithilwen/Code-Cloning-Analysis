#include<bits/stdc++.h>
#define rep(i,n)  for(ll i=0; i<n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF 1e9
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
  int n; cin >> n;
  string s,t; cin >> s >> t;
  int ans = s.size()+t.size();
  for(int i = n; 0 <= i; i--)
  if(s.find(t.substr(0,i)) != string::npos){
    ans -= i;
    break;
  }
  cout << ans;
  cout << "\n";
  return 0;
}
