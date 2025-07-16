#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int n, h, w;
  cin >> n >> h >> w;
  cout << max(n - h + 1, 1) * max(n - w + 1, 1) << endl;
  return 0;
}