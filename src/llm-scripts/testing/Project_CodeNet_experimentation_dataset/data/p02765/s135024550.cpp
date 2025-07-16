#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int n, r;
  cin >> n >> r;
  if(n < 10) cout << r+100*(10-n) << endl;
  else cout << r << endl;
  return 0;
}