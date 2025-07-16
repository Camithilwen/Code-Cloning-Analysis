///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

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
const int M=100005;
int h,w;
int a[505][505];
vector<pi>vec;
vector<pair<pi,pi> >ses;
vector<pi>yo;
int flag=0;
void dfs(int x,int y,int ex,int ey,int turn)
{
    if(flag)return ;
    if(x==ex && y==ey)
    {
        flag=1;
        return ;
    }
    if(y>w)
    {
        y=w;
        x++;
        turn=1-turn;
        dfs(x,y,ex,ey,turn);
        return ;
    }
    if(y<1)
    {
        y=1;
        x++;
        turn=1-turn;
        dfs(x,y,ex,ey,turn);
        return ;
    }
    yo.pb(mp(x,y));
    if(turn==0)
    {
        dfs(x,y+1,ex,ey,turn);
    }
    else if(turn==1)
    {
        dfs(x,y-1,ex,ey,turn);
    }

}
void work(pi u,pi v)
{
    int x1=u.fi;
    int y1=u.si;
    int x2=v.fi;
    int y2=v.si;
    int turn=0;
    if(x1%2==0)turn=1;
    flag=0;
    yo.clear();
    dfs(x1,y1,x2,y2,turn);
    yo.pb(mp(x2,y2));
    int sz=yo.size();
//    for(auto x:yo)
//    {
//        cout<<x.fi<<" "<<x.si<<endl;
//    }
//    cout<<"......"<<endl;
    for(int i=0;i<sz-1;i++)
    {
       ses.pb(mp(yo[i],yo[i+1]));
    }
}
 main()

{
    fast
    cin>>h>>w;
    f(i,1,h)
    {
        vector<pi>nw;
        f(j,1,w)
        {
            cin>>a[i][j];
            if(a[i][j]%2==1)nw.pb(mp(i,j));
        }
        if(i%2==0)reverse(nw.begin(),nw.end());
        for(auto x:nw)vec.pb(x);
    }
    if(vec.size()==0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    if(vec.size()%2==1)vec.pop_back();
    int sz=vec.size();
    if(sz==0)
    {
        cout<<"0"<<endl;return 0;
    }
    for(int i=0;i<sz;i=i+2)
    {
        pi x=vec[i];
        pi y=vec[i+1];
        //cout<<x.fi<<" "<<x.si<<" "<<y.fi<<" "<<y.si<<endl;
        work(x,y);
    }
   cout<<ses.size()<<"\n";
    for(auto x:ses)
    {
        pi u=x.fi;
        pi v=x.si;
        cout<<u.fi<<" "<<u.si<<" "<<v.fi<<" "<<v.si<<"\n";
    }
    return 0;

}



































