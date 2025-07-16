#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ppi pair<pii,int>
#define pip pair<int,pii>
#define pdd pair<double, double>
#define f first
#define s second
#define MOD 1000000007
#define mkp make_pair
#define M_PI 3.14159265358979323846
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define LOR(i,l,r) for (ll i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define LORD(i,r,l) for (ll i=r;i>=l;i--)
#define INF 1000000000
#define CL(x) memset(x,0,sizeof(x))
#define DEB(x) cout << #x << " : " << x << '\n'
#define ALL(x) x.begin(), x.end()
#define SZ(x) x.size()
#define UI(x) (int)(x-'A')
#define LI(x) (int)(x-'a')
typedef long long ll;

#define MXN 500005
int N,A[MXN];
map<pii,ll> DP;
//for x|x specially
ll psum[MXN];
map<int,ll> lsta;
map<int,int> lstp;
//===
ll Ans;
int xb;

ll modexp(ll x, ll y)
{
    ll Pow = x%MOD, rtn = 1;
    while(y)
    {
        if(y&1)rtn=(rtn*Pow)%MOD;
        y>>=1;
        Pow=(Pow*Pow)%MOD;
    }
    return rtn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    FOR(i,1,N)
    {
        cin>>A[i];
        xb^=A[i];
    }
    int xf=0;
    Ans=1;
    FOR(i,1,N-1)
    {
        xf^=A[i];
        xb^=A[i];
        //0|0 case
        psum[i]=psum[i-1]+( xf==0 && xb==0 );

        ll za[4];
        za[1]=DP[mkp(xb?xb:xf,1)];
        za[2]=DP[mkp(xb?xb:xf,2)];
        za[3]=DP[mkp(xb,3)];

        //(even x)|x case
        if( xf==0 && xb!=0 )
        {
            Ans=(Ans+za[2])%MOD;
            DP[mkp(xb,1)]=(za[1]+za[2])%MOD;
        }
        //(odd x)|0 case
        if( xf!=0 && xb==0 )
        {
            DP[mkp(xf,2)]=(za[1]+za[2]+1)%MOD;
        }
        //(odd x)|x case
        if( xf==xb && xf )
        {
            if( lstp.find(xf)!=lstp.end() )
            {
                int lp = lstp[xf];
                ll la = lsta[xf];
                ll na = (la+za[3]*(psum[i-1]-psum[lp]))%MOD;
                Ans=(Ans+na)%MOD;

                lsta[xf]=na;
                DP[mkp(xf,3)]=(za[3]+na)%MOD;
            }
            else
            {
                DP[mkp(xf,3)]=lsta[xf]=1;
                Ans=(Ans+1)%MOD;
            }
            lstp[xf]=i;
        }
    }
    if(psum[N-1])
    {
        ll Zans=modexp(2,psum[N-1]);
        Ans=(Ans+Zans-1)%MOD;
    }
    cout<<Ans<<'\n';

    return 0;
}

/*
3
1 2 3

5
0 0 0 0 0
*/
