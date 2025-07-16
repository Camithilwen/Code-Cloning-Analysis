#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int main(){
  int n, l;
  cin >> n >> l;

  int sum = n*(l-1) + (n*(n+1))/2;
  if((l+n-1) < 0) {
    sum -= l+n-1;
  } else if(0 < l) {
    sum -= l;
  }
  cout << sum << endl;
  return 0;
}
