#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vi v1(n);
  rep(i,n){
    if (i == 0){
      v1.at(i) = 0;
      continue;
    }
    v1.at(i) += v1.at(i-1) ;
    if (s.at(i-1) == 'W') v1.at(i)++;
  }
  vi v2(n);
  rep(i,n){
    if (i == 0){
      v2.at(i) = 0;
      continue;
    }
    v2.at(i) += v2.at(i-1);
    if (s.at(n-i) == 'E') v2.at(i)++;
  }
  vi v3(n);
  rep(i,n){
    v3.at(i) = v1.at(i) + v2.at(n-1-i);
  }
  sort(v3.begin(),v3.end());
  cout << v3.at(0) << endl;
  return 0;
}
