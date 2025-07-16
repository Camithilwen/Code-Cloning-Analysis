#include<iostream>
using namespace std;

int main(){
  int a, ans;
  cin >> a;
  
  ans = a * (1 + a + a * a);
  cout << ans << endl;
  
  return 0;
}