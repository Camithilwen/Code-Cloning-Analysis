#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

int nth_bit(int64_t num, int n){
    return (num >> n) & 1;
}

int main(){
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    int XYZ = (1<<Z) + (1<<(Y+Z)) + (1<<(X+Y+Z));
    const int M = 1<<18;
    const int B = M-1;
    static int64_t dp[41][M][2];
    dp[0][1][0] = 1;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) for(int k=0; k<2; k++) for(int l=1; l<=10; l++){
        int j2 = ((j<<l) + 1) & B;
        int k2 = k | (XYZ == (XYZ&j2));
        add(dp[i+1][j2][k2], dp[i][j][k]);
    }
    int64_t ans = 0;
    for(int j=0; j<M; j++) add(ans, dp[N][j][1]);
    cout << ans << endl;
}