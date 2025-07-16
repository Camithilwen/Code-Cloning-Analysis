#include<bits/stdc++.h>
#define FOR(i,a,b) for (register int i=(a);i<=(b);i++)
#define For(i,a,b) for (register int i=(a);i>=(b);i--)
#define mem(i,j) memset(i,j,sizeof(i))
#define GO(u) for (register int j=f[u];j!=-1;j=nxt[j])
#define fi first
#define se second
#define pii pair<int,int>
#define MP make_pair
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,a[N],ji,ou,pos,now,gcd;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return f*x;
}
inline void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
inline void yes() {if (now) printf("First\n");else printf("Second\n");exit(0);}
inline void no() {if (now) printf("Second\n");else printf("First\n");exit(0);}
inline int GCD(int x,int y)
{
	if (!y) return x;
	if (x<y) return GCD(y,x);
	return GCD(y,x%y);
}
inline void solve()
{
	ou=0,ji=0;
	FOR(i,1,n) ji+=(a[i]&1),ou+=(!(a[i]&1));
	if (!ou) no();
	if (ou&1) yes();
	if (!ji) no();
	if (ji>1) no();
	FOR(i,1,n) if (a[i]&1) {pos=i;break;}
	if (a[pos]==1) no();
	a[pos]--;
	gcd=a[1];
	FOR(i,2,n) gcd=GCD(gcd,a[i]);
	FOR(i,1,n) a[i]/=gcd;
	now^=1;
	solve();
	return;
}
int main()
{
	now=1;
	n=read();
	FOR(i,1,n) a[i]=read();
	solve();
	return 0;
}