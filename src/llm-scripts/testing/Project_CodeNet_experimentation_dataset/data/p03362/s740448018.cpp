#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(){
  int n; cin >> n;
  vector<int> sosu, ans;
  int cnt = 0;
  for(int i = 2; i <= 555555; i++){
    int j;
    for(j = 0; j < sosu.size(); j++){
      if(i % sosu[j] == 0){
        break;
      }
    }
    if(j == sosu.size()){
      sosu.push_back(i);
      if(i % 5 == 1){
        ans.push_back(i);
        cnt++;
        if(cnt == n){
          break;
        }
      }
    }
  }

  rep(i, n){
    if(i == 0) cout << ans[i];
    else cout << " " << ans[i];
  }
  cout << endl;
  return 0;
}
