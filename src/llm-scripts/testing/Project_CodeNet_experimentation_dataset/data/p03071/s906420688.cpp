#include <iostream>
using namespace std;

int main()
{
  int a, b, ans = 0;
  cin >> a >> b;
  ans += max(a , b);
  if(a == b) ans += max(a, b);
  else ans += ans - 1;
  
  cout << ans << endl;
  return 0;
}