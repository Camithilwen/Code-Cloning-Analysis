#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}


int main(){
  double d,t,s;
  cin >> d >> t >> s;
  if ((double)d / s <= t) cout << "Yes" << endl;
  else cout << "No" << endl;
}
