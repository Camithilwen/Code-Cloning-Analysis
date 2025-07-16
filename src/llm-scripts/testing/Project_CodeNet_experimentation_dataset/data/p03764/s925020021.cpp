
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 #define int long long

#define all(X) (X).begin(), (X).end()
#define reset(X) memset(X, 0, sizeof(X))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define fi first
#define se second


using namespace __gnu_pbds;
using namespace std;
const int mod=1e9+7;
 // const int mod=998244353;
 // const int mod=1e9+9;
// const int INF=4e18+10;
const int INF=4e18+10;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define read(n) int n; cin>>n;
#define readv(x, n) vector<int> x(n); for(auto &i:x) cin>>i;


typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

template<typename T1,typename T2>
void set_min(T1& a, T2 b)
{
    a=min(a, (T1)b);
}


int multiply(int a, int b, int in_mod){return (a*b)%in_mod;}
int mult_identity(int a){return 1;}


auto power(auto a, int b, int in_mod)
{
    auto prod=mult_identity(a);
    auto mult=a%in_mod;
    while(b!=0)
    {
        if(b%2)
        {
            prod=multiply(prod,mult, in_mod);

        }
        mult=multiply(mult, mult,in_mod);
        b/=2;
    }
    return prod;
}
int mod_inv(int q, int in_mod)
{

    return power(q, in_mod-2,in_mod);
}



void solve()
{
    int n, m;
    cin>>n>>m;
    vector<int> x, y;
    for(int i=0;i<n;i++)
    {
        int b;
        cin>>b;
        x.pb(b);
    } 
    for(int i=0;i<m;i++)
    {
        int b;
        cin>>b;
        y.pb(b);
    } 

    sort(all(x));
    sort(all(y));

    int ans=0;
    //precomputer the vector;
    int vec=0;
    for(int i=1;i<n;i++)
    {
        vec += i*(n-i)%mod * (x[i]-x[i-1]);
        vec%=mod;
    }
    for(int i=1;i<m;i++)
    {
        ans += i*(m-i)%mod *vec%mod * (y[i]-y[i-1]); 
        ans%=mod;

    }
    cout<<ans<<endl;
}

signed main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
        freopen ("INPUT.txt" , "r" , stdin);
        freopen ("OUTPUT.txt" , "w" , stdout);
    }
    #endif
    auto clk=clock();
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // -------------------------------------Code starts here---------------------------------------------------------------------

    int t=1;
    // cin>>t;
    for(int test=1;test<=t;test++)
    {
        // cout<<"Case #"<<test<<": ";
        // cout<<endl;
        solve();
        // cout<<endl;

    }

    // -------------------------------------Code ends here------------------------------------------------------------------


    clk = clock() - clk;
    cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}
