#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

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
    return a/gcd(a, b) * b;
}

ll dp[85][85][14000];

int main()
{
    cout << fixed << setprecision(15);
    ll H, W;
    cin >> H >> W;

    vector<vector<ll>> A(H+1, vector<ll>(W+1, 0));
    vector<vector<ll>> B(H+1, vector<ll>(W+1, 0));

    for(ll i=1; i<=H; i++){
        for(ll j=1; j<=W; j++){
            cin >> A[i][j];
        }
    }

    for(ll i=1; i<=H; i++){
        for(ll j=1; j<=W; j++){
            cin >> B[i][j];
        }
    }

    Fill(dp, 0);

    ll a = A[1][1];
    ll b = B[1][1];

    dp[1][1][abs(a-b)] = 1;

    for(ll i=1; i<=H; i++){
        for(ll j=1; j<=W; j++){
            REP(k, 13000){
                a = A[i][j];
                b = B[i][j];
                
                dp[i][j][abs(k+abs(a-b))] = max(dp[i][j][abs(k+abs(a-b))], dp[i-1][j][k]);
                dp[i][j][abs(k-abs(a-b))] = max(dp[i][j][abs(k-abs(a-b))], dp[i-1][j][k]);

                dp[i][j][abs(k+abs(a-b))] = max(dp[i][j][abs(k+abs(a-b))], dp[i][j-1][k]);
                dp[i][j][abs(k-abs(a-b))] = max(dp[i][j][abs(k-abs(a-b))], dp[i][j-1][k]);        
            }
        }
    }

    // REP(i, H+1){
    //     REP(j, W+1){
    //         cout << dp[i][j][0];
    //     }
    //     cout << endl;
    // }
    REP(k, 13000){
        // cout << dp[H][W][k] << endl;
        if(dp[H][W][k]){
            cout << k << endl;
            return 0;
        }
    }
    return 0;
}