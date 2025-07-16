#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N, K;
    cin >> N >> K;
    unsigned long mx{0}, g{0};
    for(unsigned long i{0}, A; i < N; ++i){
        cin >> A;
        mx = max(mx, A);
        g = __gcd(g, A);
        if(mx >= K && K % g == 0)return 0 & puts("POSSIBLE");
    }
    puts("IMPOSSIBLE");
    return 0;
}