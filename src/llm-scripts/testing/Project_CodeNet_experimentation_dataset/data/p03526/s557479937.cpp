#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[5010];
const int INF = 1e12+10;
int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(), v.end(), [](const pair<int,int> &l, const pair<int,int> &r){
        return l.first+l.second<r.first+r.second;
    });
    for(int i=1;i<=5000;i++)
        dp[i] = INF;
    for(int i=0;i<n;i++)
    {
        for(int j=5000;j>=0;j--)
        {
            if(dp[j]<=v[i].first)
                dp[j+1] = min(dp[j+1],dp[j]+v[i].second);
        }
    }
    for(int i=5000;i>=0;i--)
    {
        if(dp[i]!=INF)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}