///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=405;
int h,w;
string s[M];
int vis[M][M];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int chk(int x,int y)
{
    if(x<0 || x>=h || y<0 || y>=w)return false;
    if(vis[x][y])return false;
    return true;
}
int cw=0,cb=0;
int dfs(int i,int j)
{
    vis[i][j]=1;
    if(s[i][j]=='#')cb++;
    else cw++;
    for(int k=0;k<4;k++)
    {
        int x=dx[k]+i;
        int y=dy[k]+j;
        if(!chk(x,y))continue;
        if(s[i][j]==s[x][y])continue;
        dfs(x,y);
    }
}
 main()

{
    fast
    cin>>h>>w;
    f(i,0,h-1)
    {
        cin>>s[i];
    }
    int ses=0;
    f(i,0,h-1)
    {
        f(j,0,w-1)
        {
            if(vis[i][j])continue;
            else
            {
                cb=cw=0;
                dfs(i,j);
                ses+=(cb*cw);
            }
        }
    }
    cout<<ses<<endl;
    return 0;

}



































