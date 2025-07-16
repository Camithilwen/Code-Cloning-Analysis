#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll N;
  cin >> N;
  ll P[N];
  for(ll i=0;i<N;i++){
    cin >> P[i];
  }
  ll ans = 1;
  ll now = P[0];
  for(ll i=1;i<N;i++){
    if(P[i]<now){
      ans++;
      now = P[i];
    }
  }
  cout << ans << endl;
}
