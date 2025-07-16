#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],b[N],c[N*3],d[N*3],n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(int i=0;i<n;i++)
		c[i]=a[i]^a[(i+1)%n],c[i+n*2]=c[i+n]=b[i]^b[(i+1)%n];
	int j;d[0]=c[n]=j=-1;
	for(int i=0;i<3*n;d[++i]=++j)
		while(j>=0&&c[i]!=c[j])
			j=d[j];
	for(int i=0;i<n;i++)
		if(d[n*3-i]==n)
			printf("%d %d\n",i,a[i]^b[0]);
	return 0;
} 
