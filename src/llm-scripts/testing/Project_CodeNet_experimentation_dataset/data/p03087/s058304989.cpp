#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};


int main() {
    ll N,Q;
    string S;
    cin >>N>>Q>>S;
    vector<ll> l(Q);
    vector<ll> r(Q);
    rep(i,Q){
        cin>>l[i]>>r[i];
    }

    vector<ll> sum(N);
    sum[0]=0;
    rep(i,N-1){
        if(S[i]=='A' && S[i+1]=='C'){
            sum[i+1] = sum[i]+1;
        }else{
            sum[i+1] = sum[i];
        }
        
    }

    rep(i,Q){
        cout<<sum[r[i]-1]-sum[l[i]-1]<<endl;;
    }
    

    return 0;
    

}