#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;

typedef pair <int, int> pii;
const int N = 3e3 + 5;
const long long INF = 1e18;
const int mod = 998244353;//786433;//998244353;
const double Pi = acos(-1);

 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n, m;
queue <pair <int, int> > BFS;
int Dist[1005][1005];
char a[1005][1005];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			Dist[i][j] = 1000000;
			cin >> a[i][j];
			if(a[i][j] == '#')
			{
				Dist[i][j] = 0;
				BFS.push(mp(i, j));
			}
		}
	}
	while(BFS.empty() == false)
	{
		int x = BFS.front().fi, y = BFS.front().se;
		BFS.pop();
		for(int i = 0; i < 4; i++)
		{
			if(Dist[x + dx[i]][y + dy[i]] > Dist[x][y] + 1)
			{
				Dist[x + dx[i]][y + dy[i]] = Dist[x][y] + 1;
				BFS.push(mp(x + dx[i], y + dy[i]));
			}
		}
	}
	int t = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			t = max(t, Dist[i][j]);
		}
	}
	cout << t;
}