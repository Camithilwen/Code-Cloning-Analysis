#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define sz(obj) ((int)(obj).size())
#define pf push_front
#define pb push_back

int main()
{
  int n;
  cin >> n;
  int a[3] = {0};
  REP(i, n) cin >> a[i];
  if (n == 2){
    FOR(i, 1, min(a[0], a[1]) + 1){
      if (a[0] % i == 0 && a[1] % i == 0) cout << i << endl;
    }
  }
  else {
    FOR(i, 1, min(min(a[0], a[1]), a[2]) + 1){
      if (a[0] % i == 0 && a[1] % i == 0 && a[2] % i == 0) cout << i << endl;
    }
  }
}