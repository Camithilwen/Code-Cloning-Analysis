#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  vector<vector<int>> ans(2);

  if(n%2 == 1){
    for(int l = 1, r = n-1; l < r; l++, r--){
        ans.at(0).push_back(l);
        ans.at(1).push_back(r);
    }
  }
  else{
    bool flag = false;
    for(int l = 1, r = n-1; l < r; l++, r--){
        if(!flag && r-l <= n/2){
          --r;
          flag = true;
        }
        ans.at(0).push_back(l);
        ans.at(1).push_back(r);
    }
  }
  
  for(int i = 0; i < m; i++){
    cout << ans.at(0).at(i) << " " << ans.at(1).at(i) << endl;
  }
}