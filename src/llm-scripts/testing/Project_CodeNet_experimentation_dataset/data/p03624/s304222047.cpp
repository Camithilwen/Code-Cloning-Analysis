#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REP1(i, n) for(int i = 1; i <= (n); i++)
#define REPD(i,a,b) for (int i=(a);i<=(b);i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<si> vsi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pi;
typedef queue<int> qi;
typedef queue<pi> qpi;
typedef pair<ll, ll> pll;
typedef queue<pll> qpll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const int mod = 1000000007;
const int INF = 1001001001;
// 小数点　<< fixed << setprecision(0) <<
// sort降順　sort(ALL(),greater<int>());
// 円周率　M_PI
// 文字判定　isupper islower
// 文字変換　
// 順列　do {} while(next_permutation(ALL(X)));
// 最大値　LLONG_MAX
// a内でx以上　auto iter = lower_bound(ALL(a), x);
// a内でxより大きい　auto iter = upper_bound(ALL(a), x);
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
struct edge {
    int from; //出発点
    int to;   //到達点
    int cost; //移動コスト
};
typedef struct edge se;
typedef vector<edge> ve;
unsigned Euclidean_gcd(unsigned a, unsigned b) {
  if(a < b) return Euclidean_gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int digit_sum(int n) {
  int sum=n%10;
  while(n!=0) {
    n/=10;
    sum+=n%10;
  }
  return sum;
}

vpll PrimeFactorization(ll n) {
  vpll res;
  for (ll i=2; i*i<=n; i++) {
    if(n%i!=0) continue;
    ll ex=0;
    while(n%i==0) {
      ex++;
      n/=i;
    }
    res.push_back(pll(i,ex));
  }
  if(n!=1) res.push_back(pll(n,1));
  return res;
}

int main() {
  char s[100001];
  cin >> s;
  int n=strlen(s);
  vi check(26,0);
  REP(i,n) {
    int x=s[i]-'a';
    check[x]++;
  }
  int ans=-1;
  REP(i,26) {
    if(ans==-1&&check[i]==0) ans=i; 
  }
  if(ans!=-1) {
    char a='a'+ans;
    cout << a << endl;
  } else {
    cout << "None" << endl;
  }
  return 0;
}
