#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}
ll maxx(ll x,ll y,ll z){return max(max(x,y),z);}
ll minn(ll x,ll y,ll z){return min(min(x,y),z);}
ll gcd(ll x,ll y){if(x%y==0) return y;else return gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}

vector<ll> pw2(51,1);vector<ll> pw10(19,1);
ll high_order_bit(ll n){
    ll tmp=1,i=-1;
    while(tmp<=n){
        tmp*=2;
        i++;
    }
    if(n==0) return 0;
    else return i;
}
vector<ll> binary_expansion(ll n){
    vector<ll> B(high_order_bit(n)+1);
    ll tmp=n;
    for(ll i=high_order_bit(n);i>=0;i--){
        B[i]=tmp/pw2[i];
        tmp%=pw2[i];
    }
    return B;
}
vector<ll> divisor(ll x){
    vector<ll> div;
    for(int i=1;i*i<=x;i++){
        if(i*i!=x && x%i==0){
            div.pb(i);
            div.pb(x/i);
        }
        else if(x%i==0) div.pb(i);
    }
    return div;
}
vector<ll> vectorprime(ll x){
    vector<bool> is_prime(x+1);
    vector<ll> prime;
    rep(i,x+1) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=x;i++){
        if(is_prime[i]){
            prime.pb(i);
        }
        for(int j=i*2;j<=x;j+=i) is_prime[j]=false;
    }
    return prime;
}

int main(){
    {rep1(i,50) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N; cin>>N;
    ll count=0;
    vector<ll> V=vectorprime(55555);
    rep(i,sz(V)){
        if(V[i]%5==2){
            cout<<V[i]<<" ";
            count++;
        }
        if(count==N) break;
    }
}