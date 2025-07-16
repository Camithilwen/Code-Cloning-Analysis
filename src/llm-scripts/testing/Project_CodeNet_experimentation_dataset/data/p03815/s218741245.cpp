#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1000000000;
constexpr ll INF = 5000000000000000000;

int main() {
    ll x;
    cin >> x;
    ll ans = 0;
    ans += x / 11 * 2;
    x -= x / 11 * 11;
    if (x >= 1 && x <= 6) ans += 1;
    if (x >= 7) ans += 2;
    cout << ans << "\n";
}
