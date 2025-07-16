#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,ans;
  cin >> n;
  ans=n/11*2;
  n=n%11;
  if(n>0) ans++;
  if(n>6) ans++;
  cout << ans << endl;
}