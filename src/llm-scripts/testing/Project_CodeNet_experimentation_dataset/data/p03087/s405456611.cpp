#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main() {
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> a(n);
  a[0]=0;
  rep(i,1,n){
    if(s[i-1]=='A' && s[i]=='C') {
     a[i]= a[i-1]+1;
    }
    else a[i]=a[i-1];
  }
//  rep(i,0,n) cout << a[i] << ' ';

  rep(i,0,q){
    int l,r;
    cin >> l >> r;
    l--; r--;
    cout << a[r] - a[l] << endl;
  }

  return 0;
}