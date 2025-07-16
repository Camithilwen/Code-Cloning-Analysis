#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m, cnt, d[N << 3], v[N << 3], sum, ans;

map <int, int> mp[N << 3];

vector < pair <int, int> > e[N << 3];

queue <int> q;

void init ()
{
	scanf ( "%d%d" , &n, &m);
	cnt = n;
	for (int i = 1; i <= m; ++ i)
	{
		int p, q, c;
		scanf ( "%d%d%d" ,&p, &q, &c);
		if ( !mp[p].count (c) )
		{
			mp[p][c] = ++cnt;
			e[p].push_back ( make_pair (cnt, 1) );
			e[cnt].push_back ( make_pair (p, 1) );
		}
		if ( !mp[q].count (c) )
		{
			mp[q][c] = ++cnt;
			e[q].push_back ( make_pair (cnt, 1) );
			e[cnt].push_back ( make_pair (q, 1) );
		}
		e[ mp[p][c] ].push_back ( make_pair (mp[q][c], 0) );
		e[ mp[q][c] ].push_back ( make_pair (mp[p][c], 0) );
	}
}

void work ()
{
	memset ( d, 0x3f, sizeof (d) );
	d[1] = 0, v[1] = 1;
	q.push (1);
	for ( ; !q.empty (); )
	{
		int x = q.front ();
		q.pop ();
		for (int i = 0; i < e[x].size (); ++ i)
		{
			int y = e[x][i].first;
			if (d[y] > d[x] + e[x][i].second)
			{
				d[y] = d[x] + e[x][i].second;
				if (!v[y])
				{
					v[y] = 1;
					q.push (y);
				}
			}
		}
		v[x] = 0;
	}
	if (d[n] == 0x3f3f3f3f) sum = -1;
	else sum = d[n] / 2;
}

void prin ()
{
	printf ( "%d" , sum);
}

int main ()
{
	init ();
	work ();
	prin ();
	return 0;
}