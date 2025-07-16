#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf
#define lcm hddalkwjeidjjhasda
#define random_shuffle asdasdd

const int MAXN = 2 * 105000;
const long long INF = 1e15;

int n;
int a[MAXN];
// long long dpl[MAXN], dpr[MAXN];
// pair<long long, long long> pl[MAXN], pr[MAXN];
long long sum;
long long total;
multiset <long long> st1, st2;

int main() { 

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    total += a[i];
  }

  for (int i = n - 1; i > 0; i--) {
    sum += a[i];
    st2.insert(sum);
  }

  sum = 0;
  long long ans = INF;
  for (int i = 0; i + 1 < n; i++) {
    sum += a[i];
    if (st2.find(total - sum) != st2.end()) {
      st2.erase(st2.find(total - sum));
    }

    if (sz(st1) && sz(st2)) {
      vector<long long> v1, v2; 
      auto it = st1.lower_bound(sum / 2);
      if (it != st1.end()) {
        v1.push_back(*it);
      }
      if (it != st1.begin()) {
        it--;
        v1.push_back(*it);
      }

      it = st2.lower_bound((total - sum) / 2);
      if (it != st2.end()) {
        v2.push_back(*it);
      }
      if (it != st2.begin()) {
        it--;
        v2.push_back(*it);
      }

      for (auto x : v1) {
        for (auto y : v2) {
          long long mn = min(x, y);
          long long mx = max(x, y);
          mn = min(mn, min(sum - x, total - sum - y));
          mx = max(mx, max(sum - x, total - sum - y));
          ans = min(ans, mx - mn);
        }
      }
    }

    st1.insert(sum);
  }

  // for (int i = 0; i < n; i++) {
  //   sum += a[i];
  //   dpl[i] = INF;
  //   if (sz(st)) {
  //     auto it = st.lower_bound(sum / 2);
  //     if (it != st.end()) {
  //       long long cur = *it;
  //       dpl[i] = min(dpl[i], abs(cur - (sum - cur)));
  //     }
  //     if (it != st.begin()) {
  //       it--;
  //       long long cur = *it;
  //       dpl[i] = min(dpl[i], abs(cur - (sum - cur)));
  //     }
  //   }
  //   st.insert(sum);
  // }

  // st.clear();
  // sum = 0;
  // for (int i = n - 1; i >= 0; i--) {
  //   sum += a[i];
  //   dpr[i] = INF;
  //   if (sz(st)) {
  //     auto it = st.lower_bound(sum / 2);
  //     if (it != st.end()) {
  //       long long cur = *it;
  //       dpr[i] = min(dpr[i], abs(cur - (sum - cur)));
  //     }
  //     if (it != st.begin()) {
  //       it--;
  //       long long cur = *it;
  //       dpr[i] = min(dpr[i], abs(cur - (sum - cur)));
  //     }
  //   }
  //   st.insert(sum);
  // }

  // for (int i = 0; i < n; i++) {
  //   cerr << dpl[i] << " ";
  // }
  // cerr << endl;

  /* long long ans = INF;
  for (int i = 1; i + 2 < n; i++) {
    ans = min(ans, max(dpl[i], dpr[i + 1]));
  } */

  cout << ans << endl;

  return 0;
}
