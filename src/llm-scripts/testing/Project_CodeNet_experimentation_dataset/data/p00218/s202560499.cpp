#include <bits/stdc++.h>

#define loop(v, f, l) for(int v = (f), v##_ = (l); v < v##_; ++v)

using namespace std;

typedef long long int lint;
static inline int in(){ int x; scanf("%d", &x); return (x); }
static inline lint inl(){ lint x; scanf("%lld", &x); return (x); }

int main()
{
	int point[3];
	int n;
	int ave;
	int me_ave;
	bool has100point;

	while( true )
	{
		n = in();
		if( n == 0 )break;
		for(int i = 0; i < n; i++)
		{
			ave = me_ave = 0;
			has100point = false;
			for(int j = 0; j < 3; j++)
			{
				point[j] = in();
				if( point[j] == 100 )has100point = true;
			}
			ave = (point[0] + point[1] + point[2]) / 3;
			me_ave = (point[0] + point[1]) / 2;
			if( has100point || me_ave >= 90 || ave >= 80 )
			{
				puts("A");
			}
			else if( ave >= 70 || (ave >= 50 && (point[0] >= 80 || point[1] >= 80)) )
			{
				puts("B");
			}
			else
			{
				puts("C");
			}
		}
	}
	return (0);
}