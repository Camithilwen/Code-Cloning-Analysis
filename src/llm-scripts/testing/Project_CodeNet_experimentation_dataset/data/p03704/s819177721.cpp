#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

ll solve(ll d, string s){
  ll ans = 0;
  ll m = s.size();
  vll t(18, 1);
  for(int i=1;i<18;i++) t[i] = (t[i-1]*10);

  //std::cout << s << '\n';
  for(int i=0;i<(1<<(m/2));i++){
    ll num = 0, cnt = 1;
    //bitset<5> b(i);
    //std::cout << b << '\n';
    for(int j=0;j<m/2;j++){
      ll l = m - 1 - j, r = j;
      string tmp = to_string(num);
      ll x = (tmp.size()<=j?0:tmp[tmp.size()-1-j] - '0');
      ll y = (s.size()<=j?0:s[s.size()-1-j] - '0');
      if((i>>j)&1){ //加算
        ll z = (y - x + 10)%10, ad;

        if(z==0){
          ad = 0;
          cnt *= 10-(j==0);
        }else{
          ll L = 10 - z;
          ad = L * t[l] - L*t[r];
          cnt *= (10 - L) - (j==0);
          num += ad;
        }
      }else{ //減算
        ll z = (y-x+10)%10, sb;
        if(z==0){
          sb = 0;
          cnt *= 0;
        }else{
          ll L = z;
          sb = L*t[l] - L*t[r];
          cnt *= (10 - L) - (j==0);
          num -= sb;
        }
      }
      //std::cout << num << " " << cnt << '\n';
    }
    if(num==d) ans += cnt;
  }
  if(m%2) ans *= 10;
  return ans;
}

int main(int argc, char const *argv[]) {
  ll d;std::cin >> d;
  string k = to_string(d);
  ll ret = 0;
  for(int i=0;i+k.size()<=18;i++){
    string ad(i, '0');
    ret += solve(d, ad + k);
  }

  std::cout << ret << '\n';
  return 0;
}
