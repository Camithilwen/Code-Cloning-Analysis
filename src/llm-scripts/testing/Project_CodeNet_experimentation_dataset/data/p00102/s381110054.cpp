#include <bits/stdc++.h>

#define loop(v, f, l) for(int v = (f), v##_ = (l); v < v##_; ++v)

using namespace std;

typedef long long int lint;
static inline int in(){ int x; scanf("%d", &x); return (x); }
static inline lint inl(){ lint x; scanf("%lld", &x); return (x); }

int matrix[11][11];

int main()
{
	int n;

	while( (n = in()) != 0 )
	{
		loop(i, 0, 11)
		{
			loop(j, 0, 11)
			{
				matrix[i][j] = 0;
			}
		}

		loop(i, 0, n)
		{
			loop(j, 0, n)
			{
				matrix[i][j] = in();
			}
		}
		
		loop(i, 0, n)
		{
			loop(j, 0, n)
			{
				matrix[i][n] += matrix[i][j];
				matrix[n][i] += matrix[j][i];
			}
			matrix[n][n] += matrix[i][n];
		}
		
		loop(i, 0, n + 1)
		{
			loop(j, 0, n + 1)
			{
				printf("%5d", matrix[i][j]);
			}
			printf("\n");
		}
		
	}

	return (0);
}