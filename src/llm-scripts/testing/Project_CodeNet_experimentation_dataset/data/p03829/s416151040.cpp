#include<bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  long long A, B;
  cin >> A >> B;
  long long ans = 0;
  long long x;
  cin >> x;
  for (int i = 0; i < N - 1; i ++) {
    long long k = 0;
    cin >> k;
    ans += min((k - x) * A, B);
    x = k;
  }
  cout << ans << endl;
}
