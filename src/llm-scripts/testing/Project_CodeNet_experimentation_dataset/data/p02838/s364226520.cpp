#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 200000000000
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
    ll N;
    cin >>N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }

    ll ans=0;
    vector<ll> cnt(61);

    rep(i,61){
        rep(j,N){
            if((A[j]>>i)&1){
                cnt[i]++;
            }

        }
    }
    rep(i,61){
        ll ml = cnt[i]*(N-cnt[i]);
        rep(j,i){
            ml = (ml*2)%mod;
        }
        ans = (ans+ml)%mod;
    }
    cout << ans << endl;


    return 0;
    

}