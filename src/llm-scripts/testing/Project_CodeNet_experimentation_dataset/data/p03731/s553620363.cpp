#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
  ll N, T;
  cin >> N >> T;
  
  vector<ll> time(N);
  
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> time[i];
  }
  
  for (int i = 0; i < N-1; i++) {
    if (time[i+1] - time[i] < T) {
      ans += time[i+1]- time[i];
    } else {
      ans += T;
    }
  }
  
  ans += T;
  
  cout << ans << endl;
  
  
  
  
  
  
}