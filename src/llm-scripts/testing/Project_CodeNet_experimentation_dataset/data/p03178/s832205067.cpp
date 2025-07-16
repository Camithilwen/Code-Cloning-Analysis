#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1e6+1;
using namespace std;
const ll mod = 1e9+7;
char _;
ll N, D, dp[10100][110][2][2]; string s;
// dp holds position, previous sum % MOD, lmt,
ll solve (ll pos,ll prevsum,  bool lmt, bool zero){
    ll ret = dp[pos][prevsum][lmt][zero];
    if (ret!= -1) return ret;
    if(pos == s.size()) return (prevsum%D==0);
    int v = s[pos] - '0', bound = lmt? v : 9; ret = 0;
    for(int i = (zero && pos == s.size()-1); i <= bound; ++i){
        ret += solve(pos+1, (prevsum+i)%D, lmt && i == v, zero && i == 0);
        ret %= mod;
    }
    return dp[pos][prevsum][lmt][zero] = ret;
}
int main()
{
    ms(dp, -1);
    cin>>s;
    cin>>D;
    cout<<solve(0,0,1,1)<<endl;
    return 0;
}
