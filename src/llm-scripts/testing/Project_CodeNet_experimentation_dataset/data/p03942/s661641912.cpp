#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1000000 + 1000;

int n;
char s[MAXN], t[MAXN];

void no()
{
	cout << -1 << endl;
	exit(0);
}

vector<int> sp, ri;

void init()
{
	int p = n;
	for(int i = n; i >= 1; i--)
		if(i == n || t[i] != t[i + 1] || i == p)
		{
			ri.push_back(i);
			while(p >= 1 && s[p] != t[i])
				p--;
			if(p <= 0) no();
			sp.push_back(p);
			p = p - 1;
			// cout << i << ' ' << p << endl;
		}
	reverse(sp.begin(), sp.end());
	reverse(ri.begin(), ri.end());
	sp.push_back(n + 1), ri.push_back(n + 1);
	// for(int i = 0; i < sp.size(); i++)
	// 	cout << sp[i] << ' ' << ri[i] << endl;	
}

void solve()
{
	if(strcmp(s + 1, t + 1) == 0)
	{
		cout << 0 << endl;
		exit(0);
	}
	int ans = 0;
	int pos = 0, cnt = 0;
	for(int i = 0; i < sp.size() - 1; i++)
	{
		if(cnt > 0) cnt--;
		while(i + cnt < sp.size() && sp[i + cnt] - cnt < ri[i])
			cnt++;
		ans = max(ans, cnt);
		// cout << cnt << endl;
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("game.in", "r", stdin);
	// freopen("game.out", "w", stdout);

	cin >> n;
	cin >> (s + 1);
	cin >> (t + 1);

	init();
	solve();

	return 0;
}
/*
12
abxxcdefghij
aabbbbccdeee
*/
/*
8
bbaabbxx
bbbbbbba
*/
/*
10
cydjgcbckr
cccdggggcc
*/
/*
10
aaaaaaaa
aaaaaaaa
*/
