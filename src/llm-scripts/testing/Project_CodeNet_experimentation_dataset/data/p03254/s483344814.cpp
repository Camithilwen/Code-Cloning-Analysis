#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,x;
  int ans = 0;
  bool flag = false;
  
  cin >> N >> x;
  vector<int> vec(N);
  for(int i=0;i<N;++i){
    cin >> vec.at(i);
  }
  sort(vec.begin(),vec.end());
  for(int i=0;i<N-1;++i){
    if(x - vec.at(i) >= 0){
      x -= vec.at(i);
      ans += 1;
    }else{
      flag = true;
    }
    if(flag) break;
  }
  if(!flag && vec.at(N-1) == x) ans += 1;
  cout << ans << endl;
  return 0;
}
