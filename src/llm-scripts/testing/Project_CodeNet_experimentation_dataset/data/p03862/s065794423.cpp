#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

typedef long long ll;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int n, x;  cin >> n >> x;
  vector<int> a(n); cin >> a;
  ll ans = max(0, a[0]-x);
  for (int i = 0; i < n-1; ++i){
    ll now = max (min(a[i]+a[i+1]-x, a[i+1]), 0);
    ans += now;
    a[i+1] -= now;
  }
  cout << ans << "\n";
  return 0;
}