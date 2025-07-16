#include<bits/stdc++.h>
#define rint register int
#define rep(i,a,b) for (rint i=(a),_E=(b); i<=_E; ++i)
#define per(i,a,b) for (rint i=(a),_E=(b); i>=_E; --i)
#define REP(i,n) for (rint i=(0),_E=(n); i<_E; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N = 100005;
priority_queue<int> Q;
int n, res;
pii a[N];
ll now;

int main() {
	scanf("%d", &n);
	rep (i, 1, n) {
		scanf("%d%d", &a[i].fi, &a[i].se);
		a[i].fi += a[i].se;
	}
	sort(a + 1, a + n + 1);
	rep (i, 1, n) {
		now += a[i].se;
		Q.push(a[i].se);
		if (now > a[i].fi) {
			now -= Q.top();
			Q.pop();
		}
	}
	cout << Q.size() << endl;
	return 0;
}