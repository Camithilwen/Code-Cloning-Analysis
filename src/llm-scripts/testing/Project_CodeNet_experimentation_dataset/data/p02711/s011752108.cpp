#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 

int main() {
  int n;
  cin >> n;
  if ((n-7) % 10 == 0) {
    cout << "Yes" << endl;
    return 0;
  }
  n /= 10;
  if ((n-7) % 10 == 0) {
    cout << "Yes" << endl;
    return 0;
  }
  n /= 10;
  if ((n-7) % 10 == 0) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}