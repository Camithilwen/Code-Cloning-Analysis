#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n,s;
struct que
{
	int x;
	long long p;
}a[100005];
long long calc(int l,int r,int last)
{
	if(a[l].x>=s) return a[r].x-s;
	if(a[r].x<=s) return s-a[l].x;
	if(a[l].p>=a[r].p){a[l].p+=a[r].p;return calc(l,r-1,l)+((last==r)?a[r].x-a[l].x:0);}
	else {a[r].p+=a[l].p;return calc(l+1,r,r)+((last==l)?a[r].x-a[l].x:0);}
}
int main()
{
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++) scanf("%d%lld",&a[i].x,&a[i].p);
	printf("%lld\n",calc(1,n,a[1].p<a[n].p?1:n));
}