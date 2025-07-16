#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <functional>
#include <numeric>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;
int n;

const int INF = 1 << 29;

typedef pair<int,int> P;
vector<P> teams;
bool sortSecond(const P& p1, const P& p2)
{
	if(p1.second != p2.second) return p1.second < p2.second;
	if(p1.first != p2.first) return p1.first < p2.first;
	return false;
}

int main(void)
{
	while(cin >> n && n)
	{
		teams.resize(n);
		for (int i = 0; i < n; i++)
		{
			teams[i] = P(0, i);
		}
		for (int i = 0, leags = n * (n - 1) / 2; i < leags; i++)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			if(c == d)
			{
				teams[a - 1].first++;
				teams[b - 1].first++;
			}
			else if(c > d) teams[a - 1].first += 3;
			else teams[b - 1].first += 3;
		}
		sort(teams.begin(), teams.end(), greater<P>());
		int hikiwake = 0;
		for (int i = 0; i < n; i++)
		{
			int tmp = teams[i].first;
			teams[i].first = i + 1 - hikiwake;
			if(i + 1 < n && tmp == teams[i + 1].first)
			{
				hikiwake++;
			}
			else hikiwake = 0;
		}
		sort(teams.begin(), teams.end(), sortSecond);
		for (int i = 0; i < n; i++)
		{
			cout << teams[i].first << endl;
		}
	}
	return 0;
}