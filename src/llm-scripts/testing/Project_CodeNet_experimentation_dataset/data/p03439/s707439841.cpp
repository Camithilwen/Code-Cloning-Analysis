#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

const string v = "Vacant";
const string m = "Male";
const string f = "Female";

int main(){
  int n;
  cin >> n;
  cout << 0 << endl;
  string sl;
  cin >> sl;
  if(sl == v) return 0;
  string sr;
  cout << n-1 << endl;
  cin >> sr;
  if(sr == v) return 0;
  int l = 0, r = n-1;
  rep(i, 20){
    int m = (l+r)/2;
    cerr << l << " " << m << " " << r << endl;
    int dl = m - l, dr = r - m;
    cout << m << endl;
    string sm;
    cin >> sm;
    if(sm == v) return 0;
    if(dl % 2 == 0){
      if(sl == sm){
        l = m;
      }else{
        sr = sm;
        r = m;
      }
    }else{
      if(sl != sm){
        sl = sm;
        l = m;
      }else{
        sr = sm;
        r = m;
      }
    }
  }
  return 1;
}