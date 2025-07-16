#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t X, Y;
  cin >> X >> Y;
  int ans =0;
  if(X>Y){
    if(X*Y>0){
      ans += X-Y+2;
    }

    else ans += max(X, -Y)-min(X, -Y)+1;
  }
  else{
    if(X*Y>=0){
      ans += Y-X;
    }

    else ans += max(-X, Y)-min(-X, Y)+1;
  }
  
  cout << ans << endl;
}