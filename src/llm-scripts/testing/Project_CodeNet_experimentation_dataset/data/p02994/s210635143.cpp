#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, l, m=101;
  cin >> n >> l;

  for(int i=l; i<l+n; i++)m=min(abs(i), m);
  int ans=0;
  for(int i=l; i<l+n; i++){
    if(abs(i)==m)continue;
    ans+=i;
  }

  cout << ans << endl;

  return 0;
}