#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  map<ll,ll> mp;
  for(int i = 0;i < n;i++)cin >> a[i],mp[a[i]]++;
  sort(a.rbegin(),a.rend());
  ll res = 0;
  for(int i = 0;i < n;i++){
    if(mp[a[i]] == 0)continue;
    mp[a[i]]--;
    ll now = 2;
    while(1){
      if(now > a[i])break;
      now *= 2;
    }
    ll pan = now - a[i];
    if(mp[pan] >= 1)res++,mp[pan]--;
  }
  cout << res << endl;
}