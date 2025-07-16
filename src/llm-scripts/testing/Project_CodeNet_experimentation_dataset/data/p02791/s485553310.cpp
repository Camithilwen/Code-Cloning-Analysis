#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int min;
  int ans = 1;
  cin >> N >> min;

  for(int i=0;i<N-1;++i){
    int s; cin >> s;
    if(s < min){
      ans += 1;
      min = s;
    }
  }
  cout << ans << endl;
  return 0;
}
