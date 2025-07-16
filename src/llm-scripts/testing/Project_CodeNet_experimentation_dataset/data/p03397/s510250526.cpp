#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int read()
{
	int out = 0, sgn = 1;
	char jp = getchar();
	while (jp != '-' && (jp < '0' || jp > '9'))
		jp = getchar();
	if (jp == '-')
		sgn = -1, jp = getchar();
	while (jp >= '0' && jp <= '9')
		out = out * 10 + jp - '0', jp = getchar();
	return out * sgn;
}
const int P = 1e9 + 7;
int add(int a, int b)
{
	return a + b >= P ? a + b - P : a + b;
}
void inc(int &a, int b)
{
	a = add(a, b);
}
const int N = 3e5 + 10;
char s[N];
int trans[9][2] = {{1, 2}, {3, 0}, {4, 5}, {1, 1}, {6, 2}, {7, 5}, {4, 4}, {8, 5}, {7, 7}};
int n, dp[N][9];
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 9; ++j) if (dp[i][j])
		{
			if (s[i + 1] != '0')
				inc(dp[i + 1][trans[j][1]], dp[i][j]);
			if (s[i + 1] != '1')
				inc(dp[i + 1][trans[j][0]], dp[i][j]);
		}	
	int ans = 0;
	for (int j : {2, 5, 7, 8})
		inc(ans, dp[n][j]);
	printf("%d\n", ans);
	return 0;
}
