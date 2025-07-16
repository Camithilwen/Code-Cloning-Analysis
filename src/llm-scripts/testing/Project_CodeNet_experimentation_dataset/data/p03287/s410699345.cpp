#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
static const double pi = 3.141592653589793;




int main(){
    ll N, M;
    cin>>N>>M;
    vector<ll> A(N);
    map<ll, ll> B;
    set<ll> Q;
    B[0]=1;
    ll Sum=0;
    rep(i, N){
        cin>>A[i];
        Sum+=A[i];
        Sum%=M;
        Q.insert(Sum);
        B[Sum]++;
    }
    ll Ans=0;
    for (auto itr = Q.begin(); itr != Q.end(); ++itr) {
        Ans+=B[*itr]*(B[*itr]-1)/2;
    }
    cout<<Ans<<endl;
}
    