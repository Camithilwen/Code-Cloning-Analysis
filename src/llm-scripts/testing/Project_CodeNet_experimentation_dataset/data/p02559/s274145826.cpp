#include<bits/stdc++.h>
using namespace std;

#define int             long long
#define ld              long double
#define F               first
#define S               second
#define PB              push_back
#define FOR(a,b)        for(int i=a;i<=b;i++)
#define RFOR(a,b)       for(int i=a;i>=b;i--)
#define FORE(a)         for(auto it: a)
#define all(x)          x.begin(),x.end()
#define rall(x)         x.rbegin(),x.rend()
#define clr(x,f)        memset(x,f,sizeof(x))
#define pii             pair<int,int>
#define vi              vector<int>
#define vpii            vector<pii>
#define vvi             vector<vi>
#define si              set<int>
#define spii            set<pii>
#define usi             unordered_set<int>
#define uspii           unordered_set<pii>
#define mii             map<int,int>
#define umii            unordered_map<int,int>
#define pqmx            priority_queue<int>
#define pqmn            priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define tzbits(x)       __builtin_ctzll(x)
#define lzbits(x)       __builtin_clzll(x)
#define pbits(x)        __builtin_parityll(x)
#define gcd             __gcd
#define lcm(x, y)       ((x)*(y))/gcd(x,y)
#define endl            '\n'
#define sz(s)           (int)s.size()
#define sp(x,y)         fixed<<setprecision(y)<<x
const int mod = 1000000007;
const int inf = 1000000000000000000;
const ld PI = 3.1415926535897932384626;
const ld eps = 1e-12;
void __print(int32_t x) {cout<<x;}
void __print(int x) {cout<<x;}
void __print(double x) {cout<<x;}
void __print(ld x) {cout<<x;}
void __print(float x) {cout<<x;}
void __print(bool x) {cout<<(x?"true":"false");}
void __print(char x) {cout <<'\''<<x<<'\'';}
void __print(const char *x) {cout <<'\"' <<x<<'\"';}
void __print(const string &x) {cout<<'\"'<<x<<'\"';}
template<typename T,typename V>     void __print(const pair<T,V> &x) {cout<<'{';__print(x.first);cout<<',';__print(x.second);cout<<'}';}
template<typename T>                void __print(const T &x) {int f=0;cout<<'{';for(auto &i:x)cout<<(f++?",":""),__print(i);cout<<"}";}void _print(){cout<<"]\n";}
template <typename T,typename... V> void _print(T t, V... v) {__print(t);if(sizeof...(v))cout<<", ";_print(v...);}
#define dbg(x...) cout<<"["<<#x<<"]=[";_print(x)
int powerm(int base,int exp) {int res=1;base%=mod;while(exp>0){if(exp&1)res=(res*base)%mod;base=(base*base)%mod;exp=exp>>1;}return res;}
int power(int base,int exp) {int res=1;while(exp>0){if(exp&1)res=res*base;base=base*base;exp=exp>>1;}return res;}
float powerNeg(float base,int exp) {float temp;if(exp==0)return 1;temp=powerNeg(base,exp/2);if(exp%2==0)return temp*temp;else{if(exp>0)return base*temp*temp;else return (temp*temp)/base;}}
int modinv(int exp) {return powerm(exp,mod-2);}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



const int N=1e6+5,M=N;

vi a;
void update(int i,int val){
    while(i<sz(a)){
        a[i]+=val; 
        i+=i&(-i);
    }
}
int query(int i){
    int res=0;
    while(i>=1){
        res+=a[i];
        i-=i&(-i);
    }
    return res;
}

void solve(){
    
    int i,j,k;
    int n,q; cin>>n>>q;

    a=vi(n+1);

    FOR(1,n){
        int val; cin>>val;
        update(i,val);
    }
    FOR(0,q-1){
        int t; cin>>t;
        if(t){
            int j,k; cin>>j>>k;
            int ans=query(k)-query(j);
            cout<<ans<<endl;
        }else{
            int j,val; cin>>j>>val; 
            update(j+1,val);
        }
    }
    
    

    //cout<<<<endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T=1;
    // cin>>T;
    FOR(1,T){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    // cout<<endl<<"Times Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC<<"sec";
    return 0;
}