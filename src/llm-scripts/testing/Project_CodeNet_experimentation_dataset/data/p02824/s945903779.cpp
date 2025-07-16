#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define LL long long
using namespace std;
int n,m,v,p,a[N+5];LL s[N+5];
I bool cmp(CI x,CI y) {return x>y;}//从大到小排序
int main()
{
	RI i;for(scanf("%d%d%d%d",&n,&m,&v,&p),i=1;i<=n;++i) scanf("%d",a+i);
	for(sort(a+1,a+n+1,cmp),i=1;i<=n;++i) s[i]=s[i-1]+a[i];//排序后求前缀和
	for(i=n;i>p;--i) if(a[i]+m>=a[p])//枚举答案，首先要使得加上m后大于等于第p个数
		if(1LL*max(v-p-(n-i),0)*m<=1LL*(a[i]+m)*(i-p)-(s[i-1]-s[p-1])) break;//用1去填平中间的坑
	return printf("%d",i),0;//输出答案（若始终没break则最后i恰好等于p）
}