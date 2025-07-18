// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int mod=1e9+7;
inline void add(int&x,const int&y){x+=y;if(x>=mod)x-=mod;}

char s[300111];
int n,dp[300111][3][2][3];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);s[++n]='1';
	dp[1][0][0][0]=1;
	for(int i=1;i<=n;i++)for(int v=0;v<3;v++)for(int p=0;p<2;p++)for(int cur=0;cur<3;cur++)
	{
		if(s[i]!='1')add(dp[i+1][v==0?1:3-v][p][cur],dp[i][v][p][cur]);
		if(s[i]!='0')
		{
			if(v==1)add(dp[i+1][0][p][cur],dp[i][v][p][cur]);
			else
			{
				int nc=cur;
				if(cur==0&&v==0&&!p)nc=1;
				else if(cur==1&&v==0&&p)nc=2;
				add(dp[i+1][0][p^1][nc],dp[i][v][p][cur]);
			}
		}
	}
	printf("%d\n",(dp[n+1][0][0][2]+dp[n+1][0][1][2])%mod);
	return 0;
}