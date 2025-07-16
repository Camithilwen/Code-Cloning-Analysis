#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  int max_v = 100000;
  vector<int> va(n), cnt1(max_v + 1, 0), cnt2(max_v + 1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
    if (i % 2 == 0) {
      cnt1[va[i]]++;
    } else {
      cnt2[va[i]]++;
    }
  }

  auto max2 = [](vector<int> &cnt) {
    array<int, 2> res{0, 0};
    for (int i = 0; i < cnt.size(); i++) {
      if (cnt[res[0]] < cnt[i]) {
        res[1] = res[0];
        res[0] = i;
      } else if (cnt[res[1]] < cnt[i]) {
        res[1] = i;
      }
    }

    return res;
  };

  auto max2_even = max2(cnt1), max2_odd = max2(cnt2);
  int ans;
  if (max2_even[0] != max2_odd[0]) {
    ans = n - cnt1[max2_even[0]] - cnt2[max2_odd[0]];
  } else {
    ans = n - max(cnt1[max2_even[0]] + cnt2[max2_odd[1]],
                  cnt1[max2_even[1]] + cnt2[max2_odd[0]]);
  }

  cout << ans << '\n';
}
