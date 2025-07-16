#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
int main() {
  int A, B;
  cin >> A >> B;
  int Xa, Xb, Xc;
  int co = 0;
  rep2(i, A, B) {
    Xa = i % 10;
    Xb = (i - Xa) % 100 / 10;
    Xc = (i - Xa - Xb*10) % 1000 / 100;
    if(Xa * 10001 + Xb * 1010 + Xc * 100 == i) {
      co++;
    }
  }
  cout << co << endl;
}