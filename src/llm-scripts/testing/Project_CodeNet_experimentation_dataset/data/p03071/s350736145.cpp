#include <bits/stdc++.h>
using namespace std;
int a, b, res;
int main(){
  cin >> a >> b;
  res = max(a+a-1, b+b-1);
  res = max(res, a+b);
  cout << res;
}
