#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<bool> dislike(10, false);

bool isOK(int p) {
  while (p) {
    int d = p % 10;
    if (dislike[d]) return false;
    p /= 10;
  }
  return true;
}

int main() {
  int n, k;
  cin >> n >> k;
  rep(i, k) {
    int d;
    cin >> d;
    dislike[d] = true;
  }

  int pay = n;
  while (!isOK(pay)) pay++;
  cout << pay << endl;
  return 0;
}