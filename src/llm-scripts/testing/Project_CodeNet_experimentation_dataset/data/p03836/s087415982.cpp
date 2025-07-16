#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define pll pair<lli,lli>
#define vi  vector<int>
#define vii vector<pair<int,int>>
#define vll vector<lli>
#define pb  push_back
#define mpr  make_pair
#define ff  first
#define ss  second
#define mod 1000000007
#define pie 3.14159265358979323846264338327950L
#define all(x) x.begin(),x.end()
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define testcase() int t;cin>>t;while(t--)
#define clean(x) memset(x,0,sizeof(x))
#define FOR(x,y) for(int i=x;i<=y;i++)
const lli maxn = 2e5+9;
vector<lli> catlan(int n) {
    vector<lli> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i ++) {
        for (int j = 0; j < i; ++ j) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp;
}
lli b_ex(lli n,lli a){lli res=1;while(n){if(n%2==1)res*=a;n>>=1;a=a*a;}return res;}
lli ncr(lli n,lli k){lli ans=1;if(k>n-k)k=n-k;for(lli i=1;i<=k;i++){ans*=(n-i+1),ans=ans/i;}return ans;}
lli power(lli a , lli n){lli ans = 1;while(n){if(n % 2)ans = (ans * a) % mod;n /= 2;a = (a * a) % mod;}return ans;}
lli lcm(lli a,lli b){lli ans=(a*b)/(__gcd(a,b));return ans;}
lli set_bits(lli n)
{
    int c=0;
    if(n==0)return 0;
    while(n)
    {
        if((n&1)==1)
        {
           cout<<c<<" ";
        }
        c++;
        n=n>>1;
    }
    return c;
}

string X="IF THE CONSTRAINTS ARE LOW JUST BRUTE FORCE IT!!!!!!!!!!!!!!!!!!!!!";
///------------------ALWAYS lli-----TEMP TSF99--------------------------------------------------------------------------------------///


void solve()
{
    string z="";
    int a,b,c,d;cin>>a>>b>>c>>d;
    /// 1st traversal
    int dx=c-a,dy=d-b;
    cout<<string(dy,'U') <<string(dx,'R');
    cout<<string(dy,'D')<<string (dx,'L');
    cout<<'L'<<string(dy+1,'U')<<string(dx+1,'R')<<'D';
    cout<<'R'<<string(dy+1,'D')<<string(dx+1,'L')<<'U';
    cout<<endl;


}
int main()
{
    solve();
}
