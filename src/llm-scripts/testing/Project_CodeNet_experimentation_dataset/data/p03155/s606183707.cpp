#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  int h,w;
  cin >> h >> w;
  int ans=(n-h+1)*(n-w+1);
  cout << ans << endl;
  return 0;
}
