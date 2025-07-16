#include <bits/stdc++.h>
using namespace std;
using ll=long long;

// GCD, LCM
// https://youtu.be/8lm8o8L9Bmw?t=2285
// https://youtu.be/XI8exXVxZ-Q?t=3595
// https://youtu.be/F2p_e6iKxnk?t=843
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
    ll N,K;
    cin >>N >> K;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    if(A.back()<K){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    ll g = A[0];
    
    for(int i=1;i<N;i++){
        g = gcd(g,A[i]);
    }
    if(K%g ==0){
        cout <<"POSSIBLE" << endl;
    }else{
        cout <<"IMPOSSIBLE" << endl;
    }
    return 0;
}