//\\//\\ * * * //\\// ||
#include <bits/stdc++.h> 

#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;

const int N = 110;

int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (a[i] != a[j] && a[i] != a[k] && a[j] != a[k]) {
          if (a[i] + a[j] > a[k]) {
            ++ans;
//            debug(i);
//            debug(j);
//            debug(k);
//            debug(a[i]);
//            debug(a[j]);
//            debug(a[k]);
          }
        } 
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
