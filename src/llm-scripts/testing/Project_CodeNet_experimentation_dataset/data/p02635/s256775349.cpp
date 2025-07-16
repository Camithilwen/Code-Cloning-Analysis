#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 300
#define X 998244353
#define Inc(x,y) ((x+=(y))>=X&&(x-=X))
using namespace std;
int n,m,a[N+5],f[N+5][N+5][N+5];char s[N+5];
int main()
{
	RI i,j,k,cnt=1;for(scanf("%s",s+1),n=strlen(s+1),i=1;i<=n;++i) s[i]^'0'?++a[cnt]:++cnt;//转化
	RI p;scanf("%d",&m),m=min(n,m),f[0][0][0]=1;//初始化
	for(i=0;i^cnt;++i) for(j=0;j<=m;++j) for(k=0;k<=m;++k) if(f[i][j][k])//枚举状态，如果状态能达到再去刷表
	{
		Inc(f[i+1][j][k],f[i][j][k]);//不操作
		for(p=m-j;p;--p) Inc(f[i+1][j+p][k+p],f[i][j][k]);//加上一个数
		for(p=min(a[i+1],k);p;--p) Inc(f[i+1][j][k-p],f[i][j][k]);//减去一个数
	}
	RI t=0;for(i=0;i<=m;++i) Inc(t,f[cnt][i][0]);return printf("%d\n",t),0;//输出答案
}
