#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  int n,m; cin >> n >> m;
  cout << max(n+m,max(n-m,n*m));
}