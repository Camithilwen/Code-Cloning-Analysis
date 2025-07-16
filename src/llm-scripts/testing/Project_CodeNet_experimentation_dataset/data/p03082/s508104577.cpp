//----------------------------templates
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("tune=native")
    #pragma GCC target ("avx")
    //----------------------------
    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef unsigned long long ull;
    #define int ll

    #define FOR(i,j,n) for (int i=(int)(j);i<(n);i++)
    #define REP(i,n) for (int i=0;i<(int)(n);i++)
    #define REPS(i,n) for (int i=1;i<=(int)(n);i++)
    #define REPN(i,n) for (int i=(int)(n)-1;i>=0;i--)
    #define REPNS(i,n) for (int i=(int)(n);i>0;i--)

    #define I(n) scanf("%lld", &(n))
    #define LL(n) scanf("%lld", &(n))
    #define pb(n) push_back((n))
    #define mp(i,j) make_pair((i),(j))
    #define eb(i,j) emplace_back((i),(j))
    #define y0 y3487465
    #define y1 y8687969
    #define j0 j1347829
    #define j1 j234892
    #define uniq(v) v.erase( unique(v.begin(), v.end()), v.end() )

    #define all(x) (x).begin(),(x).end()
    #define sz(x) ((int)(x).size())

    typedef vector<int> vi;
    typedef pair<int,int> pi;
    typedef vector<pi> vpi;
    typedef vector<vi> vvi;
    typedef vector<vpi> vvpi;
    typedef vector<vvi> vvvi;

    const int mod = 1000000007;

//--------------------------------------------

int n,x;
vi s,prim;
int ret;
int facto[201];

ll powll(ll base,ll power){
    ll ans = 1;
    while (power){
        if (power&1) ans = (base*ans)%mod;
        base = (base*base)%mod;
        power >>= 1;
    }
    return ans;
}
int invs[201];

int dp[201][100010];

signed main(){
    facto[0] = 1;
    REPS(i,200) facto[i] = (facto[i-1] * i) % mod;
    REPS(i,200) invs[i] = powll(i,mod-2);

    I(n); I(x);
    s.resize(n);
    REP(i,n) I(s[i]);
    sort(all(s), greater<int>());

    dp[0][x] = 1;
    REP(i,n){
        REP(j,x+1){
            int prob = invs[n-i];
            dp[i+1][j] = (dp[i+1][j] + dp[i][j] * (1 + mod - prob)) % mod; 
            dp[i+1][j % s[i]] = (dp[i+1][j % s[i]] + dp[i][j] * prob) % mod; 
        }
    }
    int ret = 0;
    REP(j,s[n-1]) ret = ((dp[n][j] * j) + ret) % mod;
    cout << (ret * facto[n]) % mod << endl;
}