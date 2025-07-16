#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll n,m; cin >> n >> m;
  if(n % m == 0){
    cout << "0";
  }
  else{
    cout << "1";
  }
}