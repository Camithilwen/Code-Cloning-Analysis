#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MAX 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define zoom ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return (b.ff + b.ss > a.ff + a.ss);
}

int main() {


    zoom;
    ll n, i, j;
    cin>>n;
    vector<pair<ll, ll> >A(n);
    for(i = 0; i < n; i += 1)
        cin>>A[i].ff>>A[i].ss;
    sort(A.begin(), A.end(), cmp);
    vector<vector<ll> > dp(n, vector<ll>());
    dp[0].pb(0);
    dp[0].pb(A[0].ss);
    for(i = 1; i < n; i += 1) {
        dp[i].pb(0);
        for(j = 1; j <= i; j += 1) {
            ll temp1 = dp[i - 1][j];
            ll temp2 = -1;
            if(dp[i - 1][j - 1] != -1 && dp[i - 1][j - 1] <= A[i].ff)
                temp2 = dp[i - 1][j - 1] + A[i].ss;            
            if((temp1 == -1 && temp2 == - 1))
                dp[i].pb(-1);
            else if(temp1 == -1)
                dp[i].pb(temp2);
            else if(temp2 == -1)
                dp[i].pb(temp1);
            else
                dp[i].pb(min(temp1, temp2));
        }
        if(dp[i - 1][j - 1] != -1 && dp[i - 1][j - 1] <= A[i].ff)
            dp[i].pb(dp[i - 1][j - 1] + A[i].ss);
        else
            dp[i].pb(-1); 
    }
    ll ans = -1;
    for(i = n - 1; i >= 0; i -= 1) {
        for(j = i + 1; j >= 1; j -= 1) {
            if(dp[i][j] != -1)
            ans = max(ans, j); 
        }
    }
    cout<<ans;
    return 0;
}