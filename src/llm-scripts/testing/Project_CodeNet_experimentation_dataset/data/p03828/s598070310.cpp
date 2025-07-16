#include <bits/stdc++.h>
using namespace std;
#define ll long long

//ライブラリ始まり

//定数

//円周率
const double PI = 3.1415926535897932384;

//天井
const int INF = 1000000000; // = 10^9
const ll LINF = 1000000000000000; // = 10^15

//ABC文字列
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZABC";
const string abc = "abcdefghijklmnopqrstuvwxyzabc";

//よくあるmodくん
const ll MOD = 1000000007; // = 10^9 + 7

//データ構造

//Union_Find木
struct UnionFind {
  vector<int> UF; // UF.at(i) : iの親の番号
  vector<int> SIZE; // SIZE.at(root(i)) : iと連結されてる要素の数
  UnionFind(int N) : UF(N), SIZE(N, 1) { // 最初は全てが根であるとして初期化
    for(int i = 0; i < N; i++) {
      UF.at(i) = i;
    }
  }
  int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (UF.at(x) == x) {
      return x;
    }
    return UF.at(x) = root(UF.at(x));
  }
  void unite(int x, int y) { // xとyの木を併合
    int rx = root(x); // xの根をrx
    int ry = root(y); // yの根をry
    if (rx == ry) {
      return; // xとyの根が同じ(=同じ木にある)時はそのまま
    }
    // xとyの根が同じでない(=同じ木にない)時：小さい方の根を大きい方の根につける
    if (SIZE.at(rx) < SIZE.at(ry)) {
      UF.at(rx) = ry;
      SIZE.at(ry) += SIZE.at(rx);
      SIZE.at(rx) = 0;
    }
    else {
      UF.at(ry) = rx;
      SIZE.at(rx) += SIZE.at(ry);
      SIZE.at(ry) = 0;
    }
  }
  bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
  int size(int x) { // xと連結されてる要素の数を返す
    return SIZE.at(root(x));
  }
};

//関数

//ctoi
int ctoi(char c){
  if (c == '0') {
    return 0;
  }
  if (c == '1') {
    return 1;
  } 
  if (c == '2') {
    return 2;
  } 
  if (c == '3') {
    return 3;
  }
  if (c == '4') {
    return 4;
  } 
  if (c == '5') {
    return 5;
  } 
  if (c == '6') {
    return 6;
  }
  if (c == '7') {
    return 7;
  } 
  if (c == '8') {
    return 8;
  } 
  if (c == '9') {
    return 9;
  }
  return -1;  
}

//素数判定
bool PN(int x) {
  if (x <= 1) {
    return false; // 1や0,-1は素数ではない
  }
  if (x == 2) {
    return true; // √2 + 1 > 2 なので下でやると 2 ％ 2 = 0 となり判定できない
  }
  for (int i = 2; i < sqrt(x) + 1; i++) {
    if (x % i == 0) {
      return false; // 割れたら素数じゃない
    }
  }
  return true;
}

//ライブラリ終わり

int main() {
  int N;
  cin >> N;
  vector<int> T(N, 1);
  for (int i = 2; i <= N; i++) {
    int M = i;
    for (int j = 2; j < sqrt(i) + 1; j++) {
      while (M % j == 0) {
        T.at(j - 1)++;
        M /= j;
      }
    }
    if (M != 1) {
      T.at(M - 1)++;
    }
  }
  ll ans = 1;
  for (int i = 0; i < N; i++) {
    ans *= T.at(i);
    ans %= MOD;
  }
  cout << ans << endl;
}