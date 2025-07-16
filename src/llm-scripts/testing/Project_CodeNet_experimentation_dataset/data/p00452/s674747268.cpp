#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

// 0119 B-0563 18:00 ~ 19:00

int main() {
	int n, m;
	while(cin >> n >> m) {
		if(n == 0 && m == 0) break;

		vector<ll> v(n);
		rep(i, n) cin >> v[i];

		sort(v.begin(), v.end());

		vector<ll> p;
		rep(i, n) p.push_back(v[i]);

		rep(i, n) {
			REP(j, i, n) {
				p.push_back(v[i] + v[j]);
			}
		}

		sort(p.begin(), p.end());
		ll ans = 0;
		rep(i, p.size()) {
			int id = upper_bound(p.begin(), p.end(), m - p[i]) - p.begin();
			if(id == 0) {
				if(p[i] <= m) ans = max(ans, p[i]);
			}
			else ans = max(ans, p[i] + p[id-1]);
		}

		cout << ans << endl;
	}

	return 0;
}