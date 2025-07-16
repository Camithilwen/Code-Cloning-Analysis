#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  ll n;
  cin >> n;
  string s;
  map<string, int> mps;
  for(int i = 0; i < n; ++i)
  {
    cin >> s;
    mps[s]++;
  }
  ll m;
  cin >> m;
  string t;
  map<string, int> mpt;
  for(int i = 0; i < m; ++i)
  {
    cin >> t;
    mpt[t]++;
  }

  int ans = 0;
  for(const auto& m : mps)
  {
    ans = max(ans, mps[m.first] - mpt[m.first]);
  }
  cout << ans;


}

int main()
{
  fastio;
  solve();

  return 0;
}