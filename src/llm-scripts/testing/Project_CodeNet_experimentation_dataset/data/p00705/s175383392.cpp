#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e7+1;
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
typedef long long int ll;
typedef vector<ll> vi;
typedef vector < pair<ll, ll > > vp;
typedef vector <string> vs;
typedef vector <char> vc;
typedef list <ll> lst;

ll n,m, k, ans = 0, sum = 0, cnt = 0;
string s;
char c;

/*--------------------template--------------------*/

ll a[105];

int main()
{
	while (1) {
		cin >> n >> k;
		if (n == 0 && k == 0) {
			return 0;
		} else {
			fill(a, a + 105, 0);
			ll ma = 0;
			REP(i, n)
			{
				cin >> m;
				REP(j, m)
				{
					ll b;
					cin >> b;
					a[b]++;
				}
			}
			ll p;
			REP(i, 105)
			{
				if (ma < a[i]) {
					ma = a[i];
					p = i;
				}
			}
			if (ma < k) {
				cout << 0 << endl;
			} else {
				cout << p << endl;
			}
		}
	}
}