#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2010;
bool board[maxn][maxn];
int n, m;
int len[2][maxn][maxn];
void init(bool asd)
{
	//cout << asd << " : " << endl;
	for(int i = 1; i <= m; i ++)
		len[asd][1][i] = m + 1;
	for(int i = 2; i <= n; i ++)
	{
		int p = 0;
		for(int j = 1; j <= m; j ++)
		{
			p = max(p, j);
			for(p; p <= m && board[i][p] == (board[i - 1][p] ^ asd); p ++);
			//cout << i << " " << j << " " << p << endl;
			len[asd][i][j] = p;
		}
	}
	/*
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
			cout << len[asd][i][j] << " ";
		cout << endl;
	}
	*/
}
int ans = 0;
int sta[maxn], cnt = 0;
int l[maxn];
void get(int x)
{
	//cout << x << " ---------------------- " << endl;
	cnt = 0;
	sta[++ cnt] = 1;
	l[1] = 0;
	for(int i = 2; i <= n; i ++)
	{
		l[i] = max(len[0][i][x], len[1][i][x]) - x;
		//cout << i << " " << l[i] << endl;
		while(cnt > 0 && l[sta[cnt]] > l[i])
		{
			//cout << sta[cnt] << " : " << endl;
			ans = max(ans, (i - sta[cnt - 1]) * l[sta[cnt]]);
			//cout << ans << endl;
			cnt --;
		}
		sta[++ cnt] = i;
	}
	while(cnt > 0)
	{
		ans = max(ans, (n - sta[cnt - 1] + 1) * l[sta[cnt]]);
		cnt --;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			char a;
			cin >> a;
			if(a == '#')
				board[i][j] = 1;
			else
				board[i][j] = 0;
		}
	}
	init(0);
	init(1);
	for(int a = 1; a <= m; a ++)
		get(a);
	cout << max(ans, max(n, m)) << endl;
	return 0;
}