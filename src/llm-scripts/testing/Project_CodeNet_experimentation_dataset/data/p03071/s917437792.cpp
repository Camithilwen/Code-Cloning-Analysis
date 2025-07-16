#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b;
  cin >> a >>b;
  int mx = max(a,b);
  int mn = min(a,b);
  int mx2 = max(mx-1,mn);
  cout << mx + mx2 << endl;
}

// cout << fixed << setprecision(15) <<  << endl;
