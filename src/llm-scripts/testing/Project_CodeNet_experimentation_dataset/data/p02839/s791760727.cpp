#include <bits/stdc++.h>
using namespace std;
const auto start_time = std::chrono::high_resolution_clock::now();
void timecalculater(){
    #ifndef ONLINE_JUDGE
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
    #endif
}
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int  i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long int> vll;
typedef vector<pii> vii;
ll p=1e9+7;
const int N=2e5+5;
ll power(ll a,ll x){
    if(x<0)return 1;
    ll r=1;
    while(x!=0){
        if(x%2==1){
            r=r*a;r%=p;
        }
        a=a*a;a%=p;
        x=x/2;
    }
    return r;
}
ll mul(ll a,ll b){
    ll t=(a*b);
    if(t>=p)t%=p;
    return t;
}
int main() {
    
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int T=1;
    // cin>>T;
    while(T--){
        int h,w;cin>>h>>w;
        int a[h][w],b[h][w];
        rep(i,h)rep(j,w)cin>>a[i][j];
        rep(i,h)rep(j,w)cin>>b[i][j];
        int x=12800;
        bool dp[h][w][2*x];
        memset(dp,0,sizeof(dp));
        int y=a[0][0]-b[0][0];if(y<0)y=-y;
        dp[0][0][y+x]=1;
        dp[0][0][y]=1;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                for(int k=0;k<x*2;k++){
                    int y=a[i][j]-b[i][j];if(y<0)y=-y;
                    if(i-1>=0){
                        if(k-y>=0&&dp[i-1][j][k-y]==1)
                        dp[i][j][k]=1;
                        if(k+y<2*x&&dp[i-1][j][k+y]==1)
                        dp[i][j][k]=1;
                    } 
                    if(j-1>=0){
                        if(k-y>=0&&dp[i][j-1][k-y]==1)
                        dp[i][j][k]=1;
                        if(k+y<2*x&&dp[i][j-1][k+y]==1)
                        dp[i][j][k]=1;
                    }
                }
            }
        }
        int ans=2*x;
        rep(i,2*x){
            if(dp[h-1][w-1][i]==1){
                ans=min(ans,abs(i-x));
                // dbg(i);
            }
        }
        cout<<ans<<endl;
    }   
    timecalculater();
    return 0;   
} 