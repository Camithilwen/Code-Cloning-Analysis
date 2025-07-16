#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

/*int main(){
  int n, m;
  cin >> n >> m;
  vi vec(n);
  vi num(n);
  rep(i,m){
    int si, ci;
    cin >> si >> ci;
    si -= 1;
    if (vec.at(si) != ci) num.at(si)++;
    vec.at(si) = ci;
  }
  if (num.at(0) != 1 ){
    cout << -1 << endl;
    return 0;
  }
  REP(i,1,n){
    if (num.at(i) > 1){
      cout << -1 << endl;
      return 0;
    }
  }
  rep(i,n){
    cout << vec.at(i);
  }
  cout << endl;
  return 0;
}*/

int main(){
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> p(m);
  rep(i,m) cin >> p.at(i).first >> p.at(i).second;
  rep(i,1000){
    vi d(1, i%10);
    int nx = i / 10;
    while (nx){
      d.push_back(nx%10);
      nx /= 10;
    }
    if ((int)d.size() != n) continue;
    reverse(d.begin(), d.end());
    bool ok = true;
    rep(i,m){
      if (d[p.at(i).first-1] != p.at(i).second) ok = false;
    }
    if (ok){
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
