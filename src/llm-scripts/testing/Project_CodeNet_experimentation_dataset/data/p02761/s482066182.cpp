#include<bits/stdc++.h>
#include<string.h>
#define ll long long
#define pf printf
#define sf scanf
#define ff first
#define ss second
#define clr clear()
#define sz size()
#define pb push_back
#define mk make_pair
#define pi acos(-1)
#define inf 20000000000000000
#define mod 998244353
#define ull unsigned long long int
#define f(i,k,n) for(i=k;i<n;i++)
#define fr(i,n,k) for(i=n;i>=k;i--)
#define ent(a) scanf("%lld",&a)
#define ent2(a,b) scanf("%lld%lld",&a,&b)
#define ent3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define mem(a) memset(a,0,sizeof(a))
#define vec(v,s) vector<ll>v[s]
#define arr(a,s) ll a[s];
/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
//knight and king//
int dr[]= {2,2,-2,-2,1,-1,1,-1};
int dc[]= {1,-1,1,-1,2,2,-2,-2};
int dr1[]= {0,0,1,1,1,-1,-1,-1};
int dc1[]= {1,-1,1,0,-1,0,1,-1};
int dr2[]= {0,0,1,-1};
int dc2[]= {1,-1,0,0};
////////////////////////////
using namespace std;
#define ma 200
ll a[4][4];
ll mark[ma];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j,x,y,n,m;
    while(cin>>n)
    {
        memset(mark,-1,sizeof(mark));
        cin>>m;
        vector<pair<ll,ll> >v;
        ll max1=n;
        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            v.pb({x,y});
            mark[x]=y;
            max1=max(max1,x);
        }
        for(i=1;i<=max1;i++)
        {
            if(mark[i]==-1)
            {
                if(i==1&&max1>1)mark[i]=1;
                else mark[i]=0;
            }
        }
        bool f=0;

        for(i=0;i<v.sz;i++)
        {
            if(mark[v[i].ff]!=v[i].ss)f=1;
        }
        if(mark[1]==0&&max1>1)f=1;
        if(f)cout<<"-1"<<endl;
        else
        {
            for(i=1;i<=max1;i++)cout<<mark[i];
            cout<<endl;
        }

    }

    return 0;
}
