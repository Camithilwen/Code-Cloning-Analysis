#include<cstdio>
#include<cstring>
#define N 300003
#define p 1000000007
inline int mod(int x){return x>p?x-p:x;}
char c[N];int f[8],g[8],i,j,k,n,x;const int a[8]={1,3,5,1,1,7,6,5},b[8]={2,4,6,1,2,2,6,5};
int main()
{
	scanf("%s",c+1),n=strlen(c+1),*f=1;
	for(i=1;i<=n;i++,memcpy(f,g,32),memset(g,0,32))
	{
		if(c[i]!=48)for(j=0;j<8;j++)g[b[j]]=mod(g[b[j]]+f[j]);
		if(c[i]!=49)for(j=0;j<8;j++)g[a[j]]=mod(g[a[j]]+f[j]);
	}
	return 0*printf("%d\n",mod(f[2]+f[6]));
}