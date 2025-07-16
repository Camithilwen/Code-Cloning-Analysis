#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  ll N; cin >> N;
  ll a, b, c, d, e; cin >> a >> b >> c >> d >> e;
  ll m = min({a,b,c,d,e});
  ll retval = (N+m-1ll)/m + 4ll;
  cout << retval << endl;


  // cout << fixed << setprecision(10);
  
  return 0;
}

