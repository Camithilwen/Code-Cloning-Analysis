///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=302;

inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}

int n,m;
int a[M+2][M+2];
int col_pos_in_row[M+2];
bool chk(int mx)
{
    queue<int>q;
    int cnt[m+2],vis[m+2];clr(vis);
    f(i,1,n)col_pos_in_row[i]=1;
    clr(cnt);
    for(int i=1;i<=n;i++)
    {
         cnt[a[i][1]]++;
         if(cnt[a[i][1]]>mx && vis[a[i][1]]==0)
         {
             q.push(a[i][1]);
             vis[a[i][1]]=1;
         }
    }
    while(!q.empty())
    {
        int game=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(a[i][col_pos_in_row[i]]==game)
            {
                while(1)
                {
                    col_pos_in_row[i]++;
                    if(col_pos_in_row[i]>m)return false;
                    int gm=a[i][col_pos_in_row[i]];
                    if(vis[gm]==0)
                    {
                        break;
                    }
                }
                int ngm=a[i][col_pos_in_row[i]];
                cnt[ngm]++;
                if(cnt[ngm]>mx && vis[ngm]==0)
                {
                    q.push(ngm);
                    vis[ngm]=1;
                }
            }
        }
    }
    return true;
}
 main()

{
    fast
    cin>>n>>m;
    f(i,1,n)f(j,1,m)cin>>a[i][j];
    int lo=1,hi=n;
    while(hi-lo>=2)
    {
        int mid=(lo+hi)>>1;
        if(chk(mid))hi=mid;
        else lo=mid+1;
    }
    f(i,lo,hi)
    {
        if(chk(i))
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"ERROR"<<endl;
    return 0;

}



































