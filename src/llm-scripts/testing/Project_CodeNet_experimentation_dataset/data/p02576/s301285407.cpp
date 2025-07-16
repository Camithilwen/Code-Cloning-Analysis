#include <iostream>
using namespace std;

int main(void){
  int n,x,t;
  int ans;
  
  cin >> n >> x >> t;
  ans = t * ((n+x-1)/x);
  cout << ans << endl;
  
  return 0;
}