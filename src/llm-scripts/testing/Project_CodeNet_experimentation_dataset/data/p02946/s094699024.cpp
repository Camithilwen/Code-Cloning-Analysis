#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int k,x;
  cin >> k >> x;
  x = x-k+1;
  rep(i,0,2*k-1){
    cout << x+i;
    if(i != 2*k-2) cout << " ";
    else cout << "" << endl;
  }
}