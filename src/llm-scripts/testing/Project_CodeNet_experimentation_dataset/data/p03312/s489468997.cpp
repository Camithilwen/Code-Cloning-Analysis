#include <bits/stdc++.h>
using namespace std;

vector<int> calc_cut_left(vector<long long> pref, int n) {
  vector<int> ans(n);
  int cur = 0;
  ans[1] = 0;
  for (int i = 2; i + 2 < n; i++) {
    long long s1 = abs(pref[cur + 1] - (pref[i] - pref[cur + 1]));
    long long s2 = abs(pref[cur] - (pref[i] - pref[cur]));
    while (abs(pref[cur + 1] - (pref[i] - pref[cur + 1])) < abs(pref[cur] - (pref[i] - pref[cur])))
      cur++;
    ans[i] = cur;
  }
  return ans;
}

vector<int> calc_cut_right(vector<long long> pref, int n) {
  vector<int> ans(n);
  int cur = n - 2;
  ans[n - 3] = cur;
  for (int i = n - 4; i >= 1; i--) {
    long long s1 = abs((pref[n - 1] - pref[cur - 1]) - (pref[cur - 1] - pref[i]));
    long long s2 = abs((pref[n - 1] - pref[cur]) - (pref[cur] - pref[i]));
    while (abs((pref[n - 1] - pref[cur - 1]) - (pref[cur - 1] - pref[i])) < abs((pref[n - 1] - pref[cur]) - (pref[cur] - pref[i])))
      cur--;
    ans[i] = cur;
  }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  vector<long long> pref(n, a[0]);
  for (int i = 1; i < n; i++)
    pref[i] = pref[i - 1] + a[i];
  vector<int> pos_left = calc_cut_left(pref, n);
  vector<int> pos_right = calc_cut_right(pref, n);
  long long ans = -1;
  for (int i = 1; i + 2 < n; i++) {
    int l = pos_left[i];
    int r = pos_right[i];
    long long s1 = pref[l];
    long long s2 = pref[i] - pref[l];
    long long s3 = pref[r] - pref[i];
    long long s4 = pref[n - 1] - pref[r];
    long long cur = max({s1, s2, s3, s4}) - min({s1, s2, s3, s4});
    if (ans == -1 || cur < ans)
      ans = cur;
  }
  printf("%lld\n", ans);
  return 0;
}