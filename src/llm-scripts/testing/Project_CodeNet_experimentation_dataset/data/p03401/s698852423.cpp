#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n;
  cin >> n;
  vector<int> a;
  a.push_back(0);
  rep (i, n) { 
    int x; cin >> x;
    a.push_back(x);
  }
  a.push_back(0);

  ll sum = 0;
  for (int i = 1; i < n + 2; i++) {
    sum += abs(a[i] - a[i - 1]);
    //printf("abs(a[%d] - a[%d]) = %d\n", i, i - 1, abs(a[i] - a[i - 1]));
  }

  for (int i = 1;  i < n + 1; i++) {
    ll tmp = sum;
    tmp -= abs(a[i] - a[i - 1]);
    tmp -= abs(a[i + 1] - a[i]);
    tmp += abs(a[i - 1] - a[i + 1]);
    cout << tmp << endl;
  }

  //printVec(a);

  //printf("sum = %d\n", sum);

  return 0;
}
