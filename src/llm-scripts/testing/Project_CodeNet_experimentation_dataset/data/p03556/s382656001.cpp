#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int64_t N, ans;
  cin >> N;
  for (int i=0; i<=sqrt(N); i++) {
    if (i*i<=N) {
      ans=i*i;
    }
  }
  cout << ans << endl;
}
