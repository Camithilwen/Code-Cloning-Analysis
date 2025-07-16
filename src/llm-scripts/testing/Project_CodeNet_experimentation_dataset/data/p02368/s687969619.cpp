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
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef priority_queue<int> PQ;
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

const int MAX_N=10000;
vector<VI> g1(MAX_N);
vector<VI> g2(MAX_N);
VI flag(MAX_N);
int fcnt = 0;
int gcnt = 0;
vector<bool>vis(MAX_N, false);
VI group(MAX_N);

void dfs(int v) {
	vis[v] = true;
	for (int w : g1[v]) {
		if (!vis[w])dfs(w);
	}
	flag[fcnt] = v;
	//cout << fcnt << " " << v << endl;
	fcnt++;
}

void rdfs(int v) {
	vis[v] = false;
	group[v] = gcnt;
	//cout << v << " " << gcnt << endl;
	for (int w : g2[v]) {
		if (vis[w])rdfs(w);
	}
}


signed main(){
cin.tie(0);
ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	REP(i, M) {
		int a, b;
		cin >> a >> b;
		g1[a].push_back(b);
		g2[b].push_back(a);
	}
	REP(i, N) {
		if (!vis[i])dfs(i);
	}
	//REP(i, N)cout << flag[i] << endl;

	for (int i = N - 1; i >= 0; i--) {
		if (vis[flag[i]]) {
			//cout << i << endl;
			rdfs(flag[i]);
			gcnt++;
		}
	}
	//REP(i, N)cout << group[i] << endl;

	int Q;
	cin >> Q;
	REP(i, Q) {
		int a, b;
		cin >> a >> b;
		cout << (group[a] == group[b]) << endl;
	}
	return 0;
}


