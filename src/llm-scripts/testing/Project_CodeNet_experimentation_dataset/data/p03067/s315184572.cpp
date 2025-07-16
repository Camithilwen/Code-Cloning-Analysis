#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c; cin >> a >> b >> c;
  string ans = "Yes";
  if((a-c)*(b-c)>0) ans ="No";
  cout << ans << endl;
}