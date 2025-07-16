# define _CRT_SECURE_NO_WARNINGS 1
# define _USE_MATH_DEFINES
# include <iostream>
# include <numeric>
# include <string>
# include <bitset>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iomanip>
# include <queue>
# include <sstream>
# include <unordered_set>
# include <unordered_map>
# include <climits>
# include <complex>
# include <cmath>
# include <list>
# include <functional>
# include <string>
# include <ctime>
# include <set>
# include <forward_list>
# include <map>
# include <stack>
using namespace std;
# define INF ((int)(1<<25))
# define REP(i,n) for(int i=0;i<(int)n;i++)
# define FOR(i,n) REP(i,n)
# define FORI(i,k,n) for(int i=k;i<(int)n;i++)
# define TORAD 2.0*M_PI/360.0
# define INT(x) int x;cin>>x;
# define STR(x) string x;cin>>x;
# define ALL(x) begin(x),end(x)
# define RALL(x) (x).rbegin(),(x).rend()
# define DEBUG(x) cout<<#x<<":"<<x<<endl;
# define EPS 1e-12
#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#endif
typedef long long lint;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<lint> vl;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
//const int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
template<class T> void debug(T a) { for (auto i : a)cout << i << endl; }



int main()
{
	while (true)
	{
		int w, h;
		pii start, goal;
		int n;
		int a[200][200] = {};
		bool flag[200][200] = {};
		bool ok = false;
		cin >> w >> h;if (!w)break;
		cin >> start.first >> start.second;
		cin >> goal.first >> goal.second;
		cin >> n;

		FOR(i, n)
		{
			int c, d, x, y;
			cin >> c >> d >> x >> y;
			for (int X = x; X <= x+1+(d?0:2); X++)
			{
				for (int Y = y; Y <= y + 1 + (d ? 2 : 0); Y++)
				{
					a[X][Y] = c;
				}
			}
		}

		flag[start.first][start.second] = true;
		queue<pii> que; 
		if(a[start.first][start.second]!=0)que.push(start);

		while (!que.empty())
		{
			pii now = que.front(); que.pop();
			if (now == goal)
			{
				cout << "OK" << endl;
				ok = true;
			}

			FOR(i, 4)
			{
				pii next=now;
				next.first += dx[i]; next.second += dy[i];

				if (a[next.first][next.second] == a[now.first][now.second] && !flag[next.first][next.second])
				{
					flag[next.first][next.second] = true;
					que.push(next);
				}
			}
		}

		if (!ok)cout << "NG" << endl;
	}
}