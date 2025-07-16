#include "bits/stdc++.h"

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ll long long
#define li long int
#define ld long double
#define lld long long double

#define pb push_back
#define mk make_pair
#define F first
#define S second

#define all(v) (v).begin(),(v).end()
#define fill(a) memset(a, 0, sizeof(a))

const int MX = 1e6;
const int MI = -1e6;
const int MOD = 1e9 + 7;
const string ALPHA = "abcdefghijklmnopqrstuvwxyz";
const double PI = 3.1415926535;

#define rep(i, n) for(int i=0; i<n; i++)

const int mod=1e9+7;
inline int add(int x,int y){
  x+=y;
  if (x>=mod) return x-mod;
  return x;
}
inline int sub(int x,int y){
  x-=y;
  if (x<0) return x+mod;
  return x;
}
inline int mul(int x,int y){
  return (x*1ll*y)%mod;
}
inline int power(int x,int y){
  int ans=1;
  while(y){
    if (y&1) ans=mul(ans,x);
    x=mul(x,x);
    y>>=1;
  }
  return ans;
}
inline int inv(int x){
  return power(x,mod-2);
}

int main()
{
  IOS;
  int a, b, c;
  cin >> a >> b >> c;
  cout << c << " " << a << " " << b << endl;

  return 0;
}
