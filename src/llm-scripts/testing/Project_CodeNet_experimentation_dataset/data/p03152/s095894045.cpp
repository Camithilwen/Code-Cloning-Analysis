#include <bits/stdc++.h>
#define owo(i,a, b) for(int i=(a);i<(b); ++i)
#define uwu(i,a, b) for(int i=(a)-1; i>=(b); --i)
#define senpai push_back
#define ttgl pair<int, int>
#define ayaya cout<<"ayaya~"<<endl
 
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gpu_hash_map<int, int> mp;*/
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ll root = 62;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
const double PI = acos(-1);
const double eps = -1e6;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 1001;
ll arr[mxN];
ll b[mxN];
int cnt[mxN*mxN];
ll n, m;
int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    owo(i, 0, n) {
        cin>>arr[i];
        cnt[arr[i]]++;
        if(cnt[arr[i]]>1) {
            cout<<"0\n";
            exit(0);
        }
    }
    memset(cnt, 0, sizeof(cnt));
    owo(i, 0, m) {
        cin>>b[i];
        cnt[b[i]]++;
        if(cnt[b[i]]>1) {
            cout<<"0\n";
            exit(0);
        }
    }
    ll ans = 1;
    sort(arr, arr+n);
    sort(b, b+m);
    reverse(arr, arr+n);
    reverse(b, b+m);
    ll aidx = 0;
    ll bidx = 0;
    for(ll nxt=n*m; nxt>0; --nxt) {
        while(aidx<n&&arr[aidx]>=nxt)aidx++;
        while(bidx<m&&b[bidx]>=nxt)bidx++;
        if(arr[aidx-1]==nxt&&b[bidx-1]==nxt) {
            ans = (ans*1LL)%MOD;
        }else if(arr[aidx-1]==nxt) {
            ans = (ans * bidx)%MOD;
        }else if(b[bidx-1]==nxt) {
            ans = (ans * aidx)%MOD;
        }else {
            ans = (ans * max((aidx * bidx - n * m + nxt), 0LL))%MOD;
        }
    }
    cout<<ans<<"\n";
    return 0;
}