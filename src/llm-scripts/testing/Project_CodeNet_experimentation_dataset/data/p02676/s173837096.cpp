///_________________________________ B I S M I L L A H I R  R A H M A N I R  R A H I M __________________________________________________

#include<bits/stdc++.h>
using namespace std;

typedef bool                   boo;
typedef int                    li;
typedef long                   il;
typedef unsigned long          ul;
typedef long long int          ll;
typedef unsigned long long     ull;
typedef double                 dd;
typedef string                 str;

#define vli                    vector<li>
#define vll                    vector<ll>
#define sli                    set<li>
#define sll                    set<ll>
#define pli                    pair<li, li>
#define pll                    pair<ll, ll>
#define vpi                    vector<pair<li, li>>
#define vpl                    vector<pair<ll, ll>>
#define mpl                    map<ll, ll>

#define test                   ll t; cin>>t; while(t--)
#define input(a,n)             for(int i=0;i<n;i++) cin>>a[i];
#define lp(a, i, b)            for(ll i=a; i<b; i++)
#define rlp(a, i, b)           for(ll i=a; i>=b; i--)
#define sz(x)                  x.size()
#define len(z)                 z.begin(), z.end()
#define ci(x)                  cin>>x;
#define co(x)                  cout<<x nl
#define fix(x)                 fixed<<setprecision(x)
#define mem(z, l)              memset(z, l, sizeof(z))
#define MP                     make_pair
#define pb                     push_back
#define F                      first
#define S                      second
#define nl                     <<endl
#define nll                    cout<<endl
#define sp                     <<" "<<
#define sl                     <<" "
#define cy                     cout<<"YES" nl
#define cn                     cout<<"NO" nl
#define rn                     return
#define good_bye               return 0
#define gcd(a,b)               __gcd(a,b)
#define lcm(a,b)               (a*(b/gcd(a,b)))
#define faster                 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define input_txt()            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

const double eps =             1e-9;
const int inf =                2000000000;
const ll infLL =               9000000000000000000;
const ll MOD =                 1e+7;
const double PI =              3.141592653589793238462643383279;

int dx[] =                     {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] =                     {+1, -1, 0, 0, +1, -1, +1, -1};

//ll Pow(ll P, ll Q)           { ll R=1; for(ll I=1; I<=Q; I++) R*=P; rn R; }
//ll fact(ll N)                { ll M=1; for(ll I=1; I<=N; I++) M*=I; return M; }
//void dfs(ll K)               { vis[K]=true; for(auto J: v[K]) { if(!vis[J]) dfs(J); } }
//void bfs(ll s)               { queue<ll>q; q.push(s); while(!q.empty()) { ll u=q.front(); q.pop(); for(auto i : v[u]) if(lev[i]==-1) { lev[i]=lev[u]+1; q.push(i); } } }
//void sieve(ll MX)            { S.pb(2); for(ll I=3; i<=MX; i+=2) { if(!vis[I]) { S.pb(I); for(ll J=I*I; j<=MX; J+=(2*I)) vis[J]=true; } } }
//bool isPrime(ll n)           { if(n%2==0) rn false; for(ll i=3; i*i<=n; i+=2) { if(n%i==0) rn false; } rn true; }

///_____________________________________________ L E T ' S  B E G I N __________________________________________________________________________

const int mX = 1e6+123;
ll n, l, i=0;
str s;

void case_i()
{
    cin>>n>>s; l=sz(s);
    while(i<min(l, n)) { cout<<s[i]; i++; }
    if(l>n) cout<<"...";
    nll;
}

int main()
{
    //  input_txt();
    faster;  //                                                                                                                   test
    case_i();
    good_bye;
}

//                                                                                                          author : 5 A 1 F U D D 1 N  5 A 8 8 1 R

///|||||||||||||||||||||||||||||||||||||||||||||||||||||| E N D ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

