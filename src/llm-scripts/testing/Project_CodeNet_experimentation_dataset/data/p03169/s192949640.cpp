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
 
const int mxN = 301;
double dp[mxN][mxN][mxN] = {};
double p[mxN][mxN][mxN] = {};
ll n;
 
int main()
{
FIO
 
    cin >> n;
    int c[3] = {}, num;
    For(n) cin >> num, c[--num]++;
    ll one = c[0], two = c[1], three = c[2];
    p[one][two][three] = 1;
    for(int k = n; k >= 0; k--)
    {
        for(int j = n; j >= 0; j--)
        {
            for(int i = n; i >= 0; i--)
            {
                if(i+j+k == 0 || i+j+k > n)
                    continue;
                dp[i][j][k] += p[i][j][k] * n / (i+j+k);

                if(i > 0)
                {
                    p[i-1][j][k] += p[i][j][k] * i / (i+j+k);
                    dp[i-1][j][k] += dp[i][j][k] * i / (i+j+k);
                }
                if(j > 0)
                {
                    p[i+1][j-1][k] += p[i][j][k] * j / (i+j+k);
                    dp[i+1][j-1][k] += dp[i][j][k] * j / (i+j+k);
                }
                if(k > 0)
                {
                    p[i][j+1][k-1] += p[i][j][k] * k / (i+j+k);
                    dp[i][j+1][k-1] += dp[i][j][k] * k / (i+j+k);
                }
            }
        }
    }

    cout << fixed << setprecision(10) << dp[0][0][0] << endl;
     
}