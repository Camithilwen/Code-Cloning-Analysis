#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, h, w;
  cin >> n >> h >> w;
  cout << (n-h+1)*(n-w+1) << endl;  
  return 0;
}