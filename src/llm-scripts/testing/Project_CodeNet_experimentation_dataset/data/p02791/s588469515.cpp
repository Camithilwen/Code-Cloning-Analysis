#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int ans = 0;
  int minimum = N;
  for(int i = 0; i < N; i++) {
    int P;
    cin >> P;
    if(P <= minimum) {
      minimum = P;
      ans++;
    }
  }
  cout << ans << endl;
}