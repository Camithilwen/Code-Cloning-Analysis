#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)

int num[4][100010],c0[300010],c1[300010],n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add0(int x) { for (;x;x-=lowbit(x)) c0[x]++; }

inline void add1(int x) { for (;x;x-=lowbit(x)) c1[x]++; }

inline int sum0(int x)
{
	int res=0;
	for (;x<=n*3;x+=lowbit(x)) res+=c0[x];
	return res;
}

inline int sum1(int x)
{
	int res=0;
	for (;x<=n*3;x+=lowbit(x)) res+=c1[x];
	return res;
}

int main()
{
	n=rd();
	for (int i=1;i<=3;i++) for (int j=1;j<=n;j++) num[i][j]=rd();
	int t0=0,t1=0,tt0=0,tt1=0;
	for (int i=1;i<=n;i++)
	{
		int h1=num[1][i],h2=num[2][i],h3=num[3][i];
		if (h1<h3)
		{
			if (h2-h1!=1||h3-h2!=1) { puts("No");return 0; }
			if (h1%3!=1) { puts("No");return 0; }
			int hh=h1/3+1;
			if (abs(i-hh)&1) { puts("No");return 0; }
		}
		else
		{
			if (h2-h3!=1||h1-h2!=1) { puts("No");return 0; }
			if (h3%3!=1) { puts("No");return 0; }
			int hh=h3/3+1;
			if (abs(i-hh)&1) { puts("No");return 0; }
			if (i&1) t1^=1;
			else t0^=1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		int h1=num[1][i],h3=num[3][i];
		if (h1<h3)
		{
			if (i&1) tt0+=sum1(h1),add1(h1);
			else tt1+=sum0(h1),add0(h1);
		}
		else
		{
			if (i&1) tt0+=sum1(h3),add1(h3);
			else tt1+=sum0(h3),add0(h3);
		}
		tt0&=1;tt1&=1;
	}
	if (t0==tt0&&t1==tt1) puts("Yes");
	else puts("No");
	return 0;
}