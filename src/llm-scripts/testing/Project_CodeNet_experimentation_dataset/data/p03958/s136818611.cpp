#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main() {
  int k,t;
  cin >> k >> t;
  int ma=0;
  rep(i,t){
    int u;
    cin >> u;
    ma=max(ma,u);
  }
  if(ma>(k*1)/2){
    cout << k-1-(k-ma)*2 << endl;
  }
  else cout << 0 << endl;
}
