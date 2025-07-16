#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<v<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

vector<ll> Eratosthenes( const ll N )
{
    std::vector<bool> is_prime( N + 1 );
    for( ll i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    std::vector<ll> P;
    for( ll i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( ll j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}
signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vl A=Eratosthenes(60000);
    ll count=0;ll now=0;
    while(count<N){
        now++;
        while(A[now]%5!=3)now++;
        cout<<A[now]<<" ";
        count++;
    }cout<<endl;


    return 0;
}
