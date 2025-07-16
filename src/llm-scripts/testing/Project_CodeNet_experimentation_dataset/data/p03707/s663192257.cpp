#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

int main()
{
  int n,m,q;
  cin>>n>>m>>q;
  vector<string> t(n+2);
  for(int i:irange(0,n)) {
    string s;
    cin>>s;
    t[i+1] = "0" + s + "0";
  }
  t[0] = t[n+1] = string(m+2, '0');
  vector<vecint> connects_v(n, vecint(m+1));
  vector<vecint> connects_h(n+1, vecint(m));
  for(int i:irange(0,n)) {
    for (int j:irange(0,m+1)) {
      bool left = t[i+1][j] == '1';
      bool right = t[i+1][j+1] == '1';
      if (left && right) {
        connects_v[i][j] = 1;
      }
    }
  }
  for (int i:irange(0,n+1)) {
    for (int j:irange(0,m)) {
      bool top = t[i][j+1] == '1';
      bool bottom = t[i+1][j+1] == '1';
      if (top && bottom) {
        connects_h[i][j] = 1;
      }
    }
  }
  vector<vecint> psumcv(n+1, vecint(m+2));
  vector<vecint> psumch(n+2, vecint(m+1));
  for(int i:irange(0,n)) {
    for (int j:irange(0,m+1)) {
      psumcv[i+1][j+1] = psumcv[i][j+1] + connects_v[i][j];
    }
  }
  for (int i:irange(0,n+1)) {
    for (int j:irange(0,m+1)) {
      psumcv[i][j+1] += psumcv[i][j];
    }
  }
  for (int i:irange(0,n+1)) {
    for (int j:irange(0,m)) {
      psumch[i+1][j+1] = psumch[i+1][j] + connects_h[i][j];
    }
  }
  for (int i:irange(0,n+1)) {
    for (int j:irange(0,m+1)) {
      psumch[i+1][j] += psumch[i][j];
    }
  }
  vector<vecint> surfs(n+1, vecint(m+1));
  for (int i:irange(0,n)) {
    for (int j:irange(0,m)) {
      if (t[i+1][j+1] == '1') {
        surfs[i+1][j+1] = 1;
      }
    }
  }
  for (int i:irange(0,n+1)) {
    for (int j:irange(0,m)) {
      surfs[i][j+1] += surfs[i][j];
    }
  }
  for (int i:irange(0,n)) {
    for (int j:irange(0,m+1)) {
      surfs[i+1][j] += surfs[i][j];
    }
  }
  for(int query : irange(0,q)) {
    int x1,y1,x2,y2;
    cin>>y1>>x1>>y2>>x2;
    int connects = 0;
    connects += psumcv[y2][x2] - psumcv[y1-1][x2] - psumcv[y2][x1] + psumcv[y1-1][x1];
    connects += psumch[y2][x2] - psumch[y2][x1-1] - psumch[y1][x2] + psumch[y1][x1-1];
    --y1;--x1;
    int s = surfs[y2][x2] - surfs[y2][x1] - surfs[y1][x2] + surfs[y1][x1];
    int res = s - connects;
    cout<<res<<endl;
  }
  return 0;
}
