//-- In The Name of God --
#include<bits/stdc++.h>
using namespace std;


#define      mod     1e9+7
#define      pai     acos(-1)
#define      ff      first
#define      ss      second
#define      ll      long long
#define      pb      push_back
#define      mp      make_pair
#define      endl    "\n"
#define      fii     freopen("input.txt","r",stdin);
#define      foo     freopen("output.txt","w",stdout);
#define      fast    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

const   ll   mx=1e5+100;
ll arr[600][600];
map<pair<ll,ll>,bool>visit;
int main()
{
    fast;
    ll i,j,a,b,c,d,n,m,t;
    cin>>n>>m;
    memset(arr,-1,sizeof(arr));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>arr[i][j];
        }
    }
    vector<pair<pair<ll,ll>,pair<ll,ll> > >vec;
    ll flag=1;
    for(i=1;i<=n;i++)
    {
        if(flag==1)
        {
            for(j=1;j<m;j++)
            {
                if(arr[i][j]&1)
                {
                    if(arr[i][j+1]!=-1)
                    {
                        arr[i][j+1]+=1;
                        vec.pb(mp(mp(i,j),mp(i,j+1)));
                    }
                }
            }
            if(arr[i+1][m]!=-1 && arr[i][m]&1)
            {
                arr[i+1][m]+=1;
                vec.pb(mp(mp(i,j),mp(i+1,j)));
            }
            flag=2;
        }
        else if(flag==2)
        {
            for(j=m;j>1;j--)
            {
                if(arr[i][j]&1)
                {
                    arr[i][j-1]+=1;
                    vec.pb(mp(mp(i,j),mp(i,j-1)));
                }
            }
            if(arr[i+1][1]!=-1 && arr[i][1]&1)
            {
                arr[i+1][1]+=1;
                vec.pb(mp(mp(i,j),mp(i+1,j)));
            }
            flag=1;
        }
    }

    ll cnt=vec.size();
    cout<<cnt<<endl;
    for(auto it:vec)
    {
        a=it.first.first;
        b=it.first.second;
        c=it.second.first;
        d=it.second.second;
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
    return 0;

}

