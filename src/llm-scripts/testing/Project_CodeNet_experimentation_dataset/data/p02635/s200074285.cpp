// LOVED IT

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define ll int
#define bits_count __builtin_popcountll
#define endl '\n'
#define double long double
#define ld double
#define FOR(i,a,n) for (ll i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (ll i=(n);i>=(a);--i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define MINUS(a) memset((a),-1,sizeof((a)))
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(g) g.begin(),g.end()
#define sz(x) (ll)x.size()
#define pr pair<int,int>
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
    
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
// struct chash { int operator()(int x) const { return x ^ RANDOM; }};
// cc_hash_table<int, int, hash<int>> cnt;

const int MAXN = 305;
int dp[MAXN][MAXN][MAXN];
const int MOD = 998244353;
string s; int k,n,m;
vector<int> one_cnt;

int rec(int idx,int carry,int step){
    if(step < 0) return 0;

    if(idx == -1) return (carry == 0);
    
    int &ans = dp[idx][carry][step];
    if(ans != -1) return ans;
    ans = 0;

    int total_ones_here = one_cnt[idx] + carry;

    FOR(how_many_here,0,total_ones_here){
        int to_go_head = total_ones_here - how_many_here;
        int steps_here = max(0LL,to_go_head - carry);
        ans = (ans + rec(idx-1,to_go_head,step-steps_here))%MOD;
    }
    return ans;
}

void solve(){
    MINUS(dp);
    cin>>s>>k; n = sz(s); k = min(k,n);

    int cnt = 0;
    for(char c:s){
        if(c == '0'){
            one_cnt.push_back(cnt);
            cnt = 0;
        }else cnt++;
    }
    if(cnt) one_cnt.push_back(cnt);
    m = sz(one_cnt);

    cout<<rec(m-1,0,k)<<endl;
}
    
signed main(){
    
    FastRead;     
    
    int t = 1; 
    // cin>>t;
    FOR(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}
    


