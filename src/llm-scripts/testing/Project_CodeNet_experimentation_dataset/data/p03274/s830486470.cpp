#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, K, ans=1000000000000, tmp=-1;
vector<ll> A, B;

signed main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        if(a<0) A.push_back(a);
        else B.push_back(a);
    }
    reverse(A.begin(), A.end());
    ll As = (ll)A.size();
    ll Bs = (ll)B.size();
    for(int i=0;i<min(K, As);i++) {
        if(Bs-1>=K-i-2&&K-i-2>=0) {
            ans = min(ans, 2*min(abs(A[i]), abs(B[K-i-2])) + max(abs(A[i]), abs(B[K-i-2])));
        }
    }
    if(As>=K) ans = min(ans, abs(A[K-1]));
    for(int i=0;i<min(K, Bs);i++) {
        if(As-1>=K-i-2&&K-i-2>=0) {
            ans = min(ans, 2*min(abs(B[i]), abs(A[K-i-2])) + max(abs(B[i]), abs(A[K-i-2])));
        }
    }
    if((ll)B.size()>=K) ans = min(ans, abs(B[K-1]));
    /*
    if(K>tmp+1) {
        for(int i=0;i<=tmp;i++) {
            if(K+i-1<=N-1) ans = min(ans, 2*min(abs(A[i]), abs(A[K+i-1])) + max(abs(A[i]), abs(A[K+i-1])));
        }
    }
    if(K>N-tmp-1) {
        for(int i=tmp+1;i<N;i++) {
            if(i+1-K>=0) ans = min(ans, 2*min(abs(A[i]), abs(A[i+1-K])) + max(abs(A[i]), abs(A[i+1-K])));
        }
    }
    */
    cout << ans << endl;
    return 0;
}