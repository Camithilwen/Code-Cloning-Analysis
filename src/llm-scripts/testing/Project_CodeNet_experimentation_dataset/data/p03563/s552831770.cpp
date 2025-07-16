#include <bits/stdc++.h>
using namespace std;

  int main() {
  double R = 0;
  cin >> R;//現在のレーティング
  double G = 0;
  cin >> G;//したいレーティング
  //(R + ans) / 2 = G
  //R + ans = 2*G
  double ans  = 0;
  ans = 2*G - R;
    cout << ans << endl;
}
