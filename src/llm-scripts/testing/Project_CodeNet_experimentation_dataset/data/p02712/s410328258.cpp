#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  ll N; cin >> N;

  ll ans = 0;
  for(ll i = 1; i <= N; i++){
    if( i%3 == 0 || i%5 == 0){

    } else {
      ans += i;
    }
  }
  cout << ans << endl;
}
