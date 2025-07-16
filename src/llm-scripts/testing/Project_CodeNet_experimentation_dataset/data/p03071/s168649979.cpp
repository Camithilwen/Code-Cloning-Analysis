#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  if(n == m){
    cout << 2*m;
  }
  else{
    cout << 2*max(m,n)-1;
  }
}