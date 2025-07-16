#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <functional>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#define MX 1000005
#define INF 1000000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct UF
{
    int par[MX],rank[MX];
    
    void init(int n)
    {
        for(int i=0;i<n;i++)
        {
            par[i]=i;
            rank[i]=0;
        }
    }
    void rem(int i)
    {
        par[i]=i;
        rank[i]=0;
    }
    int find(int x)
    {
        if(x==par[x]) return x;
        return par[x]=find(par[x]);
    }
    void unite(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x==y) return;
        if(rank[x]<rank[y])
        {
            par[x]=y;
        }
        else
        {
            par[y]=x;
            if(rank[x]==rank[y]) rank[x]++;
        }
    }
    bool same(int x,int y)
    {
        return find(x)==find(y);
    }
};
UF uf;
vector <int> vec[MX];
vector <P> query[MX];
int id[MX];
bool use[MX];
int dp[MX];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int p,q,c;
        scanf("%d %d %d",&p,&q,&c);p--,q--,c--;
        query[c].push_back(P(p,q));
    }
    int sz=n;
    for(int i=0;i<MX;i++)
    {
        if(query[i].empty()) continue;
        for(int j=0;j<query[i].size();j++)
        {
            P p=query[i][j];
            uf.rem(p.first);
            uf.rem(p.second);
            id[p.first]=id[p.second]=-1;
            use[p.first]=use[p.second]=false;
        }
        for(int j=0;j<query[i].size();j++)
        {
            P p=query[i][j];
            uf.unite(p.first,p.second);
        }
        for(int j=0;j<query[i].size();j++)
        {
            P p=query[i][j];
            if(!use[p.first])
            {
                use[p.first]=true;
                int r=uf.find(p.first);
                if(id[r]==-1) id[r]=sz++;
                //printf("%d %d: %d\n",r,id[r],p.first);
                vec[p.first].push_back(id[r]);
                vec[id[r]].push_back(p.first);
            }
            if(!use[p.second])
            {
                use[p.second]=true;
                int r=uf.find(p.second);
                if(id[r]==-1) id[r]=sz++;
                //printf("%d %d: %d\n",r,id[r],p.second);
                vec[p.second].push_back(id[r]);
                vec[id[r]].push_back(p.second);
            }
        }
    }
    queue <int> que;
    que.push(0);
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    while(!que.empty())
    {
        int v=que.front();que.pop();
        for(int i=0;i<vec[v].size();i++)
        {
            int to=vec[v][i];
            if(dp[to]==-1)
            {
                dp[to]=dp[v]+1;
                que.push(to);
            }
        }
    }
    if(dp[n-1]==-1) puts("-1");
    else printf("%d\n",dp[n-1]/2);
    return 0;
}
    