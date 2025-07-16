#include<iostream>
#include<cstdio>
#include<cstring>

namespace ShengXianTi
{
	const int N=301000,MOD=1000000007;
	inline void inc(int a,int &b){b=(a+b)%MOD;}

	int f[N][2][3][3];
	char s[N];
	int n;

	void dp()
	{
		s[n+1]='1',f[0][1][0][0]=1;

		for(int p=0;p<=n;p++)
			for(int r=0;r<2;r++)
				for(int k=0;k<3;k++)
					for(int sta=0;sta<3;sta++)
					{
						int v=f[p][r][k][sta];
						if(s[p+1]=='?' || s[p+1]=='0')
						{
							if(k==0)inc(v,f[p+1][r][1][sta]);
							else inc(v,f[p+1][r][k^3][sta]);
						}
						if(s[p+1]=='?' || s[p+1]=='1')
						{
							if(sta==2)
								inc(v,f[p+1][r^(k!=1)][0][sta]);
							else if(sta==1)
								inc(v,f[p+1][r^(k!=1)][0][sta+(r==0 && k==0)]);
							else if(sta==0)
								inc(v,f[p+1][r^(k!=1)][0][sta+(r==1 && k==0)]);
						}
					}
	}

	void solve()
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		dp();

		int ans=0;
		inc(f[n+1][0][0][2],ans);
		inc(f[n+1][1][0][2],ans);
		printf("%d\n",ans);
	}
}

int main()
{
	ShengXianTi::solve();
	return 0;
}
