#include<bits/stdc++.h>
using namespace std;
int main () {
  int K, T;
  cin >> K >> T;
  int ma = 0;
  for (int i = 0; i < T; i ++) {
    int a;
    cin >> a;
    ma = max(ma, a);
  }
  int kj = K - ma;
  cout << max(ma - kj - 1, 0) << endl;
}