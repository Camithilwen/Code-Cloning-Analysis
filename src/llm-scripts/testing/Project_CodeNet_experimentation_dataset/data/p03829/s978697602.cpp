#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll N,A,B;
  cin >> N >> A >> B;
  ll now,next;
  cin >> now;
  
  ll ans = 0;
  for(int i = 0; i < N-1; i++){
    cin >> next;
    ans += min(abs(now - next)*A, B);
    now = next;
  }
  
  cout << ans << endl;
}

