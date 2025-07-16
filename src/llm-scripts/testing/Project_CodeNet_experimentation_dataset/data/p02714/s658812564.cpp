#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  string s;
  cin >> n >> s;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    if(s[i] == 'R') a[i] = 0;
    if(s[i] == 'G') a[i] = 1;
    if(s[i] == 'B') a[i] = 2;
  }
  vector<ll> cnt(3);
  for(int i = 0; i < n; i++){
    cnt[a[i]]++;
  }
  ll ans = 1;
  for(int i = 0; i < 3; i++){
    ans *= cnt[i];
  }
  for(int j = 0; j < n; j++){
    for(int i = 0; i < j; i++){
      int k = j + (j - i);
      if(k < n){
        if(a[i] == a[j]) continue;
       	if(a[i] == a[k]) continue;
        if(a[k] == a[j]) continue;
        ans--;
      }
    }
  }
  cout << ans << endl;
  return 0;
}