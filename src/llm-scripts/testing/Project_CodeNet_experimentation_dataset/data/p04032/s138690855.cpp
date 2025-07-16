#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

int main(void){
  string s;
  cin >> s;
  
  if (s.size() == 2){
    if (s[0] == s[1])
      cout << 1 << " " << 2 << endl;
    else
      cout << -1 << " " << -1 << endl;
  }
  else {
    ll n = s.size();
    for (int i = 0; i < n-2; i++){
      if (s[i] == s[i+1] || s[i+1] == s[i+2] || s[i] == s[i+2]){
        cout << i+1 << " " << i + 3 << endl;
        return 0;
      }
    }

    cout << -1 << " " << -1 << endl;
  }

  return 0;
}
