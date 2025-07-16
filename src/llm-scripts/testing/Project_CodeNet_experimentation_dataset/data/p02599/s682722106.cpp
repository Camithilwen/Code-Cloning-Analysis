#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define lsc(x)      scanf("%lld",&x)
#define sc(x)       scanf("%d",&x)
#define lpr(x)      printf("%lld ",(long long)x)
#define pr(x)       printf("%d ",x)
#define n_l         printf("\n")
#define VI          vector<int>
#define VII         vector<long long int>
#define m_p         make_pair
#define pb          push_back
#define fi           first
#define se           second
#define mset(x,y)   memset(x,y,sizeof(x))
#define sz(v)       (int)v.size()
#define all(v)      v.begin(), v.end()
#define fr(i, a, n) for(int i=a;i<=n;i++)
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
const int N=(int)1e6+5;
const int mod = 1000000007;
typedef long long ll;
// order_of_key (val): returns the no. of values strictly less than val
// find_by_order (k): returns the kth largest element iterator.(0-based)
// vector<int>::iterator itr=lower_bound(v.begin(),v.end(),x);
// s.substr(pos[0-indexed], len(default=till end))
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll fmod(ll x){if (x<mod) return x;return x%mod;}
ll mul(ll a, ll b, ll c){
	ll ret=0;while(b){if (b%2) ret=(ret+a)%c;a=(a*2)%c;b>>=1;}
    return ret;
}
int modpow(ll a, ll b){
    ll ret=1;while(b){if (b%2) ret=(ret*a)%mod;a=(a*a)%mod;b>>=1;}
    return (int)ret;
}
inline int inv(int x){ return modpow(x, mod-2);}
int isprime[N];
void calc_prime(){
	isprime[1]=1;for(ll i=2;i<N;i++) if (!isprime[i]) for(ll j=i*i;j<N;j+=i) isprime[j]=1;
}
int ans[N];
int a[N], added[N];
#define pii pair<int, int>
vector<pii> v[N];
int BIT[N];
void upd(int idx, int val){
    //trace(idx, val);
    while(idx<N){
        BIT[idx] += val;
        idx += idx & (-idx);
    }
}
int query(int idx){
    if (idx<1) return 0;
    int ret = 0;
    int idx1 = idx;
    while(idx){
        ret += BIT[idx];
        idx -= idx & (-idx);
    }
    return ret;
}
int main(){
    int n, q;
    sc(n);sc(q);
    fr(i, 1, n) sc(a[i]);
    fr(i, 1, q){
        int l, r;sc(l);sc(r);
        v[r].pb({l, i});
    }
    fr(i, 1, n){
        //trace(i);
        if (added[a[i]]){
            upd(added[a[i]], -1);
        }
        added[a[i]] = i;
        upd(added[a[i]], 1);
        for(auto pp: v[i]){
            int l = pp.fi;
            int idx = pp.se;
            ans[idx] = query(i) - query(l-1);
        }
    }
    fr(i, 1, q){
        pr(ans[i]);
    }n_l;
    return 0;
}

