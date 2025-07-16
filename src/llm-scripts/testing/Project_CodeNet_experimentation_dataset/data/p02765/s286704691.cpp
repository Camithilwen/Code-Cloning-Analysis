#include <iostream>

using namespace std;

int main() {

  int a, n;
  cin >> n >> a;
  if(n >= 10){
    cout << a;
  }else{
    cout << a + 100 * (10 - n);
  }
  return 0;
}
