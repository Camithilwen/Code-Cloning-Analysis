#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, sum = 0;
  cin >> n;
  vector<int> a(n+2);
  a[0] = 0;
  a[n+2] = 0;
  rep(i, n) cin >> a[i+1];
  rep(i, n+1) sum += abs(a[i] - a[i+1]);
  rep(i, n){
    cout << sum + abs(a[i] - a[i+2]) - abs(a[i] - a[i+1]) - abs(a[i+1] - a[i+2])<< endl;
  }
}
