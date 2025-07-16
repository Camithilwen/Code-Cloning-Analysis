#include <algorithm>
// #include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
// #include <bitset>
const int oo=2139063143;
const int N=310;
const int P=1000000007;
using namespace std;
typedef long long LL;
typedef double db;
#define pritnf printf
//char buf[1<<22],*p1=buf,*p2=buf,obuf[1<<22],*O=obuf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template <typename T>
inline void sc (T &x)
{
    x=0; static int p; p=1; static char c; c=getchar();
    while (!isdigit(c)) { if (c=='-') p=-1; c=getchar(); }
    while ( isdigit(c)) { x=(x<<1)+(x<<3)+(c-48); c=getchar(); }
    x*=p;
}
template <typename T>
inline void print (T x)
{
	if (x< 0) putchar('-'),x=-x;
	if (x>=10) print(x/10);
	putchar(x%10+'0');
}
template <typename T>
inline void pr (T x) { print(x),putchar('\n'); }
void chkmax (int &A,int B) { A=A>=B?A:B; }
char s[N];
int f[N][N][N];
int main ()
{
	// freopen (".in","r",stdin);
	// freopen (".out","w",stdout);
	scanf ("%s",s+1);
	int n=strlen (s+1),k; sc(k);
	for (int i=1; i<=n; i++)
		f[i][i][0]=1;
	for (int len=2; len<=n; len++)
	{
		for (int l=1,r=len; r<=n; l++,r++)
		{
			for (int i=0; i<=k; i++)
			{
				f[l][r][i]=max (f[l+1][r][i],f[l][r-1][i]);
				if (s[l]==s[r]) chkmax (f[l][r][i],f[l+1][r-1][i]+2);
				if (i) chkmax (f[l][r][i],f[l+1][r-1][i-1]+2);
			}
		}
	}
	int ans=0;
	for (int i=0; i<=k; i++)
		chkmax (ans,f[1][n][i]);
	pr(ans);

	return 0;
}
