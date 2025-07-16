#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

const ll MOD = 1e9 + 7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(M);

  rep(i, N) cin >> A[i];
  rep(i, M) cin >> B[i];

  sort(A.rbegin(), A.rend());
  sort(B.rbegin(), B.rend());

  queue<int> qA, qB;

  rep(i, N) qA.push(A[i]);
  rep(i, M) qB.push(B[i]);

  int now = N * M;
  ll ans = 1;
  ll cnt_a = 0;
  ll cnt_b = 0;
  while(now > 0){

    int fa = -1;
    int fb = -1;
    if(qA.size() > 0){
      fa = qA.front();
    }
    if(qB.size() > 0){
      fb = qB.front();
    }

    if(fb == now && fa == fb){
      qA.pop();
      qB.pop();
      cnt_a++;
      cnt_b++;
      now--;
    }else if(fb == now){
      ans = (ans * cnt_a) % MOD;
      qB.pop();
      cnt_b++;
      now--;
    }else if(fa == now){
      ans = (ans * cnt_b) % MOD;
      qA.pop();
      cnt_a++;
      now--;
    }else{
      
      if(cnt_a * cnt_b - (N * M - now) <= 0){
        ans = 0;
      }else{

        ans = (ans * (cnt_a * cnt_b - (N * M - now))) % MOD;

      }
      now--;
    }
  }

  cout << ans << endl;



  return 0;
}
