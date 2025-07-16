    #include<iostream>
    #include<cstdio>
    #include<vector>
    #include<cmath>
    #include<cstring>
    #include<fstream>
    #include<algorithm>
    using namespace std;
    typedef long long LL;
    const int INF=0x3f3f3f3f;
    const int MAXN=1e5+5;
    int tot,head[MAXN];
    LL dist[MAXN];
    bool vis[MAXN];

    struct Edge
    {
        int from,to,nxt;
        LL cost;
    }e[MAXN*2];

    void addedge(int u,int v,int w)
    {
        e[tot].from=u;
        e[tot].to=v;
        e[tot].cost=w;
        e[tot].nxt=head[u];
        head[u]=tot++;
    }

    void dfs(int u,int fa)
    {
        for(int i=head[u];i!=-1;i=e[i].nxt)
        {
            int to=e[i].to;
            if(to==fa) continue;
            dist[to]=dist[u]+e[i].cost;
            dfs(to,u);
        }
    }

    int main()
    {
        int n;
        while(scanf("%d",&n)!=EOF)
        {
            tot=0;
            memset(head,-1,sizeof(head));
            memset(dist,0,sizeof(dist));
            int u,v;
            LL w;
            for(int i=1;i<=n-1;i++)
            {
                scanf("%d%d%lld",&u,&v,&w);
                addedge(u,v,w);
                addedge(v,u,w);
            }
            int q,k;
            scanf("%d%d",&q,&k);
            dfs(k,-1);
    //        for(int i=1;i<=n;i++)
    //            cout<<dist[i]<<" ";
    //        cout<<endl;
            int x,y;
            for(int i=1;i<=q;i++)
            {
                scanf("%d%d",&x,&y);
                printf("%lld\n",dist[x]+dist[y]);
            }
        }
        return 0;
    }