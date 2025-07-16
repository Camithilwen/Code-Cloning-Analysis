#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin>>N;
    vector<int> A(N);
    rep(i,N) cin>>A[i];
    map<int,int> m;
    m[0]=3;
    ll ans = 1;
    rep(i,N){
        ans = (ans*m[A[i]])%mod;
        m[A[i]]--;
        m[A[i]+1]++;
    }
    cout<<ans<<endl;
}