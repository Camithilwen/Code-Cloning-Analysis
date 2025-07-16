#include<bits/stdc++.h>
using namespace std;
#define light ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define all(c) c.begin(),c.end()
#define PI 3.14159265358979323846
const ll MAX = 1e4+10;
const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<int> digits;
int d,n;
int dp[MAX][110][2];

ll digitdp(int pos,int sum,int flag)
{
    if(pos==n)
    {
        if(sum==0)
            return 1;
        return 0;
    }
    if(dp[pos][sum][flag]!=-1)
        return dp[pos][sum][flag];
    int limit = (flag==1)?digits[pos]:9;
    ll tot = 0;
    for(int i=0;i<=limit;i++)
    {
        if(digits[pos]==i)
            tot=(tot+digitdp(pos+1,(sum+i)%d,flag))%MOD;
        else
            tot=(tot+digitdp(pos+1,(sum+i)%d,0))%MOD;
    }
        return dp[pos][sum][flag] = tot;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int i,j,l;
    string k;
    cin >> k >> d;
    l = k.length();
    for(i=0;i<l;i++)
        digits.pb(k[i]-'0');
    n = digits.size();
    ll ans = (digitdp(0,0,1)-1+MOD)%MOD;
    cout << ans;
}