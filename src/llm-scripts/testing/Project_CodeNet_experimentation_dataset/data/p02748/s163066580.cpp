#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
int l,m,n;
cin >> l >> m >> n;
vector<int> a(l);
vector<int> b(m);
rep(i,l) cin >> a.at(i);
rep(i,m) cin >> b.at(i);
vector<vector<int>> x(n,vector<int>(3));

rep(i,n)rep(j,3) cin >> x.at(i).at(j);
int ans = 100000000000000000;
int t;
rep(i,n){
  t = a.at(x.at(i).at(0)-1)+b.at(x.at(i).at(1)-1)-x.at(i).at(2);
  ans = min(ans,t);
}
sort(a.begin(),a.end());
sort(b.begin(),b.end());
  if(a.at(0)+b.at(0) < ans) ans = a.at(0)+b.at(0);
cout << ans << endl;
}
