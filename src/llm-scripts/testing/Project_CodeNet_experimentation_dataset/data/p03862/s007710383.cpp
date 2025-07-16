#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, x;
  cin >> n >> x;
  long long ans = 0, now = 0;
  for(int i = 0; i < n; i++){
    long long a;
    cin >> a;
    long long dis = max((long long)0, now + a - x);
    ans += dis;
    now = a - dis;
  }
  
  cout << ans << endl;
}