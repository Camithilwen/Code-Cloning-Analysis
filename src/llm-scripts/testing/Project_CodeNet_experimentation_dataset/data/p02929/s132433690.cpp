#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int main(){
  int n; 
  string s;
  cin >> n >> s;
  for(int i=0; i<2*n; i++){
    if((i + (s[i] == 'W')) % 2 == 0){
      s[i] = 'L';
    }
    else{
      s[i] = 'R';
    }
  }
  if(count(s.begin(), s.end(), 'L') != n) cout << 0 << endl;
  else{
    ll ans = 1;
    int left = 0;
    for(int i=0; i<2*n; i++){
      if(s[i] == 'L') left++;
      else{
        ans *= left;
        left--;
        ans %= MOD;
      }
    }
    for(int i=1; i<n+1; i++){
      ans *= i;
      ans %= MOD;
    }
    cout << ans << endl;
  }
}