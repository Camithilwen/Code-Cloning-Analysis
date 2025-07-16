#include <bits/stdc++.h>

#define int long long
#define ci(m)     for(int i=0;i<m;i++)
#define cj(m)     for(int j=0;j<m;j++)
#define ck(m)     for(int k=0;k<m;k++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;
int n,m;
int ans=INT_MAX;
int a[500][500];
void solve(int num,set<int>&s)
{
    if(num==m)
    {
        return ;
    }
    vector<int>v(m+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s.count(a[i][j]))
                continue;
            else
            {
                v[a[i][j]]++;
                break;
            }
        }
    }
    int val=maxe(v.begin(),v.end());
    ans=min(ans,val);
    for(int i=1;i<=m;i++)
    {
        if(v[i]==val)
        {
            s.insert(i);
            solve(num+1,s);
            return;
        }
    }
}
int32_t main() {
    nitin;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    set<int>s;
    solve(0,s);
    cout<<ans<<endl;
    return 0;
}