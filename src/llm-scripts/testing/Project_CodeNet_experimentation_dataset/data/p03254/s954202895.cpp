#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  ll N, X;
  cin >> N >> X;
  
  vector<ll> A(N);
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  
  ll ans = 0;
  while (true){
    if (X >= A.at(ans)){
      X -= A.at(ans);
      ans++;
      if (ans == N){
        if (X > 0){
          ans--;
        }
        break;
      }
    }
    else{
      break;
    }
  }
  
  cout << ans << endl;
}