#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin >> n;
  string ans;
  if(n<1200) ans = "ABC";
  else if(n<2800) ans = "ARC";
  else ans = "AGC";
  cout << ans << endl;
  return 0;
}
