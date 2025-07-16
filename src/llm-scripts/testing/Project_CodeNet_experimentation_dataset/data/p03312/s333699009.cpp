// g++ A.cpp -Wall -Wextra -Woverflow -Wshadow -O2
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <cmath>
#include <iomanip>
#include <set>
#include <bitset>

using namespace std;
 
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pii> edge;

const int MAXN = 2 * 100005;
int n;
LL a[MAXN];
LL pref[MAXN];
LL get(int a, int b) {
  return pref[b] - pref[a - 1];
}
int find(int L, int R) {
  int b1 = L, b2 = R;
  while (L + 1 < R) {
    int mid = (L + R) / 2;
    LL v1 = get(b1, mid);
    LL v2 = get(mid + 1, b2);
    if (v1 < v2) {
      L = mid;
    } else if (v1 > v2) {
      R = mid;
    } else {
      L = mid;
      R = mid;
      break;
    }
  }
  if (abs(get(b1, L) - get(L + 1, b2)) < abs(get(b1, R) - get(R + 1, b2))) {
    return L;
  }
  return R;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }
  LL ans = LLONG_MAX;
  for (int i = 2; i <= n - 2; i++) {
    int L = find(1, i);
    int R = find(i + 1, n);
    LL B = get(1, L);
    LL C = get(L + 1, i);
    LL D = get(i + 1, R);
    LL E = get(R + 1, n);
    LL diff = max(B, max(C, max(D, E))) - min(B, min(C, min(D, E)));
    ans = min(ans, diff);
  }
  cout << ans << endl;
} 