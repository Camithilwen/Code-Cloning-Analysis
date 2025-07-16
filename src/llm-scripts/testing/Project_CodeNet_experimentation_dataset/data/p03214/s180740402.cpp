#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}


int main() {
    int N;
    cin >> N;
    vector<double> a(N);
    REP(i,N) cin >> a[i];

    double av = accumulate(ALL(a),double(0))/N;
    int ans  = 0;
    double shortest = INF;
    REP(i,N) {
        if (chmin(shortest,abs(av-a[i]))) {
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}
