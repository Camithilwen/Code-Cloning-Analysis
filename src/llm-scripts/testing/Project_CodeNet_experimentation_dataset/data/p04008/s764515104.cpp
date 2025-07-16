/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            佛祖保佑       永无BUG
*/
#include<stdio.h>
#include<algorithm>
#define re register
using namespace std;
const int maxn=1e5+5;
struct edge
{
	int to,nxt;
}e[maxn<<1];
int n,k,head[maxn],cnt;
int a[maxn],rem[maxn],ans;
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(int u)
{
	for(re int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		dfs(v);
		if(rem[v]==k-1&&u!=1) 
		{
			ans++;
			rem[v]=-1;
		}
		rem[u]=max(rem[u],rem[v]+1);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(re int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	if(a[1]!=1) ++ans;
	for(re int i=2;i<=n;++i)
		add(a[i],i);
	dfs(1);
	printf("%d",ans);
	return 0;
}