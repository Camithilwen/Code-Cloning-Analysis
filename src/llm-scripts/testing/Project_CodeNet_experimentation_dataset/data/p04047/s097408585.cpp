//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define  all(v)            v.begin(), v.end()
#define  sz(x)             (int)x.size()
#define  debug(x)         cout << '>' << #x << ':' << x << endl;
#define  rep(i,n)         for(int i = 0; i < n; i++)
#define  reps(i,n)        for(int i = 1; i<=n ; i++)
#define  make_unique(v)   sort(all(v));v.erase(unique(all(v)), v.end());
#define  rot(v)           rotate(v.begin(), v.begin() + k, v.end());
#define  rmv(v,a)         v.erase(remove(v.begin(),v.end(), a), v.end());
#define  max(x,y)         ((x>y)?x:y)
#define  min(x,y)         ((x<y)?x:y)
#define  pb               push_back
#define  eb               emplace_back
#define  mp               make_pair
#define  endl             '\n'
#define  fi               first
#define  se               second
#define  ajs(a)           (a<0)?(-1*a):a
using namespace std;
typedef long long          ll;
// use count() instead of find() in sets.
const ll MOD = 1e9 + 7;
const double PI  = acos(-1.0);
const double EPS = (1e-10);
const int dx4[4] = {0, 1, 0, -1};
const int dy4[4] = { -1, 0, 1, 0};
const int dx8[8] = { -1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = { -1, 0, 1, 1, 1, 0, -1, -1};
bool cmp(int X, int Y) {return X > Y;}
int dcp(double A, double B){return fabs(A-B)<=EPS ? 0 : A<B ? -1:1;}


ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a / gcd(a, b)) * b;}
ll modpow(ll a, ll b, ll m ){a %= m; ll res = 1; while (b) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b >>= 1;} return res;}
ll bpow(ll a, ll b){ll res = 1; while (b) {if (b & 1)res = res * a; a = a * a; b >>= 1;} return res;}
ll modinv(ll a, ll m = MOD) {return modpow(a, m - 2, m);}




int main()
{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll n;cin>>n;
ll c = 2*n;
ll a[c];
rep(i,c){cin>>a[i];}

sort(a,a+c);
ll sum = 0;
for(ll i = 0; i < 2*n ; i = i+2){
    sum+=a[i];
}
cout<<sum;
}



