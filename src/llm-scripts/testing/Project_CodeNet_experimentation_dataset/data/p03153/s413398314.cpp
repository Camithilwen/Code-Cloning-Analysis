#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int n, d;
Int a[216000];
Int sums[216000];
Int difs[216000];
Int res;
int main(){
  cin >> n >> d;
  for(int i = 0;i < n;i++){
    cin >> a[i];
    sums[i] = a[i] + i * d;
    difs[i] = a[i] - i * d;
    res += 2 * a[i];
  }
  res += (n-1)*d;
  res -= a[0] + a[n-1];
  for(int i = 1;i < n;i++)difs[i] = min(difs[i], difs[i-1]);
  for(int i = n-2;i >= 0;i--)sums[i] = min(sums[i], sums[i+1]);
  for(int i = 1;i < n-1;i++){
    //    cout << difs[i] << " " << sums[i] << endl;
    Int ltmp = -a[i] + i*d + difs[i];
    Int rtmp = -a[i] - i*d + sums[i];
    //    cout << ltmp << " " << rtmp << endl;
    res += min(ltmp, rtmp);
  }

  cout << res << endl; 
  return 0;
}