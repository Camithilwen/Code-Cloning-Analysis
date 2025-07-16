#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<int> even(1e5+1, 0);
  vector<int> odd(1e5+1, 0);
  rep(i,n) {
    int v;
    cin >> v;
    if (i%2) {
      odd[v]++;
    } else {
      even[v]++;
    }
  }
  pair<int, int> mx_odd = make_pair(0, 0);
  pair<int, int> mx_even = make_pair(0, 0);
  pair<int, int> mx_odd_2 = make_pair(0, 0);
  pair<int, int> mx_even_2 = make_pair(0, 0);

  rep(i, 1e5+1) {
    if (odd[i] > mx_odd.second) {
      mx_odd_2 = mx_odd;
      mx_odd = make_pair(i, odd[i]);
    } else {
      if (odd[i] > mx_odd_2.second) mx_odd_2 = make_pair(i, odd[i]);
    }
    if (even[i] > mx_even.second) {
      mx_even_2 = mx_even;
      mx_even = make_pair(i, even[i]);
    } else {
      if (even[i] > mx_even_2.second) mx_even_2 = make_pair(i, even[i]);
    }
  }
  int h = n/2;
  int odd_diff = (n/2 - mx_odd.second);
  int even_diff = (n/2 - mx_even.second);
  int ans = 0;
  if (mx_even.first == mx_odd.first) {
    int a = (h - mx_even.second) + (h - mx_odd_2.second);
    int b = (h - mx_odd.second) + (h - mx_even_2.second);
    ans = min(a, b);
  } else {
    ans = (h - mx_odd.second) + (h - mx_even.second);
  }
  cout << ans << endl;

  return 0;
}