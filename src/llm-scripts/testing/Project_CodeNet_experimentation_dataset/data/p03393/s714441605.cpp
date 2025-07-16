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

int main()
{
    cout << fixed << setprecision(15);
    string S;
    cin >> S;

    ll N = S.length();

    map<char, bool> A;

    REP(i, N){
        A[S[i]] = true;
    }
    if(N<26){
        cout << S;
        REP(i, 26){
            // cout << char(i+'a') << endl;
            char c = char(i+'a');
            if(!A.count(c)){
                cout << c << endl;
                return 0;
            }
        }
    }

    vector<char> T;
    for(ll i=25; i>=0; i--){
        if(i ==25){
            T.push_back(S[i]);
            continue;
        }
        // cout << S[i] << endl;
        sort(T.begin(), T.end());
        // cout << T[0] << endl;
        if(i==0){
            if(S[0] != 'z'){
                cout << char(S[0]+1) << endl;
            }
            else{
                cout << -1 << endl;
            }
            return 0;
        }
        else if(S[i] < T[T.size()-1]){
            REP(j, i){
                cout << S[j];
            }
            for(auto v: T){
                if(v > S[i]){
                    cout << v << endl;
                    return 0;
                }
            }
        }
        T.push_back(S[i]);
    }
    return 0;
}