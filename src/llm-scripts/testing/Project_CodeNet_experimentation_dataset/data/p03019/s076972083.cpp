#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
#define __builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
template <typename CT, typename T> inline void reset_container(CT &c, int sz, T v){c.resize(sz); for(auto &x: c) x=v;}
#define taskname "C"
int n;
ll x;
ll start;
class subject{
public:
    ll b, l, u, w;
    void input(){
        read(b);
        read(l);
        read(u);
        start+=b*l;
        w=(x-b)*u+b*l;
    }
    ll cost(ll x){
        if(x<=b*l){
            return (x-1)/l+1;
        }
        else{
            x-=b*l;
            return b+(x-1)/u+1;
        }
    }
} s[100001];
ll f[100001];
int get(int i){
    int res=n;
    int low=0, high=n-1, mid;
    while(low<=high){
        mid=(low+high)/2;
        ll sum=f[mid];
        if(mid<i) sum+=s[i].w;
        if(sum>=start){
            res=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return res;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(x);
    FOR(i, 1, n) s[i].input();
    sort(s+1, s+n+1, [](subject A, subject B){
        return A.w>B.w;
    });
    ll ans=x*n;
    FOR(i, 1, n) f[i]=f[i-1]+s[i].w;
    FOR(i, 1, n){
        int j=get(i);
        ll res=x*j;
        if(j>i) res-=x;
        ll now=start-f[j];
        if(j>i) now+=s[i].w;
        if(now>0) ans=min(ans, res+s[i].cost(now));
        else ans=min(ans, res);
    }
    writeln(ans);
}