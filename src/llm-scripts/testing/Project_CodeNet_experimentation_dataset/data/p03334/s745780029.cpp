#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define mod 1000000007LL
#define eps 1e-13
// #define PI 3.141592653589793238L
#define INF 1000000011
#define INFLL 1000000000000000011LL
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define fo(i,a,n) for(i = (a); i < (n); i++)
#define gtl(x) getline(cin, (x))
#define flsh fflush(stdout)
#define sws ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define gcd __gcd
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)((a).size())
#define io_file freopen("D:/Coding Problems/Contest/input_file.in", "r", stdin); freopen("D:/Coding Problems/Contest/output_file.out", "w", stdout)

ll modx(ll Base, ll exponent)
{
	ll ans = 1;
	if(Base == 1)
		return Base;
	while(exponent)
	{
		if(exponent & 1)
			ans = (ans * Base)%mod;
		Base = (Base * Base)%mod;
		exponent = exponent >> 1;
	}
	return ans;
}

ll inmodx(ll num)
{
	return (modx(num, mod-2LL));
}

bool cmp(pair < pii, int > a, pair < pii, int > b)//true for a before b
{
	if(a.F.F/300 < b.F.F/300)
		return 1;
	if(a.F.F/300 > b.F.F/300)
		return 0;
	if(a.F.S < b.F.S)
		return 1;
	if(a.F.S > b.F.S)
		return 0;
	if(a.F <= b.F)
		return 1;
	return 0;
}

const int N = (6e2) + 9;
const int M = (36e4) + 9;
const int LOGN = ((int)log2(N)) + 3;
const int LOGM = ((int)log2(M)) + 3;
const int BUCK = 2*550;
const int SQRT = BUCK+9;

vector < pii > arr[2], ans[4];
int node[N][N];
pii val[M];
vi v[2][M];
int mark[2][M];
bool vis[2][M];
queue < int > q;
int n;

inline void add_edge(int bit, int a, int b, int x, int y)
{
	if(x < 0 || x >= n+n || y < 0 || y >= n+n)
		return;
	v[bit][node[a][b]].pb(node[x][y]);
	return;
}

void bfs(int cur, int bit)
{
	if(vis[bit][cur])
		return;
	while(!q.empty())
		q.pop();
	int z;
	q.push(cur);
	vis[bit][cur] = 1;
	mark[bit][cur] = 0;
	while(!q.empty())
	{
		z = q.front();
		q.pop();
		for(auto x : v[bit][z])
			if(!vis[bit][x])
			{
				vis[bit][x] = 1;
				mark[bit][x] = 1 - mark[bit][z];
				q.push(x);
			}
	}
	return;
}

void solve()
{
	int d1, d2, i, j, k, d, cnt = 0;
	cin >> n >> d1 >> d2;
	fo(i,0,n+n)
		fo(j,0,n+n)
		{
			int d = i*i + j*j;
			if(d == d1)
				arr[0].pb({i,j});
			if(d == d2)
				arr[1].pb({i,j});
		}
	fo(i,0,n+n)
		fo(j,0,n+n)
		{
			node[i][j] = cnt;
			val[cnt] = {i,j};
			cnt++;
		}
	fo(i,0,n+n)
		fo(j,0,n+n)
			fo(k,0,2)
				for(auto x : arr[k])
				{
					add_edge(k,i,j,i+x.F,j+x.S);
					add_edge(k,i,j,i+x.F,j-x.S);
					add_edge(k,i,j,i-x.F,j+x.S);
					add_edge(k,i,j,i-x.F,j-x.S);
				}
	fo(i,0,cnt)
	{
		bfs(i,0);
		bfs(i,1);
	}
	fo(i,0,cnt)
		ans[mark[0][i]*2 + mark[1][i]].pb(val[i]);
	fo(j,0,4)
		if(sz(ans[j]) >= n*n)
		{
			fo(i,0,n*n)
				cout << ans[j][i].F << " " << ans[j][i].S << '\n';
			return;
		}
	return;
}

int main()
{
	sws;
	clock_t clk;
	clk = clock();
	// io_file;
	// srand (time(NULL));

	//Code here
	int t = 1, cs;
	cout << fixed << setprecision(9);
	// cin >> t;
	fo(cs,1,t+1)
	{
		// cout << "Case #" << cs << ": ";
		solve();
	}
	// Code ends here

	clk = clock() - clk;
	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
	return 0;
}