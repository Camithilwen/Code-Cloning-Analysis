#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
using ping = pair<ll, ll>;

int main(){
    ll X;
    cin >> X;
    ll cnt500 = 0;
    for (int i = 1;; i++) {
      if (i * 500 > X) break;
      else
        cnt500++;
    }
    X = X - cnt500 * 500;
    ll cnt5 = 0;
    for (int i = 1;; i++) {
      if (i * 5 > X) break;
      else
        cnt5++;
    }
    cout <<cnt500 * 1000 + cnt5 * 5 << endl;
    return 0;
}