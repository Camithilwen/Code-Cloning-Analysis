#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
// typedef pair<ll, ll> P;
typedef pair<string, string> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t = s;
  reverse(ALL(t));
  map<P, ll> mp1, mp2;
  REP(bit, 1 << n) {
    string r1 = "", b1 = "";
    string r2 = "", b2 = "";
    REP(i, n) {
      (bit >> i & 1 ? r1 : b1) += s[i];
      (bit >> i & 1 ? r2 : b2) += t[i];
    }
    mp1[P(r1, b1)]++;
    mp2[P(r2, b2)]++;
  }
  ll ans = 0;
  for (auto a : mp1) {
    if (mp2.find(a.first) != mp2.end()) {
      ans += a.second * mp2[a.first];
    }
  }
  cout << ans << endl;
  return 0;
}