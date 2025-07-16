#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAXN 100000
using namespace std;
typedef long long LL;
vector<int> turns[MAXN+5];//用vector来记录每一个循环
LL k;
int n,m,tcnt=0,chs[MAXN+5],id[MAXN+5],id2[MAXN+5];
//id存的是单次操作之后的状态,id2存的是k次操作之后的操作
LL x[MAXN+5],a[MAXN+5];
LL a2[MAXN+5],x2[MAXN+5];
//a2是之后的差分序列，x2是之后的兔子位置
bool vis[MAXN+5];
int main()
{
//	freopen("rabbit.in","r",stdin);
//	freopen("rabbit.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&x[i]),id[i]=i;
	for(int i=1;i<=n;i++)
		a[i]=x[i]-x[i-1];
	scanf("%d %lld",&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d",&chs[i]),swap(id[chs[i]],id[chs[i]+1]);
	for(int i=1;i<=n;i++)
	{
		int p=i;
		if(vis[p]==true)
			continue;
		tcnt++;
		while(vis[p]==false)
		{
			vis[p]=true;
			turns[tcnt].push_back(p);
			p=id[p];
		}
	}
	for(int i=1;i<=tcnt;i++)
	{
		int T=(int)turns[i].size();//对于每一个循环单独计算
		int pos=k%T;
		//处理出开头位置所对应的最终位置，然后向后挪到来求出这个循环里的其他元素所对应的答案
		for(int j=0,p=pos;j<(int)turns[i].size();j++,p=(p+1)%T)
			id2[turns[i][j]]=turns[i][p];
	}
	for(int i=1;i<=n;i++)
		a2[i]=a[id2[i]];
	for(int i=1;i<=n;i++)
		x2[i]=x2[i-1]+a2[i];
	for(int i=1;i<=n;i++)
		printf("%lld.0\n",x2[i]);//因为题目要求，强行加一个.0
	return 0;
}
