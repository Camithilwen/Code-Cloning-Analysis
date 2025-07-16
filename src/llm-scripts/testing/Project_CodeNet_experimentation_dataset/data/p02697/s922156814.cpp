#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) 
		if (2 * i < m + 2) printf("%d %d\n", i, m + 2 - i);
	for (int i = 1; i <= m; ++i) 
		if (2 * i < m + 1) printf("%d %d\n", m + 1 + i, 2 * m + 2 - i);
	return 0;
}
