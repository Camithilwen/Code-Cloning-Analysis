#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,ans=1; cin >> A >> B;
  if(B==1) cout << 0 << endl;
  else if(A>=B) cout << 1 << endl;
  else{
    int sum = A*ans;
    while(sum < B) {
      ans++;
      sum += (A-1);
    }
    cout << ans << endl;
  }
}