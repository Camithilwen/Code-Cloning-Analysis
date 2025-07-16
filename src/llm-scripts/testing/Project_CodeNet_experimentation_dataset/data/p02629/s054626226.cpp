#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string c(ll n);
int main() {
  ll n;
  cin >> n;
  cout << c(n);
}


string c(ll n) {
  // n >= 1
  string ans = "";
  while(n) {
    n--;
    ans += (char)('a' + (n % 26));
    n/=26;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

