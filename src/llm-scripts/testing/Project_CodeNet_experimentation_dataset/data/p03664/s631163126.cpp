#include <bits/stdc++.h>
#define mov(x) (1<<(x))

using namespace std;

template <typename T> void cmin(T &x, const T &y)
{
	if(y < x) x = y;
}

template <typename T> void cmax(T &x, const T &y)
{
	if(y > x) x = y;
}

template <typename T> void read(T &x)
{
	x = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c) && c!='-') c = getchar();
	if(c == '-') f = 1, c = getchar();
	while(isdigit(c)) x = x*10+c-'0', c = getchar();
	if(f) x = -x;
}

int n, m, sum;
int grp[mov(15)];
int w[15][15];
int f[mov(15)][15];

int main()
{
	read(n), read(m);
	memset(w, 0x9f, sizeof(w));
	for(int i=1; i<=m; i++)
	{
		int a, b, c;
		read(a), read(b), read(c);
		w[a-1][b-1] = c;
		w[b-1][a-1] = c;
		sum += c;
	}
	memset(f, 0x9f, sizeof(f));
	for(int s=1; s<mov(n); s++)
		for(int i=0; i<n; i++)
			if(s & mov(i))
				for(int j=i+1; j<n; j++)
					if(s & mov(j))
						if(w[i][j] > 0)
							grp[s] += w[i][j];
	for(int s=1; s<mov(n); s++)
		if(s & 1)
			f[s][0] = grp[s];
	for(int s=1; s<mov(n); s++)
		for(int i=0; i<n; i++)
			if((mov(i)&s) && (s&1))
			{
				int u = ((~s)&(mov(n)-1));
				for(int t=u; t; t=((t-1)&u))
					for(int j=0; j<n; j++)
						if(mov(j) & t)
							if(w[i][j] > 0)
								cmax(f[s|t][j], f[s][i] + w[i][j] + grp[t]);
			}
	printf("%d\n", sum-f[mov(n)-1][n-1]);
	return 0;
}
