#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimization("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target ("avx2,avx,fma")
#define ll long long int
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for(i=l;i<r;i++)
#define ld long double
#define ff first
#define ss second
#define pli pair<ll,int>
#define pi 3.1415926535897932384626433832
int main()
{
    io;
    int i,n;
    ll x;
    cin>>n>>x;
    vector<ll>b(n);
    vector<ll>l(n);
    vector<ll>u(n);
    vector<pli>p(n);
    vector<ll>pre(n);
    ll d=0;
    rep(i,0,n)
    {
    cin>>b[i]>>l[i]>>u[i];
    d-=l[i]*b[i];
    p[i]=mp(l[i]*b[i]+u[i]*(x-b[i]),i);
    }
    ll beg=0;
    ll r=n*x;
    //cout<<r;
    sort(p.begin(),p.end(),greater<pli>());
    pre[0]=p[0].ff;
    rep(i,1,n)
    pre[i]=pre[i-1]+p[i].ff;
    while(beg<=r)
    {
        //cout<<1;
        ll mid=(beg+r)/2;
        ll q=mid/x;
        ll rem=mid%x;
        ll ans;
        ll maxi=d;
        if(q==n)
            maxi=0;
        else
        rep(i,0,n)
        {
            ans=d;
            if(q!=0)
            {
            if(i<q)
                ans+=pre[q]-p[i].ff;
            else
                ans+=pre[q-1];
            }
            ans+=min(b[p[i].ss],rem)*l[p[i].ss]+max(rem-b[p[i].ss],0ll)*u[p[i].ss];
            maxi=max(ans,maxi);
        }
        if(maxi>=0)
        r=mid-1;
        else
        beg=mid+1;
    }
    cout<<beg;
    return 0;
}
