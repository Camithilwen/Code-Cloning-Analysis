#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,q;
  cin >> n >> q;

  set<P> ds;
  rep(i,n){
    int s,t,x;
    cin >> s >> t >> x;
    ds.emplace(s-x,x);
    ds.emplace(t-x,-x);
  }
  set<int> s; auto itr = ds.begin();
  rep(i,q){
    int d;
    cin >> d;
    while(itr!=ds.end() && itr->first<=d){
      if(itr->second>0) s.insert(itr->second);
      else s.erase(-itr->second);
      ++itr;
    }
    cout << (s.empty() ? -1 : *s.begin()) << endl;
  }
}
