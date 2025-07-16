#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  vector<int> num(3);
  rep(i, 3) cin >> num.at(i);
  for(int i = 1; i < 3; i++) {
    int tmp = 0;
    tmp = num.at(0);
    num.at(0) = num.at(i);
    num.at(i) = tmp;
  }
  rep(i, 3) cout << num.at(i) << " ";
  cout << endl;
  return 0;
}