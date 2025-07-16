#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

void dfs(vector<vector<int>> &tree, vector<int> &d, int p){
  for(auto i : tree.at(p)){
    if(d.at(i) != -1) continue;
    d.at(i) = d.at(p) + 1;
    dfs(tree, d, i);
  }
}

int main(){
  int n, ta, ao;
  cin >> n >> ta >> ao;
  ta--; ao--;
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }

  vector<int> dta(n, -1), dao(n, -1);
  dta.at(ta) = 0; dao.at(ao) = 0;
  dfs(tree, dta, ta);
  dfs(tree, dao, ao);
  // rep(i, n){
  //   cerr << dta.at(i) << " ";
  // }
  // cerr << endl;
  // rep(i, n){
  //   cerr << dao.at(i) << " ";
  // }
  // cerr << endl;

  int ans = 0;
  rep(i, n){
    if(dao.at(i) > dta.at(i)){
      ans = max(ans, dao.at(i)-1);
    }
  }
  cout << ans << endl;

  return 0;
}