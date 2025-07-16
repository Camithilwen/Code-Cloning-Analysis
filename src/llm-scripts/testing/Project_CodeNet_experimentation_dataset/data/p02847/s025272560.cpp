#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  vector<string> dow = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  string s;
  cin >> s;
  cout << 7 - distance(dow.begin(), find(dow.begin(), dow.end(), s)) << endl;
  return 0;
}
