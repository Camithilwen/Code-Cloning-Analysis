#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 1e+9 + 7;

int main()
{
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    long long ans = 1;
    REP(i, N) ans = ans*10 % MOD;

    int S = (1<<(X+Y+Z))-1;  // X+Y+Z-1 個前までの状態を保持しておけば十分
	int C = (1<<(Z-1))|(1<<(Y+Z-1))|(1<<(X+Y+Z-1));

    // dp[i][j]: i-1まで見たとき、直前が j で XYZ を含まない数列の数
    vector<vector<long long>> dp(N+1, vector<long long>((1<<(X+Y+Z))+1));
	dp[0][0] = 1;
    FOR(i, 1, N+1){
        REP(s, S+1){ // s: 直前の状態
            if(dp[i-1][s] == 0) continue; 
            FOR(j, 1, 11){  // i 番目が j のとき
                int sn = (s<<j)|(1<<(j-1));
                sn &= S;  // sn の bit 桁数を S 未満にする
                if((sn&C) != C){
                    dp[i][sn] += dp[i-1][s];
                    dp[i][sn] %= MOD;
                }
            }
        }
    }

    REP(i, S+1) ans = (ans-dp[N][i]) % MOD;
    cout << (ans+MOD)%MOD << endl;


    return 0;
}