#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100003],leaf;
int par[100003],depth[100005],sparse[100005][20],root=0,lz=0;

int lca(int p,int q)
{

    int a,b,c,d,lp,i,j;

    if(depth[p]<depth[q])
    {
        c=p; p=q; q=c;
    }

    for(j=19;j>=0;j--)
    {
         if((depth[p]-(1 << j))>=depth[q])
         {
             p=sparse[p][j];  if(depth[p]==depth[q])break;
         }
    }

    if(p==q){ return p; }
    else
    {
         for(j=19;j>=0;j--)
         {
             if(sparse[p][j]!=0 && sparse[p][j]!=sparse[q][j])
             {

                 p=sparse[p][j]; q=sparse[q][j];

                 if(par[p]==par[q])break;
             }

         }

         return par[p];
    }



}

void dfs(int src)
{
    int sz=adj[src].size();

    if(sz==1 && src!=root){   leaf.push_back(src);  lz++;   }

    for(int lp=0;lp<sz;lp++)
    {
        int u=adj[src][lp];

        if(u!=root && par[u]==0)
        {
            par[u]=src; sparse[u][0]=src; depth[u]=depth[src]+1;
            dfs(u);

        }

    }

}

int main()
{

    int n,m,a,b,i,j,u,v,ans,z,x,y,fr,sc,tr,w;
    scanf("%d %d %d",&n,&u,&v);

    for(i=1;i<=n-1;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].push_back(b); if(root==0){  if(adj[a].size()==2)root=a;  }
        adj[b].push_back(a); if(root==0){  if(adj[b].size()==2)root=b;  }

    }

    if(n==2)printf("0\n");
    else
    {
       dfs(root);

       for(j=1;j<=19;j++)
       {
           for(i=1;i<=n;i++)
           {
               if(sparse[i][j-1]!=0)
               {
                   sparse[i][j]=sparse[sparse[i][j-1]][j-1];
               }
           }
       }

       m=lca(u,v);

       ans=(depth[v]-depth[m])+(depth[u]-depth[m]); ans=ans-1;

       for(i=0;i<lz;i++)
       {
           y=leaf[i]; m=lca(u,y); w=lca(v,y);

           fr=(depth[u]-depth[m])+(depth[y]-depth[m]);
           sc=(depth[v]-depth[w])+(depth[y]-depth[w]);

           if(fr<sc)
           {
               if(sc-1>ans)ans=sc-1;
           }

       }

       printf("%d\n",ans);


    }



    return 0;
}
