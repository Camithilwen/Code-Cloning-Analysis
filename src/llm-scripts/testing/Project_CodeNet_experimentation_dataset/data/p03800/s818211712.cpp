#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
using namespace std;
#define rep(i,a,b) for(int64_t i=(a);i<(b);++i) // a ≦ i < b 
#define Rrep(i,a,b) for(int64_t i=(a);i>=(b);--i) // reverse repeat. a から b まで減少．
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend() //逆イテレータ
#define RANGE(a,b,c) (a).begin()+(b),(a).begin()+(c) // [b,c) イテレータ
#define INF 1000000000000000
#define MOD 1000000007
using PII = pair<int64_t, int64_t>;
using VI = vector<int64_t>;
using VVI = vector<VI>;
using VS = vector<string>;
using VP = vector<PII>;
using i64 = int64_t;
template<typename T> void invec(vector<T> &A){for(T& a:A) cin >> a;} 

char SWswap(char c){
    if (c == 'S') return 'W';
    else return 'S';
}

bool out(string S, string s){
    int N = S.size();
    if (s[N-1] == 'o'){
        if (S[N-1] == 'S' && S[0] == S[N-2]){
            return true;
        }
        else if (S[N-1] == 'W' && S[0] != S[N-2]){
            return true;
        }
    }
    else {
        if (S[N-1] == 'S' && S[0] != S[N-2]){
            return true;
        }
        else if (S[N-1] == 'W' && S[0] == S[N-2]){
            return true;
        }
    }
    return false;
}

int main() {
cin.tie(0);
ios::sync_with_stdio(false);

int N;
string s;
cin >> N >> s;

VS ans{"SS", "SW", "WS", "WW"};
for(string S: ans){
    rep(i, 1, N-1){
        if (s[i] == 'o'){
            if (S[i] == 'S') S.push_back(S[i-1]);
            else S.push_back(SWswap(S[i-1]));
        }
        else { // s[i] == 'x'
            if (S[i] == 'S') S.push_back(SWswap(S[i-1]));
            else S.push_back(S[i-1]);
        }
    }

    if (s[0] == 'o'){
        if ((S[0] == 'S' && S[1] == S[N-1]) || (S[0] == 'W' && S[1] != S[N-1]))
            if (out(S, s)){
                cout << S + "\n";
                return 0;
            }
    }
    else {
        if ((S[0] == 'S' && S[1] != S[N-1]) || (S[0] == 'W' && S[1] == S[N-1]))
            if (out(S, s)){
                cout << S + "\n";
                return 0;
            }
    }

}


cout << "-1\n";

return 0;
}
// コンテスト前はtemplate振り返り。
// 書いて考える．場合分け．情報整理．
// 単純に分かる量から．愚直解を実装して研究．
// 境界，出力文字列 チェック．行末にスペース入れない．
// 可読性優先．高速化次点．
// まずは全探索，分割，次にDP(小さい問題から大きな問題)
// 制限を見る．境界に注意．求めたい量の変域．動かせる量．
// 偶奇，逆から，ソート，出現回数，出現位置，DP， 余事象，包除
// データ構造． 問題の特徴量．単調性→二分探索
// 存在判定：構成方法，入力の特徴
// 構築問題。極端解を試す。
// 例外を十分に含む一般化．想像力の限界
// 小さい系から例示
// 代数的処理．前処理によるクエリ高速化．
// 始めは過剰に例示・場合分けしてもいい．各場合を確実に対処．
// 自明な例から処理，除外．
// 小数のときは，精度の設定する．doubel 変数に数値を入力するときは 123. とする．
// コーナーケース。境界値。数表出力プログラム作る
// 実行エラー：vector添え字超え．0割り．

