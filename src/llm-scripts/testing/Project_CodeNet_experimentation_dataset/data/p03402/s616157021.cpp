#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
char ans[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n = 100;
	int a, b;
	cin >> a >> b;
	MEM(ans, '#');
	for (int i = 1; i <= n / 2; i++)
	{
		for (int j = 1; j <= 100; j++) ans[i][j] = '.';
	}
	a--, b--;
	for (int i = 1; i <= n / 2; i += 2)
	{
		for (int j = 1; j <= 100 && b > 0; j += 2, b--)
		{
			ans[i][j] = '#';
		}
	}
	for (int i = n; i >= n / 2; i -= 2)
	{
		for (int j = 1; j <= 100 && a > 0; j += 2, a--)
		{
			ans[i][j] = '.';
		}
	}
	puts("100 100");
	for (int i = 1; i <= n; i++)
	{
		ans[i][n + 1] = 0;
		puts(ans[i] + 1);
	}
	return 0;
}
