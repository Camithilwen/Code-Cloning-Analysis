#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 305;

int n,k,ans;
int f[2][MAXN][MAXN];

char s[MAXN];

int main()
{
	scanf("%s",s + 1);
	n = strlen(s + 1);
	scanf("%d",&k);
	for (int i = 0;i <= k;i++)
	{
		memcpy(f[i & 1],f[~i & 1],sizeof(f[i & 1]));
		for (int j = 1;j <= n;j++)
			for (int k = n;k >= j + 1;k--)
			{
				if (s[j] == s[k])
					f[i & 1][j][k] = max(f[i & 1][j][k],f[i & 1][j - 1][k + 1] + 1);
				else if (i)
					f[i & 1][j][k] = max(f[i & 1][j][k],f[~i & 1][j - 1][k + 1] + 1);
				f[i & 1][j][k] = max(f[i & 1][j][k],f[i & 1][j - 1][k]);
				f[i & 1][j][k] = max(f[i & 1][j][k],f[i & 1][j][k + 1]);
			}
	}
	for (int i = 0;i <= n;i++)
		ans = max(ans,f[k & 1][i][i + 1] * 2);
	for (int i = 1;i <= n;i++)
		ans = max(ans,f[k & 1][i - 1][i + 1] * 2 + 1);
	printf("%d\n",ans);
	return 0;
}