#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi p(n);
  int mn = 100000000, cnt = 0;
  rep(i,n){
    cin >> p[i];
    if(mn > p[i]){
      mn = p[i];
      cnt++;
    }
  }
  cout << cnt << endl;
}
