//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn = 300111;
char s[maxn];
int n;
int dp[maxn][3][3];
void upd(int &x, int v) {x=(x+v)%mod;}
int main()
{
	scanf("%s", s);
	n = strlen(s);
	dp[0][0][0] = 1;
	for (int i=0; i<n; i++)
	{
		for (int x=0; x<3; x++)
		{
			for (int y=0; y<3; y++)
			{
				int cur = dp[i][x][y];
				if (!cur) continue;
				for (int t=0; t<2; t++)
				{
					if (s[i]!='?'&&s[i]-'0'!=t) continue;
					int nx, ny;
					if (x==2) nx=2, ny=0;
					else
					{
						if (t==0) nx=x, ny=y+1==3?1:y+1;
						else
						{
							if (y==0) nx=x+1, ny=0;
							else nx=x, ny=y-1;
						}
					}
					upd(dp[i+1][nx][ny], cur); 
				}
			}
		}
	}
	int ans = 0;
	upd(ans, dp[n][2][0]);
	upd(ans, dp[n][1][0]);
	upd(ans, dp[n][0][0]);
	cout<<ans<<endl;
	return 0;
}
