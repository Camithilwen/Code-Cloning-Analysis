#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,sum,fs,bs,fbs;
  cin >> n;
  sum = n,fs = 0, bs = 0, fbs = 0;
  for (int i = 0; i < n; i++) {
    sum += i;
  }
  for (int i = 3; i <= n; i += 3) {
    fs += i;
  }
  for (int i = 5; i <= n; i += 5) {
    bs += i;
  }
  for (int i = 15; i <= n; i += 15) {
    fbs += i;
  }
  cout << sum-fs-bs+fbs << endl;
}