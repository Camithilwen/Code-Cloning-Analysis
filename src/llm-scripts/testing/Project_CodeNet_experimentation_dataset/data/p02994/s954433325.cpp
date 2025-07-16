#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, l;
  cin >> n >> l;
  
  int target = 0;
  for (int i=0 ; i<n ; i++)
    target += l + i;
  
  int ans;
  vector<int> pie(n);
  for (int i=0 ; i<n ; i++){
    for (int j=0 ; j<n ; j++){
      if (i == j)
        continue;
      pie.at(i) += l + j;
    }
    if (i == 0)
      ans = pie.at(i);
    else{
      if (abs(pie.at(i)-target) < abs(ans-target))
        ans = pie.at(i);
    }
  }
  
  cout << ans << endl;
}