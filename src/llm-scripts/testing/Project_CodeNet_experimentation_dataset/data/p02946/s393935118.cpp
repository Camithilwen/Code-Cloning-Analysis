#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main() {
  int k,x;
  cin >> k >> x;
  for (int i = x-k+1; i < x+k; i++) {
    cout << i << " ";
  }
  cout << endl;
}
