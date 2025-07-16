#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int n;
  while(cin>>n){
    if(n==0) break;
    vector<int> friends[501];
    int m;
    cin>>m;
    REP(i,m){
      int a,b;
      cin>>a>>b;
      friends[a].push_back(b);
      friends[b].push_back(a);
    }
    set<int> ans;
    REP(i,friends[1].size()){
      int s = friends[1][i];
      ans.insert(s);
      REP(i,friends[s].size()){
        ans.insert(friends[s][i]);
      }
    }

    if(ans.size()!=0)cout<<ans.size()-1<<endl;
    else cout<<0<<endl;
  }
  return 0;
}