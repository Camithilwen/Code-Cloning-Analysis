#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

template <class T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

bool solve(int N, vector<int>& A) {
    if (N == 1) return false;

    // 総和の偶奇
    int parity = accumulate(A.begin(), A.end(), 0, [](int init, int a) { return (init + (a & 1)) & 1; });

    // Nが偶数の場合、和の偶奇がそのまま勝敗になる
    if ((N & 1) == 0) return parity != 0;

    // Nが奇数の場合も、和が偶数なら絶対勝てる
    if (parity == 0) return true;

    // 奇数を前に持っていく
    sort(A.begin(), A.end(), [](int a, int b) { return (a & 1) > (b & 1); });
    // 奇数が複数個ある、あるいは唯一の奇数が1(減らせない)なら負け
    if (A[0] == 1 || (A[1] & 1) != 0) return false;
    // そうでなければ、唯一の奇数を減らしてワンチャンに賭ける
    --A[0];
    int g = accumulate(A.begin(), A.end(), 0, gcd<int>);
    for (auto& a : A) a /= g;
    return !solve(N, A);
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) cin >> a;
    cout << (solve(N, A) ? "First" : "Second") << endl;
    return 0;
}
