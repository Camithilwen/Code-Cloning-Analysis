#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpl;
typedef vector<vll> vvll;

#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define REP1(i,n) for(int i=1;i<((int)n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define no cout<<"No"<<endl
#define NO cout<<"NO"<<endl
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll n;
    cin >> n;

    vpl r(n);
    map<pll, ll> m;
    vpl f;
    REP(i, n) {
        string s;
        cin >> s;

        ll k = s.size();
        ll p = k - 1;
        REP(i, k) {
            if (s[i] == '.')
                p = i;
        }

        ll num = 0;
        REP(i, k) {
            if (s[i] == '.')
                continue;
            num *= 10;
            num += s[i] - '0';
        }
        ll r2 = 0, r5 = 0;
        REP(i, k - p - 1) {
            if (num % 2 == 0)num /= 2;
            else r2 -= 1;

            if (num % 5 == 0)num /= 5;
            else r5 -= 1;
        }

        while (num % 2 == 0) {
            num /= 2;
            r2++;
        }
        while (num % 5 == 0) {
            num /= 5;
            r5++;
        }

        r[i].first = r2;
        r[i].second = r5;

        m[r[i]] += 1;
    }


    ll ans = 0;
    //  for(ll i=-10; i<=14; i++){
    //      for (ll j = -10; j <= 14; j++) {
    //          ll t = m[pll(i, j)];
    //          if (t == 0)
    //              continue;
    //
    //		  ll res = 0;
    //		  for (ll k = i; k <= 14; k++) {
    //              for (ll q = -10; q <= 14; q++) {
    //				  if (k + i < 0 || q + j < 0)
    //					  continue;
    //
    //
    //                  if (k == i && q < j)
    //                      continue;
    //				  if (k == i && q == j)
    //					  res += t * (t - 1) / 2;
    //				  else
    //					  res += t * m[pll(k, q)];
    //
    //
    //              }
    //          }
    //
    //		  ans += res;
    //
    //	  }
    //  }

    for (auto p1 : m) {
        ll res = 0;
        for (auto p2 : m) {
            if (p1.FI.FI + p2.FI.FI < 0 || p1.FI.SE + p2.FI.SE < 0)
                continue;
            if (p1.FI > p2.FI)
                continue;

			if (p1 == p2)
				res += p1.SE * (p1.SE - 1) / 2;
			else
				res += p1.SE * p2.SE;
        }

        ans += res;
    }

	cout << ans << endl;

}


