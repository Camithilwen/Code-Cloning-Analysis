
#include<bits/stdc++.h>
using namespace std;
#include<string>
#define fo(i, n) for(ll i = 0; i < n; i++)
#define endl "\n"
#define of(i, n) for(ll i = n - 1; i >= 0; i--)
#define ll long long
#define vec vector<ll>
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define rep(i,j,n) for (ll i = j; i <= n; ++i)
#define EB emplace_back
#define mem(i,j) memset( i, j,sizeof(i))
#define ff first
#define ss second
#define ii pair<ll,ll>
#define iii pair<ll,pair<ll,ll> >
#define pb push_back
#define mp make_pair
#define all(i) i.begin(),i.end()
#define pr(a) cout<<a<<endl
#define pr
#define prv(a) for(int jkl=0; jkl<a.size();jkl++) cout<<a[jkl]<<" "; cout<<endl;
ll mod = 1e9+7;
string l,r;
ll d;
int dp[10100][2][2][101];

ll getAns(int level, int tlow, int thi, int rem)
{
    if(level>=l.length())
    {
        if(rem==0) return 1;
        else return 0;
    }
    if(dp[level][tlow][thi][rem]==-1)
    {
        int blow = 0;
        int bhigh = 9;
        if(tlow) blow =l[level] - '0';
        if(thi) bhigh = r[level]-'0';
        ll ans =0;

        for(int i=blow;i<=bhigh;i++)
        {
            int ntlow = tlow;
            int nthi = thi;
            if( i > l[level]-'0') ntlow =0 ;
            if(i<r[level]-'0') nthi =0;

            ans += getAns(level+1, ntlow,nthi,(rem + i)%d);
            ans%=mod;
        }
        dp[level][tlow][thi][rem] = ans;
    }
    return dp[level][tlow][thi][rem];

}

int main()
{
    string n;
    cin>>n;
    r = n;
    l = "1";

    while(l.length()<r.length()) l += '0';
    reverse(all(l));
    cin>>d;
    mem(dp,-1);
    //cout<<r<<" "<<l<<endl;

    cout<<getAns(0,1,1,0)<<endl;;
}






