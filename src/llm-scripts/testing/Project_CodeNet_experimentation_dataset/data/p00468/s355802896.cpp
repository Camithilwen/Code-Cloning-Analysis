#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	int n, m, f[10001] = { 0 }, s[10001] = { 0 }, ss[501] = {0}, f_, s_, cnt = 0;
	int up = 0, down = 0;
	cin >> n >> m;
	ss[1] = 3;
	while (n != 0 && m != 0)
	{
		memset(ss, 0, sizeof(ss));
		for (int i = 0; i < m; i++)
		{
			cin >> f[i] >> s[i];
			if (f[i] == 1)
			{
				ss[s[i]] = 2;
			}
		}
		for (int i = 0; i < m; i++)
		{
			if (ss[s[i]] == 2 && ss[f[i]] == 0)
				ss[f[i]] = 1;
			if (ss[f[i]] == 2 && ss[s[i]] == 0)
				ss[s[i]] = 1;
		}
		for (int i = 2; i <= n; i++) {
			if (ss[i] != 0)cnt++;
		}
		cout << cnt << endl;
		cnt = 0;
		cin >> n >> m;
	}
	return 0;
}