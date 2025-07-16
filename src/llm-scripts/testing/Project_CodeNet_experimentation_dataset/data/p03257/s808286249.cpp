#include <algorithm>
// #include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
using namespace std;
typedef long long LL;
typedef double db;
const int oo=2139063143;
const int N=1010000;
const int P=1000000007;
const db eps=1e-7;
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
template <typename T1,typename T2>
void chkmax (T1 &A,T2 B) { A=A>=B?A:B; }
template <typename T1,typename T2>
void chkmin (T1 &A,T2 B) { A=A<=B?A:B; }
int pri[N]; bool vis[N];
void init (int n)
{
	for (int i=2; ; i++)
	{
		if (!vis[i]) pri[++pri[0]]=i;
		if (pri[0]==n) break;
		for (int j=1; j<=pri[0]; j++)
		{
			int p=pri[j],k=i*p;
			if (k> 10000) break;
			vis[k]=1;
			if (i%p==0) break;
		}
	}
}
LL lcm (LL x,LL y) { return (!x||!y)?(x+y):(x/__gcd (x,y)*y); }
int n; LL a[1010][1010];
int main ()
{
    // freopen (".in","r",stdin);
    // freopen (".out","w",stdout);
	sc(n); init (1000);
	if (n==2) return puts("4 7\n23 10"),0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) if ((i+j+1)&1)
			a[i][j]=pri[(i+j)/2]*pri[n+(i-j)/2+(n+1)/2];
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) if (!a[i][j])
			a[i][j]=lcm (lcm (a[i-1][j],a[i][j-1]),lcm (a[i+1][j],a[i][j+1]))+1;
	for (int i=1; i<=n; i++,putchar('\n'))
		for (int j=1; j<=n; j++,putchar(' '))
			print(a[i][j]);

    return 0;
}
