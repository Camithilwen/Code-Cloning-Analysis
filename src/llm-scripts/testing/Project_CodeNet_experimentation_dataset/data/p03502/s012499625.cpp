#include<bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  int sum = 0; cin >> n;
  m = n;

  for(int i = 0; n > 0; ++i){
    sum += n%10;
    n /= 10;
  }
  if(m%sum==0) cout << "Yes" << endl;
  else cout << "No" << endl;
}