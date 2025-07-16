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
  cin >> n;
  vector<ll> a(n);
  for(int i = 0;i < n;i++)cin >> a[i];
  vector<ll> c;
  c.push_back(a[0]);
  for(int i = 1;i < n;i++){
    //if(i == 5)cout << c.size()<< " " << c[0] << " " << c[1] << " " << c[2] << endl;
    
    ll pushnum = 0;
    ll popit = lower_bound(c.begin(),c.end(),a[i]) - c.begin();
    if(popit == 0)pushnum = a[i];
    else{
      pushnum = a[i];
      c.erase(c.begin() + popit - 1);
    }
    
    ll pushit = lower_bound(c.begin(),c.end(),pushnum) - c.begin();
    c.insert(c.begin() + pushit,pushnum);
  }
  //cout << c[0] << " " << c[1] << " " << c[2] << endl;
  cout << c.size() << endl;
}