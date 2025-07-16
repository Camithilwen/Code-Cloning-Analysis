#include <bits/stdc++.h>
using namespace std;

int main() {
  long double ans=0,n,m,d;
  cin >> n >> m >> d;

  if(d==0) {
    ans=(m-1)/n;
  } else {
    ans=(n-d)*2*(m-1)/n/n;

  }
  cout << fixed << setprecision(10);
  cout << ans << endl;
}