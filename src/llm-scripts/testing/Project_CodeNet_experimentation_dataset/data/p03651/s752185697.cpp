#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

ll gcd(ll a, ll b){
    ll r,temp;
    if (a < b){
        temp = a;
        a = b;
        b = temp;
    }
    while ( (r = a % b) != 0){
        a = b;
        b = r;
    }
    return b;
}

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    sort(all(A));
    ll gcd_num = A[0];
    rep(i,N) gcd_num = gcd(gcd_num, A[i]);
    bool possible = true;
    if (A[N - 1] < K) possible = false;
    if (K % gcd_num != 0) possible = false;
    
    if (possible) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}