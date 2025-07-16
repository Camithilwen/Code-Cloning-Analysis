#include <iostream>
using namespace std;
int main(){
  int n,k;
  cin >> n >> k;
  int c = 1;
  int i;
  for(i=0;i<n;i++){
    if(c<=k) c*=2;
    else c+=k;
  }
  cout << c << "\n";
  return 0;
}