#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define endl        "\n"
#define si(a)       scanf("%d",&a)
#define si2(a,b)    scanf("%d%d",&a,&b)
#define sl(a)       scanf("%lld",&a)
#define sl2(a,b)    scanf("%lld%lld",&a,&b)
#define pb          push_back
#define mk          make_pair
#define loop(n)     for(int i=0; i<n; i++)
#define FOR(a,b)    for(int i=a; i<=b; i++)
#define sz          size()
#define ff          first
#define ss          second
#define mem(a,val)  memset(a, val, sizeof(a))
#define md          1000000007
#define pi          acos(-1.0)

ll a[500010], bit[500010], n, m[500010], ans[500010];

pair< pair<ll,ll>, ll>p[500010];

void update(ll idx, ll val)
{
    while(idx<=n)
    {
        bit[idx]+=val;
        idx+= idx & (- idx);
    }
}

ll sum(ll idx)
{
    ll tot=0;
    while(idx>0)
    {
        tot+=bit[idx];
        idx-= idx & (- idx);
    }
    return tot;
}
int main()
{
    ll t,i,j,k,l,r,mn=0, mx=0;
    sl2(n,k);
    for( i=1; i<=n; i++)
    {
        sl(a[i]);
    }

    for(i=0; i<k; i++)
    {
        sl2(l,r);
        p[i].ff.ff=r;
        p[i].ff.ss=l;
        p[i].ss=i;
    }

    sort(p, p+k);
    /*for(i=0; i<k; i++)
    {
        cout<<p[i].ff.ss<<" "<<p[i].ff.ff<<" "<<p[i].ss<<endl;
    }*/
    memset(m, -1, sizeof(m));
    ll cnt=0;
    for( i=1; i<=n; i++)
    {
        if(m[a[i]]!=-1)
        {
            //cout<<i<<endl;
            update(m[a[i]], -1LL);
        }
        m[a[i]]=i;
        update(i, 1);

       // cout<<cnt<<" "<<p[i].ff.ff<<endl;
        while(cnt<k &&   p[cnt].ff.ff==i)
        {
            //cout<<p[i].ss<<" "<<sum(p[i].ff.ff)<<" "<<sum(p[i].ff.ss-1)<<endl;
            ans[p[cnt].ss] = sum(p[cnt].ff.ff) - sum(p[cnt].ff.ss-1);
            cnt++;
        }
    }

    for(i=0; i<k; i++)
    {
        printf("%lld\n", ans[i]);
    }

}


