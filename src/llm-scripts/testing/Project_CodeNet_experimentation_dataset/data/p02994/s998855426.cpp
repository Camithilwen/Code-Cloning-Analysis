#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Graph = vector<vector<ll>>;

int main(){
  int n,l; cin>>n>>l;
  vector<pair<int, bool> > fla;
  for (size_t i = 0; i < n; i++)
  {
    int tmpfl = l + i;
    if (tmpfl< 0)
    {
      tmpfl *= -1;
      fla.push_back(make_pair(tmpfl , true));
      continue;
    }
    fla.push_back(make_pair(tmpfl , false));
    
  }
  sort(fla.begin(), fla.end());
  
  fla.erase(fla.begin());
  ll ans =0;
  for (auto &&i : fla)
  {
    ans += i.second ? -1 * i.first : i.first ;
  }
  cout << ans << endl;
}