#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

int n, k, r, a[100100];
vector<int> e[100100];

int dfs(int i = 0) {
  int d = 0;
  for (int j : e[i])
    d = max(d, dfs(j) + 1);
  if (d + 1 >= k) {
    r += a[i] != 0;
    return -1;
  }
  return d;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i], a[i]--;
  r += a[0] != 0;
  a[0] = 0;
  for (int i = 1; i < n; i++)
    e[a[i]].push_back(i);
  dfs();
  cout << r << "\n";
}
