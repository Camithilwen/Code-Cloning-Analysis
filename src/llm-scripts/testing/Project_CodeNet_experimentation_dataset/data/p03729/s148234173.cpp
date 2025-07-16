#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template <class T> inline bool chmax(T &a, T b) {if(a < b) {a= b;return 1;}return 0;}
template <class T> inline bool chmin(T &a, T b) {if(a > b) {a= b;return 1;}return 0;}
ll mod= 1e9 + 7;



int main(){
  string a,b,c;
  cin >> a >>b >> c;
  int an=a.size(),bn=b.size(),cn=c.size();
  if(a[an-1]==b[0] && b[bn-1]==c[0]){cout << "YES" << endl;}else{cout << "NO" <<endl;}
}