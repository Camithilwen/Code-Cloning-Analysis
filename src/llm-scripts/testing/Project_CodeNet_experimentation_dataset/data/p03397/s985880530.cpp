#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n;
ll f[300005][9];
char s[300005];
int main()
{
	scanf("%s",s+1);
	n=(int)strlen(s+1);
	f[0][1]=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]!='1')
		{
			f[i][2]+=f[i-1][1]+f[i-1][3]+f[i-1][4];
			f[i][3]+=f[i-1][2];
			f[i][6]+=f[i-1][5]+f[i-1][7];
			f[i][7]+=f[i-1][6];
			f[i][8]+=f[i-1][8];
		}
		if(s[i]!='0')
		{
			f[i][2]+=f[i-1][3];
			f[i][4]+=f[i-1][2];
			f[i][5]+=f[i-1][1]+f[i-1][4]+f[i-1][6];
			f[i][6]+=f[i-1][7];
			f[i][8]+=f[i-1][5]+f[i-1][8];
		}
		f[i][1]%=MOD;
		f[i][2]%=MOD;
		f[i][3]%=MOD;
		f[i][4]%=MOD;
		f[i][5]%=MOD;
		f[i][6]%=MOD;
		f[i][7]%=MOD;
		f[i][8]%=MOD;
	}
	printf("%lld\n",(f[n][5]+f[n][8])%MOD);
	return 0;
}