#include <bits/stdc++.h>
#define NO  puts("No"),exit(0)
using namespace std;

const int N=100010;
int n,a[4][N],b[N],t[N],rev[2],swp[2];

void modify(int x){for (; x<=n; t[x]^=1,x+=x&-x);}
int ask(int x){int s=0;  for (; x; s^=t[x],x-=x&-x);  return s;}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=3; i++)
		for (int j=1; j<=n; j++)
			scanf("%d",&a[i][j]);
	for (int i=1; i<=n; i++)
		{
			if (((a[1][i]-1)/3!=(a[2][i]-1)/3)||((a[1][i]-1)/3!=(a[3][i]-1)/3))  NO;
			if (a[2][i]%3!=2)  NO;
			if (a[2][i]/3%2==i%2)  NO;
			if (a[1][i]>a[3][i])  rev[i&1]^=1;
			b[i]=a[2][i]/3+1;
		}
	for (int i=n-1+(n&1); i>0; i-=2)  swp[1]^=ask(b[i]),modify(b[i]);
	memset(t,0,sizeof(t));
	for (int i=n-(n&1); i>0; i-=2)  swp[0]^=ask(b[i]),modify(b[i]);
	if ((rev[0]!=swp[1])||(rev[1]!=swp[0]))  NO;
	puts("Yes");
}

int main()
{
	work();
	return 0;
}
