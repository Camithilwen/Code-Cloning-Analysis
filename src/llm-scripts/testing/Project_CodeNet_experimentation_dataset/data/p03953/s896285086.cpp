#include <bits/stdc++.h>
using namespace std;
#ifdef ENABLE_DEBUG
#define DEBUG(a) cerr<<#a<<"="<<a<<endl
#define DEBUG_ARRAY(a,n) cerr<<#a<<"["<<n<<"]="<<a[n]<<endl
#else
#define dump(a) 
#define dumparr(a,n) 
#endif
#define FOR(i, a, b) for(int i = a;i < b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(int i = b-1;i >= a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)

typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> P;
typedef pair<ll,P> PP;
typedef vector<ll> vll;

const ll INF=(1LL<<50);

vector<ll> d;
vector<ll> powv(vector<ll> &a){
    vector<ll> ret(a.size());
    REP(a.size()){
        ret[i]=a[a[i]];
    }
    return ret;
}
vector<ll> addv(vector<ll> &a,vector<ll> &b){
    vector<ll> ret(a.size());
    REP(a.size()){
        ret[i]=b[a[i]];
    }
    return ret;
}
void swapv(vector<ll> &a,ll b,ll c){
    swap(a[b],a[c]);
}
void solve(long long N, std::vector<long long> x, long long M, long long K, std::vector<long long> a){
    REP(N-1){
        d.push_back(x[i+1]-x[i]);
    }
    vector<ll> h(N-1);
    iota(h.begin(),h.end(),0);
    REP(M){
        swapv(h,a[i],a[i]-1);
    }
    vector<ll> ans(N-1);
    iota(ans.begin(),ans.end(),0);
    while(K>0){
        if((K&1)>0){
            ans=addv(ans,h);
        }
        K>>=1;
        h=powv(h);
    }
    cout<<x[0]<<endl;
    REP(x.size()-1){
        x[i+1]=x[i]+d[ans[i]];
        cout<<x[i+1]<<endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
    }
    long long M;
    scanf("%lld",&M);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> a(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&a[i]);
        a[i]--;
    }
    solve(N, std::move(x), M, K, std::move(a));
    return 0;
}
