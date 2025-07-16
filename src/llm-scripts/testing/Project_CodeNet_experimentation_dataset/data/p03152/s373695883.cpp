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
  ll n = 0;
  ll m = 0;
  cin >> n >> m;
  vector<ll> a(n);
  vector<ll> b(m);
  map<ll,ll> ac;
  map<ll,ll> bc;
  for(int i = 0;i < n;i++)cin >> a[i],ac[a[i]]++;
  for(int i = 0;i < m;i++)cin >> b[i],bc[b[i]]++;
  if((ll)ac.size() != n || (ll)bc.size() != m){
    cout << 0 << endl;
    return 0;
  }
  vector<ll> awa(n*m);
  vector<ll> bwa(n*m);
  for(int i = n*m - 1;i >= 0;i--){
    if(ac[i + 1] == 1)awa[i] = 1;
    if(i != n*m - 1)awa[i] += awa[i + 1];
  }
  for(int i = n*m - 1;i >= 0;i--){
    if(bc[i + 1] == 1)bwa[i] = 1;
    if(i != n*m - 1)bwa[i] += bwa[i + 1];
  }
  ll res = 1;
  ll mod = pow(10,9) + 7;
  for(int i = n*m - 1;i >= 0;i--){
    if(ac[i + 1] == 1 && bc[i + 1] == 0)res *= max((ll)0,bwa[i + 1]);
    if(ac[i + 1] == 0 && bc[i + 1] == 1)res *= max((ll)0,awa[i + 1]);
    if(ac[i + 1] == 0 && bc[i + 1] == 0)res *= max((ll)0,awa[i + 1] * bwa[i + 1] - (n*m - i - 1));
    res %= mod;
  }
  cout << res << endl;
}