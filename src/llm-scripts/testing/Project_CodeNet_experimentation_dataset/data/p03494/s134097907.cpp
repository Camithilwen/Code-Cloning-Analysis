#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int ans = 100000000;
  
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    
    int count = 0;
    
    if (x % 2 != 0)
      ans = 0;
    
    while (x % 2 == 0) {
      x /= 2;
      count++;
    }
    ans = min (ans,count);
  }
  cout << ans << endl;
}
  