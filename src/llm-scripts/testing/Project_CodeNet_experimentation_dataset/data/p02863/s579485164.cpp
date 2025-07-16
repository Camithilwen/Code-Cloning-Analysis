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
  int n,t;
  cin>>n>>t;
  vector<vecint> dp(n+1, vecint(t+3001, 0));
  vector<tuple<int,int>> vt;
  for(int i:irange(0,n)) {
    int a,b;
    cin>>a>>b;
    vt.emplace_back(a,b);
  }
  boost::sort(vt);
  for(int i:irange(0,n)) {
    int a,b;
    tie(a,b) = vt[i];
    for(int j:irange(0,t+3001)) {
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      if (j < t) {
        dp[i+1][j+a] = max(dp[i+1][j+a], dp[i][j] + b);
      }
    }
  }
  cout<<*boost::max_element(dp[n])<<endl;
  return 0;
}
