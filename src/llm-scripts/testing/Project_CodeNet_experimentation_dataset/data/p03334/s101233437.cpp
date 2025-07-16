#include<cstdio>
#define N 600
int a[2][2],i,j,m,n,o,p,x,y;bool b[N][N],c[N][N];
int main()
{
	scanf("%d%d%d",&n,&o,&p),m=n<<1;
	while(~o&1)o>>=1,x++;
	while(~p&1)p>>=1,y++;
	if(x&y&1)for(i=0,x=1<<(x>>1),y=1<<(y>>1);i<m;i++)for(j=0;j<m;j++)a[b[i][j]=i&x][c[i][j]=i&y]++;
	else if(x&1)for(i=0,x=1<<(x>>1),y=1<<(y>>1);i<m;i++)for(j=0;j<m;j++)a[b[i][j]=i&x][c[i][j]=i+j&y]++;
	else if(y&1)for(i=0,x=1<<(x>>1),y=1<<(y>>1);i<m;i++)for(j=0;j<m;j++)a[b[i][j]=i+j&x][c[i][j]=i&y]++;
	else for(i=0,x=1<<(x>>1),y=1<<(y>>1);i<m;i++)for(j=0;j<m;j++)a[b[i][j]=i+j&x][c[i][j]=i+j&y]++;
	if(a[0][0]>=n*n)x=y=0;
	else if(a[0][1]>=n*n)x=0,y=1;
	else if(a[1][0]>=n*n)x=1,y=0;
	else x=y=1;
	for(i=0,n*=n;i<m&&n;i++)for(j=0;j<m&&n;j++)if(b[i][j]==x&&c[i][j]==y)n--,printf("%d %d\n",i,j);
	return 0;
}