#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#define debug(a) cout << "*" << a << "*" << endl
using namespace std;
typedef long long ll;
char mp[50][101];
int m, n;
void fill_mp(int num, int x, char ch)
{
	for (int i = x; ; i += 2)
	{
		for (int j = 0; j < 100; j += 2)
		{
			if (num == 0)	return;
			mp[i][j] = ch;
			num--;
		}
	}
}
int main()
{
	while (~scanf("%d%d", &m, &n))
	{
		for (int i = 0; i < 25; i++)
		{
			memset(mp[i], '#', sizeof(mp[i]));
		}
		for (int i = 25; i < 50; i++)
		{
			memset(mp[i], '.', sizeof(mp[i]));
		}
		for (int i = 0; i < 50; i++)	mp[i][100] = 0;
		m--, n--;
		fill_mp(m, 0, '.'), fill_mp(n, 26, '#');
		printf("50 100\n");
		for (int i = 0; i < 50; i++)	printf("%s\n", mp[i]);
	}
}
