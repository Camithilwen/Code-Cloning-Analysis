#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

ll pw10[19], D, ans;
int bit[19];

void dfs(int l, int r, ll d, ll way)
{
	if(l > r)
	{
		if(d == -D) ans += way;
	}
	else
	{
		if(l == r) dfs(l+1, r-1, d, way*10);
		else
		{
			for(int i=-9; i<=9; i++)
			{
				ll base = d+i*pw10[r]-i*pw10[l];
				ll upb = base + pw10[r];
				ll lob = base - pw10[r];
				if(lob<=-D && -D<=upb) bit[l] = i, dfs(l+1, r-1, base, way*(10-abs(i)-(i<=0&&l==0)));
			}
		}
	}
}

int main()
{
	read(D);
	pw10[0] = 1;
	for(int i=1; i<=18; i++) pw10[i] = pw10[i-1] * 10;
	for(int i=1; i<=18; i++) dfs(0, i, 0, 1);
	printf("%lld\n", ans);
	return 0;
}
