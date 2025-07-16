#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define pb push_back
typedef vector<int> vi;
#define mod 1000000007
#define nos ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int dp[3005][3005];
int n,t;
int happy(vector<pair<int,int>>&a,int pidx,int time)
{
    if(time>=t||pidx>=n)
    return 0;
    if(dp[pidx][time]!=-1)
    return dp[pidx][time];
    return dp[pidx][time]=max(a[pidx].s+happy(a,pidx+1,time+a[pidx].f),happy(a,pidx+1,time));
}
int32_t main() {
    nos;
    cin>>n>>t;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i].f>>a[i].s;
    sort(a.begin(),a.end());
    memset(dp,-1,sizeof(dp));
    cout<<max(a[0].s+happy(a,1,a[0].f),happy(a,1,0));
    return 0;
}
