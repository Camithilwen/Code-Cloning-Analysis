#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

int main() {
  int n;
  cin >> n;
  map<int, long long> d;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    if(i == 0 && a != 0){
      cout << 0 << endl;
      return 0;
    }
    d[a]++;
  }
  
  long long sum = 0, ans = 1, last = 1;
  bool ok = false;
  for(int i = 0; i < n; i++){
    if(sum == n){
      ok = true;
      break;
    }
    else if(!d.count(i)) break;
    if(d.at(0) > 1) break;
    long long now = d.at(i);
    sum += now;
    long long mul = 1;
    for(int i = 0; i < now; i++){
      mul *= last;
      mul %= mod;
    }
    ans *= mul;
    ans %= mod;
    last = now;
    if(sum == n) ok = true;
  }
  
  if(!ok) ans = 0;
  cout << ans << endl;
}