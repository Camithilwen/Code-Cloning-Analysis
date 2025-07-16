#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
int l[N], r[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  int lmx = 0, rmn = (int)1e9 + 1;
  for(int i = 0 ; i < n; i ++ ){
    cin >> l[i] >> r[i];
    lmx = max(lmx, l[i]);
    rmn = min(rmn, r[i]);
  }
  vector<pii> shits;
  for(int i = 0 ; i < n; i ++ ){
    shits.push_back(mp(rmn - l[i] + 1,r[i] - lmx + 1));
  }
  sort(shits.begin(), shits.end());
  int low = (int)1e9 + 1;
  int ans = 0;
  for(int i = 0 ; i < n; i ++ ){
    ans = max(ans, (r[i] - l[i] + 1) + max(rmn-lmx+1,0));
  }
  for(int i = 0 ; i + 1 < n; i ++ ){
    low = min(low, shits[i].se);
    ans = max(ans, max(0,low) + max(0,shits[i + 1].fi));
  }
  ans = max(ans, max(0,shits[0].fi) + max(0,shits[n-1].fi));
  cout << ans << "\n";
  return 0;
}