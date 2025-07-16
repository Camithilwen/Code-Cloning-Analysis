#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()

int main() {
  vi a(3);
  rep(i,3){
    cin >> a.at(i);
  }
  sort(ALL(a));
  int b,ans=0;
  cin >> b;
  rep(i,b){
    a.at(2)*=2;
  }
  cout << a.at(0)+a.at(1)+a.at(2);
}