#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<sstream>
#include<stack>
#include<string>
#include<set>
#include<vector>
using namespace std;
#define PI acos(-1.0)
#define pppp cout<<endl;
#define EPS 1e-8
#define LL long long
#define ULL unsigned long long     //1844674407370955161
#define INT_INF 0x3f3f3f3f      //1061109567
#define LL_INF 0x3f3f3f3f3f3f3f3f //4557430888798830399
// ios::sync_with_stdio(false);
// 那么cin, 就不能跟C的 scanf，sscanf, getchar, fgets之类的一起使用了。
const int dr[]= {0, 0, -1, 1, -1, -1, 1, 1};
const int dc[]= {-1, 1, 0, 0, -1, 1, -1, 1};
int read()//输入外挂
{
    int ret=0, flag=0;
    char ch;
    if((ch=getchar())=='-')
        flag=1;
    else if(ch>='0'&&ch<='9')
        ret = ch - '0';
    while((ch=getchar())>='0'&&ch<='9')
        ret=ret*10+(ch-'0');
    return flag ? -ret : ret;
}
const int maxn=100005;
LL dist[maxn];
bool vis[maxn];
int head[maxn];
int tot,n;
int fa[maxn];

struct node
{
    int from,to;
    LL w;
    int next;
} edge[maxn*4];
struct Point
{
    int id;
    int x,y;

} p[maxn];

void add(int u,int v,LL w)
{
    edge[tot].from=u;
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int Find(int x)
{
    if(x==fa[x])
        return x;
    else
        return fa[x]=Find(fa[x]);
}
bool cmp1(Point a,Point b)
{
    return a.x<b.x;
}
bool cmp2(Point a,Point b)
{
    return a.y<b.y;
}
bool cmp3(node a,node b)
{
    return a.w<b.w;
}
int main()
{
    memset(head,-1,sizeof(head));
    for(int i=1; i<=maxn; i++)
        fa[i]=i;

    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        p[i].id=i;
    }

    sort(p+1,p+n+1,cmp1);
    for(int i=2; i<=n; i++)
        add(p[i-1].id,p[i].id,p[i].x-p[i-1].x);

    sort(p+1,p+n+1,cmp2);
    for(int i=2; i<=n; i++)
        add(p[i-1].id,p[i].id,p[i].y-p[i-1].y);

    sort(edge,edge+tot,cmp3);
    int cnt=0;
    LL ans=0;
    for(int i=0; i<tot; i++)
    {
        int fu=Find(edge[i].from);
        int fv=Find(edge[i].to);
        if(fu!=fv)
        {
            fa[fu]=fv;
            cnt++;
            ans+=edge[i].w;
            if(cnt==n-1)
                break;
        }
    }
    printf("%lld\n",ans);
    return 0;

}
