#include <bits/stdc++.h>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef long double ld;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll N, A, B, i, X[100001], ans=0;
    
    cin >> N >> A >> B;

    for(i=1; i<=N; i++){
        cin >> X[i];

        if(i>=2){
            ans += min(A*(X[i]-X[i-1]), B);
        }
    }

    cout << ans << endl;

    return 0;
}