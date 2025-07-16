#include<bits/stdc++.h>
using namespace std;

int H,W,Ans,top,stop[2010][2010];
bool g[2010][2010];

struct Point{
	int x,y;
	Point() {}
	Point(int x,int y):x(x),y(y) {}
}P[2010];

int main()
{
#ifdef h10
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int i,j;
	char c;
	scanf("%d%d",&H,&W);
	for (i=1;i<=H;i++)
	for (j=1;j<=W;j++)
	{
		c=getchar();
		while (c!='.'&&c!='#') c=getchar();
		g[i][j]=c=='#';
	}

	Ans=max(H,W);
	for (i=1;i<=H;i++)
	for (j=W;j>=2;j--)
		g[i][j]^=g[i][j-1];

	for (j=2;j<=W;j++)
	{
		int last[2];
		last[0]=last[1]=H+1;
		for (i=H;i>=1;i--)
		{
			stop[i][j]=last[g[i][j]^1];
			last[g[i][j]]=i;
		}
	}

	for (i=1;i<H;i++)
	{
		P[top=1]=Point(i,W+1);
		for (j=W;j>=2;j--)
		{
			while (P[top].x>=stop[i][j])
			{
				Ans=max(Ans,(P[top].x-i)*(P[top-1].y-j));
				top--;
			}
			P[++top]=Point(stop[i][j],j);
		}
		while (top)
			Ans=max(Ans,(P[top].x-i)*(P[top-1].y-j)),top--;
	}
	printf("%d\n",Ans);
}
