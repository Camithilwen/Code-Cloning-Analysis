#include<bits/stdc++.h>
using namespace std;
#define ar array
#define endl '\n'
#define ll long long
#define in insert
#define pb push_back
#define vt vector
#define P_Q(x) priority_queue<x>
#define p_q(x) priority_queue<x, vector<x>, greater<x>>
#define Rep(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(ll i=a;i>=b;i--)
#define FOR(m) Rep(i,1,m)
#define For(m) Rep(i,0,m-1)
#define Rbl(x,a) for(auto &x : a)
#define FIO ios::sync_with_stdio(0);   cin.tie(0);
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define vpii vector<pii>
#define vpll vector<pll>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()
const ll INF = 0x3f3f3f3f3f3f3f3fll;
#define mod 1000000007
 
const int mxN = 2e5 + 1;
//ll a[mxN];
ll d;
string k;

void add(ll &a, ll b)
{
    a = (a + b) % mod;
}
 
int main()
{
FIO

    cin >> k >> d;
    vt<vt<ll>> dp(d, vt<ll>(2, 0));
    dp[0][0] = 1;
    int len = k.length();
    for(int i = 0; i < len; i++)
    {
        vt<vt<ll>> new_dp(d, vt<ll>(2, 0));
        for(int sum = 0; sum < d; sum++)
        {
            for(bool small : {0, 1})
            {
                for(int digit = 0; digit < 10; digit++)
                {
                    if(digit > k[i] - '0' && !small)
                        break;
                    add(new_dp[(sum + digit) % d][small || (digit < k[i] - '0')], dp[sum][small]);
                }
            }
        }
        dp = new_dp;
    }

    ll ans = mod - 1;
    add(ans, dp[0][0] + dp[0][1]);
    cout << ans << endl;

    return 0;
}