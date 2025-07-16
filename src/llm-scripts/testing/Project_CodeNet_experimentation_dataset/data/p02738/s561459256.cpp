#include <iostream>
#include <cstdio>
using namespace std;
int N, M;
int MOD;
int Fact[6005], Inv[6005], Pw2[6005], Pw3[6005], IPw2[6005], IPw3[6005];
int power(int n, int p){
    int sol = 1;
    while(p){
        if(p & 1)
            sol = (1LL * sol * n) % MOD;
        p /= 2;
        n = (1LL * n * n) % MOD;
    }
    return sol;
}
void precalcFact(){
    Fact[0] = 1;
    for(int i = 1; i <= N * 3; i++){
        Fact[i] = (1LL * Fact[i - 1] * i) % MOD;
    }
    Inv[N * 3] = power(Fact[N * 3], M - 2);
    for(int i = N * 3 - 1; i >= 0; i--)
        Inv[i] = (1LL * Inv[i + 1] * (i + 1)) % MOD;
}

void precalcPower(){
    Pw2[0] = 1;
    Pw3[0] = 1;
    IPw2[0] = 1;
    IPw3[0] = 1;
    for(int i = 1; i <= N * 3; i++){
        Pw2[i] = (1LL * Pw2[i - 1] * 2) % MOD;
        Pw3[i] = (1LL * Pw3[i - 1] * 3) % MOD;
        IPw2[i] = power(Pw2[i], M - 2);
        IPw3[i] = power(Pw3[i], M - 2);
    }
}
int compute(int p1, int p2, int p3){
    int ans = Fact[3 * N];
    ans = (1LL * ans * Inv[p1]) % MOD;
    ans = (1LL * ans * Inv[p2]) % MOD;
    ans = (1LL * ans * Inv[p3]) % MOD;
    ans = (1LL * ans * IPw2[p2]) % MOD;
    ans = (1LL * ans * IPw3[p3]) % MOD;
    return ans;
}
void Solve(){
    int ans = 0;
    for(int i = 0; i <= N * 3; i++){
        for(int j = 0; j <= N * 3; j++){
            int g1 = 3 * N - 2 * i - 3 * j;
            if(g1 < i)
                break;
            ans += compute(g1, i, j);
            if(ans >= MOD)
                ans -= MOD;
        }
    }
    cout << ans << '\n';
}
int main()
{
    cin >> N >> M;
    MOD = M;
    precalcFact();
    precalcPower();
    Solve();
    return 0;
}
