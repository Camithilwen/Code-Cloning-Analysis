#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int a,b,c,d;
  cin >> a >> b >>c >>d;
  int ans = min(a,b) + min(c,d);
  cout << ans << endl;


	return 0;
}

