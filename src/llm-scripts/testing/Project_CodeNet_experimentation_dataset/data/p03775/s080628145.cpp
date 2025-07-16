#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll F(ll A, ll B){
    string bufA = to_string(A), bufB = to_string(B);
    return max(bufA.size(), bufB.size());
}

int main(){
    ll N;
    ll ans = to_string(N).size();
    cin >> N;
    for(ll i = 1; i <= sqrt(N); ++i){
        if(N % i == 0) ans = min(ans, F(i, N/i));
    }
    cout << ans << endl;
    return 0;
}