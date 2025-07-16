#include<bits/stdc++.h>
using namespace std;

int n, a[610][610];

void solve(int d)
{
	int num = 0;
	while(d % 4 == 0)
	{
		d /= 4;
		++num;
	}
	if(d % 4 == 1)
	{
		for(int i = 0; i < 2 * n; ++i)
			for(int j = 0; j < 2 * n; ++j)
				if(((i >> num) + (j >> num)) & 1) a[i][j] = 1;
	}
	else
	{
		for(int i = 0; i < 2 * n; ++i)
			for(int j = 0; j < 2 * n; ++j)
				if((i >> num) & 1) a[i][j] = 1;
	}
}

int main()
{
	int d1, d2, sum = 0, flag = 0;
	scanf("%d", &n);
	scanf("%d", &d1); solve(d1);
	scanf("%d", &d2); solve(d2);
	for(int i = 0; i < 2 * n && !flag; ++i)
		for(int j = 0; j < 2 * n && !flag; ++j)
			if(!a[i][j])
			{
				printf("%d %d\n", i, j);
				if(++sum == (n * n)) flag = 1;
			}
	return 0;
}