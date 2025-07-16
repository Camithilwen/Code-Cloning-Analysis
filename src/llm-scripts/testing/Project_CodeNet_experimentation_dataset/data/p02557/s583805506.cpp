//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <limits>
#include <map>
#include <vector>
#include <queue>
#define LL long long
#define ft first
#define sd second
#define mp(x,y) make_pair(x,y)
//#define int LL
using namespace std;
const int N   = 3e5+233;
//const int mod = ;
const int INF =numeric_limits<int >::max();
#define For(n) for (int i=1;i<=n;++i)
#define rep(i,n) for (int i=1;i<=n;++i)
#define repp(i,x,y) for (int i=x;i<=y;++i)
void read(int &x)
{
	x=0;
	char ch=getchar();
	int f=1;
	while (!isdigit(ch)) (ch=='-'?f=-1:0),ch=getchar();
	while ( isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	x*=f;
}

void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,a[N],b[N],c[N],d[N];
signed main()
{
	read(n);
	rep(i,n)  read(a[i]),++c[a[i]];
	rep(i,n) read(b[i]),++d[b[i]];
	reverse(b+1,b+1+n);
	rep(i,n ) if (c[i]+d[i]>n) 
	{
		printf("No");
		return 0;
	}
	int l=n,r=1;
	rep(i,n) if (a[i]==b[i])  l=min(l,i),r=max(r,i);
	int pos=l;
	for (int i=1;i<l&&pos<=r;++i) if (b[i]!=a[l]&&a[i]!=a[l]) swap(b[i],b[pos]),++pos;
	for (int i=r+1;i<=n&&pos<=r;++i) if (b[i]!=a[l]&&a[i]!=a[l]) swap(b[i],b[pos]),++pos;

	printf("Yes\n");
	rep(i,n) printf("%d ",b[i]);
	return 0;
}
