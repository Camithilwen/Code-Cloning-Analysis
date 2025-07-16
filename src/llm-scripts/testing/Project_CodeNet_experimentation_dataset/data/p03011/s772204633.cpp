#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  vi v(3);
  rep(i,3) cin >> v[i];
  sort(v.begin(),v.end());
  cout << v[0]+v[1] << endl;
}
