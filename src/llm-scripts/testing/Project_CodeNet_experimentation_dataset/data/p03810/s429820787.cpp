#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using lint = long long;

template <class T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

bool solve(int N, std::vector<lint>& A) {
    lint sum = std::accumulate(A.begin(), A.end(), 0LL);

    // Nが偶数の場合、和の偶奇がそのまま勝敗になる
    if (N % 2 == 0) return sum % 2 != 0;

    // Nが奇数の場合も、和が偶数なら絶対勝てる
    if (sum % 2 == 0) return true;

    // 奇数を前に持っていく
    std::sort(A.begin(), A.end(), [](int a, int b) { return a % 2 > b % 2; });
    // 奇数が複数個ある、あるいは唯一の奇数が1(減らせない)なら負け
    if (A[0] == 1 || (A[1] & 1) != 0) return false;

    // そうでなければ、唯一の奇数を減らしてシミュレート
    --A[0];
    int g = accumulate(A.begin(), A.end(), 0LL, gcd<lint>);  // 全体のgcdを取る
    for (auto& a : A) a /= g;
    return !solve(N, A);
}

int main() {
    int N;
    std::cin >> N;
    std::vector<lint> A(N);
    for (auto& a : A) std::cin >> a;

    std::cout << (solve(N, A) ? "First" : "Second") << std::endl;
    return 0;
}
