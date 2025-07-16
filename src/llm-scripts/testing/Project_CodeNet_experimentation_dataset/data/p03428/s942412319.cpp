#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
#define double long double
using namespace std;
const double pi=acos(-1);
struct poLL {LL  x,y,num;}p[110],a[110];
double ans[110];
LL multi(poLL  p1,poLL  p2,poLL  p0)
{
	LL x1=p1.x-p0.x,y1=p1.y-p0.y;
	LL x2=p2.x-p0.x,y2=p2.y-p0.y;
	return x1*y2-x2*y1;
}
LL  n,top=0,sta[110];
LL  dis(poLL  a,poLL  b) {return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
bool cmp(poLL a,poLL b)
{
	LL t1=multi(b,a,p[1]);
	return t1==0?dis(p[1],a)<dis(p[1],b):t1>0;
}
void solve()
{
	for(LL  i=2;i<=n;i++)
		if((p[1].x==p[i].x)?(p[i].y<p[1].y):(p[i].x<p[1].x)) swap(p[1],p[i]);
	sort(p+2,p+n+1,cmp);
	sta[++top]=1;
	for(LL  i=2;i<=n;i++)
	{
		while(top>1&&multi(p[sta[top]],p[sta[top-1]],p[i])<0) top--;
		sta[++top]=i;
	}
}
double get(poLL  p1,poLL  p2,poLL  p0)
{
	LL x1=p1.x-p0.x,y1=p1.y-p0.y;
	LL x2=p2.x-p0.x,y2=p2.y-p0.y;
	return (double)(x1*x2+y1*y2)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2));
}
void calc()
{
	if(top==0) for(LL  i=1;i<=top;i++) ans[p[sta[i]].num]=0.5;
	else
	{
		sta[0]=sta[top];sta[top+1]=sta[1];
		for(LL  i=1;i<=top;i++)
		{
			double tmp=get(p[sta[i-1]],p[sta[i+1]],p[sta[i]]);
			double s=pi-acos(tmp);
			ans[p[sta[i]].num]=s/(pi*2);
		}
	}
}
int  main()
{
	scanf("%lld",&n);
	for(LL  i=1;i<=n;i++) scanf("%lld %lld",&p[i].x,&p[i].y),p[i].num=i;
	if(n==1) return puts("1.000000000000"),0;
	solve();calc();
	for(LL i=1;i<=n;i++) printf("%.9Lf\n",ans[i]);
}