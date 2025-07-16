#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000010],b[1000010],s;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d",a+i),s+=a[i]&1;
	if(s>2)return puts("Impossible"),0;
	sort(a+1,a+m+1,[](int x,int y)->bool{return (x&1)>(y&1);});
	if(m==1)if(a[1]==1)return puts("1\n1\n1"),0;else return printf("%d\n%d\n%d %d",a[1],2,a[1]-1,1),0;
	swap(a[2],a[m]);
	for(int i=1;i<=m;++i)printf("%d ",a[i]);
	printf("\n%d\n",a[m]==1?m-1:m);
	for(int i=1;i<=(a[m]==1?m-1:m);++i)printf("%d ",i==1?a[i]+1:i==m?a[i]-1:a[i]);
}