#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;

static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const ll INF = 1023456789;

#define REP(i,n)	for(int i=0;i<n;++i)
#define REPR(i,n)	for(int i=n-1;i>=0;--i)
#define FOR(i,s,n)	for(int i=s;i<n;++i)
#define FORR(i,s,n)	for(int i=n-1;i>=s;--i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define F			first
#define S			second

ll n, v[100000];
P a[100001], b[100001];

int main(int argc, char **argv) {
	cin >> n;
	REP(i, n) cin >> v[i];
	REP(i, 100001) a[i] = b[i] = P{0, i};
	REP(i, n/2) ++a[v[i*2]].F;
	REP(i, n/2) ++b[v[i*2+1]].F;
	sort(a, a+100001); reverse(a, a+100001);
	sort(b, b+100001); reverse(b, b+100001);
	if (a[0].S == b[0].S) cout << min(n - a[0].F - b[1].F, n - b[0].F - a[1].F) << endl;
	else cout << (n - a[0].F - b[0].F) << endl;
	return 0;
}
