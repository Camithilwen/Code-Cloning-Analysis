#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
int n,x[105],y[105];
double ang[105];
int main()
{
 	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
	{
		int c=0;
		for(int j=1;j<=n;j++)if(i^j)ang[c++]=atan2(y[j]-y[i],x[j]-x[i]);
		sort(ang,ang+c);
		double mx=0;
		ang[c]=ang[0]+2*pi;
		for(int j=0;j<c;j++)mx=max(mx,ang[j+1]-ang[j]);
		mx-=pi;
		if(mx<0)mx=0;
		printf("%.10lf\n",mx/(2*pi));
	}
 	return 0;
}