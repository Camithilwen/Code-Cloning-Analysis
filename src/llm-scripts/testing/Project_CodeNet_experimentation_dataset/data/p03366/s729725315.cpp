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
int n,s,w[N]; LL a[N];
LL solve (int l,int r,int t)
{
	if (w[l]> s||w[r]< s) return max (abs (s-w[l]),abs (s-w[r]));
	if (a[l]>=a[r]) return a[l]+=a[r],a[r]=0,solve (l,r-1,l)+(t==r?w[r]-w[l]:0);
	return a[r]+=a[l],a[l]=0,solve (l+1,r,r)+(t==l?w[r]-w[l]:0);
}

int main ()
{
    // freopen (".in","r",stdin);
    // freopen (".out","w",stdout);
	sc(n),sc(s);
	for (int i=1; i<=n; i++)
		sc(w[i]),sc(a[i]);
	pr(solve (1,n,a[1]>=a[n]?n:1));

    return 0;
}
