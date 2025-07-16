#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
typedef pair<int, int> pii;
typedef vector<int> VI;
typedef vector<pii> VP;
typedef priority_queue<int> PQ;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	VP A(N);
	REP(i, N) {
		cin >> A[i].first >> A[i].second;
		A[i].second++;
	}
	SORT(A);
	int s1, s2, t1, t2;
	int ans = -1;
	s2 = A[N - 1].first;

	VI mi(N, INF), mii(N, INF);

	
	mi[N - 1] = A[N - 1].second;
	for (int i = N - 2; i >= 0; i--)mi[i] = min(A[i].second, mi[i + 1]);
	
	mii[0] = A[0].second;
	FOR(i, 1, N)mii[i] = min(mii[i - 1], A[i].second);

	REP(i, N - 1) {

		int cnt=-1;
		s1 = A[i].first;
		t2 = mi[i + 1];
		t1 = mii[i];

		chmax(cnt, max((t1 - s1), 0LL) + max((t2 - s2), 0LL));
		chmax(ans, cnt);

		if (i == 0)continue;

		t1 = A[i].second;
		t2 = min(mii[i - 1], mi[i + 1]);


		chmax(cnt, max((t1 - s1), 0LL) + max((t2 - s2), 0LL));
		
		chmax(ans, cnt);
	}

	cout << ans << endl;

	return 0;
}

