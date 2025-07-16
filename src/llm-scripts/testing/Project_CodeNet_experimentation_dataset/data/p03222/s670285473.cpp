#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

ll fibo[10];
ll dp[102][10];

ll func_fibo(ll n){
    if(n <= 0) return 1;
    else{
        return fibo[n];
    }
}
int main()
{
    cout << fixed << setprecision(15);
    ll H, W, K;
    cin >> H >> W >> K;

    fibo[1] = 2;
    fibo[2] = 3;
    for(ll i=3; i<=10; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    // cout << func_fibo(8) << endl;

    Fill(dp, 0);

    dp[0][1] = 1;
    
    for(ll i=1; i<=H; i++){
        for(ll j=1; j<=W; j++){
            dp[i][j] += (dp[i-1][j]*func_fibo(j-2)*func_fibo(W-j-1)) % MOD;
            if(j>1){
                dp[i][j] += (dp[i-1][j-1]*func_fibo(j-3)*func_fibo(W-j-1)) % MOD;
            }
            if(j< W){
                dp[i][j] += (dp[i-1][j+1]*func_fibo(j-2)*func_fibo(W-j-2)) % MOD;
            }
            dp[i][j] = dp[i][j] % MOD;
        }
    }

    cout << dp[H][K] << endl;
    return 0;
}