#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  map<int, int> odd, even;
  rep(i, n) {
    if (i % 2 == 0)
      odd[v[i]]++;
    else
      even[v[i]]++;
  }

  int num_even1 = 0, num_even2 = 0, num_odd1 = 0, num_odd2 = 0;
  int times_even1 = 0, times_even2 = 0, times_odd1 = 0, times_odd2 = 0;

  //偶数番目最大値
  int count = 0;
  for (auto itr = even.begin(); itr != even.end(); itr++) {
    if (itr->second > count) {
      count = itr->second;
      num_even1 = itr->first;
    }
  }
  times_even1 = count;

  //偶数番目二番目に大きい値
  count = 0;
  for (auto itr = even.begin(); itr != even.end(); itr++) {
    if (itr->second > count && itr->first != num_even1) {
      count = itr->second;
      num_even2 = itr->first;
    }
  }
  times_even2 = count;

  //奇数番目最大値
  count = 0;
  for (auto itr = odd.begin(); itr != odd.end(); itr++) {
    if (itr->second > count) {
      count = itr->second;
      num_odd1 = itr->first;
    }
  }
  times_odd1 = count;

  //奇数番目二番目に大きい値
  count = 0;
  for (auto itr = odd.begin(); itr != odd.end(); itr++) {
    if (itr->second > count && itr->first != num_odd1) {
      count = itr->second;
      num_odd2 = itr->first;
    }
  }
  times_odd2 = count;

  //出力
  if (num_even1 == num_odd1) {
    cout << min(n - times_even1 - times_odd2, n - times_even2 - times_odd1)
         << endl;
  } else {
    cout << n - times_even1 - times_odd1 << endl;
  }
  return 0;
}