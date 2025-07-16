#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vpii=vector<pii>;


int main(void)
{
	int h, w;
	int d_max=80*80;
	while(scanf("%d%d", &h, &w)==2)
	{
		vvi a(h), b(h), c(h);
		for(int y=0;y<h;y++)
		{
			a[y].resize(w);
			for(int x=0;x<w;x++) scanf("%d", &a[y][x]);
		}
		for(int y=0;y<h;y++)
		{
			b[y].resize(w);
			for(int x=0;x<w;x++) scanf("%d", &b[y][x]);
		}

		for(int y=0;y<h;y++)
		{
			c[y].resize(w);
			for(int x=0;x<w;x++) c[y][x]=abs(a[y][x]-b[y][x]);
		}

		vector<vector<vector<bool> > > dp(h);
		for(int y=0;y<h;y++)
		{
			dp[y].resize(w);
			for(int x=0;x<w;x++)
			{
				dp[y][x].assign(d_max+1, false);
			}
		}

		dp[0][0][c[0][0]]=true;
		for(int y=0;y<h;y++)
		{
			for(int x=0;x<w;x++)
			{
				for(int i=0;i<=d_max;i++)
				{
					if(dp[y][x][i]==false) continue;

					if(y+1<h)
					{
						int nbp=i+c[y+1][x];
						int nbn=abs(i-c[y+1][x]);
						dp[y+1][x][nbn]=true;
						if(nbp<=d_max) dp[y+1][x][nbp]=true;
					}
					if(x+1<w)
					{
						int nbp=i+c[y][x+1];
						int nbn=abs(i-c[y][x+1]);
						dp[y][x+1][nbn]=true;
						if(nbp<=d_max) dp[y][x+1][nbp]=true;
					}
				}
			}
		}
		int ans=0;
		for(ans=0;ans<=d_max && dp[h-1][w-1][ans]==false;ans++)
		{
			
		}
if(0)
{
		for(int y=0;y<h;y++)
		{
			for(int x=0;x<w;x++)
			{
				printf("%d ", c[y][x]);
			}
			printf("\n");
		}
		for(int y=0;y<h;y++)
		{
			for(int x=0;x<w;x++)
			{
				printf(" [");
				for(int i=0;i<=d_max;i++) if(dp[y][x][i]) printf(" %d", i);
				printf(" ]");
			}
			printf("\n");
		}
}
		printf("%d\n", ans);
	}
	return 0;
}
