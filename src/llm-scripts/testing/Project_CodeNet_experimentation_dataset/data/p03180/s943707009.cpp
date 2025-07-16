#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;
ll N;
vector<vector<ll>> A(16, vector<ll>(16, 0));
//dp[i]は集合の状態がiのときの最大値
vector<ll> dp((1<<16),0);



int main(){
    cin>>N;
    for(ll i=0;i<N;i++)
        for(ll j=0;j<N;j++)cin>>A[i][j];

    for(ll S=0;S<(1<<N);S++){
        for(ll i=0;i<N;i++)
            for(ll j=0;j<i;j++){
                if(S>>i&S>>j&1)dp[S]+=A[i][j];
            }
        for(ll T=S;T>0;T=(T-1)&S)chmax(dp[S],dp[T]+dp[S-T]);
    }

    print(dp[(1<<N)-1])


    return 0;
}
