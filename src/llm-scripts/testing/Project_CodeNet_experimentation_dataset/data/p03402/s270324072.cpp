#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 510, M = 1010;

int a, b, n = 100;
char g[N][N];

int main()
{
	cin >> a >> b;
	a -- , b -- ;
	
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			g[i][j] = i <= 50 ? '#' : '.';
	
	for (int i = 1; a && i <= n / 2 - 1; i += 2)
		for (int j = 1; a && j <= n; j += 2, a -- )
			g[i][j] = '.';
	
	for (int i = n / 2 + 2; b && i <= n; i += 2)
		for (int j = 1; b && j <= n; j += 2, b -- )
			g[i][j] = '#';
	
	puts("100 100");
	for (int i = 1; i <= n; i ++ ) puts(g[i] + 1);
    return 0;
}