#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    long long xor_A = 0;
    for (int i = 0; i < N; i++) xor_A ^= A[i];

    std::vector<long long> v(N);
    for (int i = 0; i < N; i++) v[i] = A[i] & ~xor_A;

    long long rank = 0;
    for (int i = 59; i >= 0; i--) {
        for (int j = rank; j < N; j++) {
            if (v[j] & 1LL << i) {
                if (j > rank) v[rank] ^= v[j];

                for (int k = 0; k < N; k++) {
                    if (k != rank && v[k] & 1LL << i)
                        v[k] ^= v[rank];
                }

                rank++;
                break;
            }
        }
    }

    long long res = 0;
    for (int i = 0; i < N; i++) res ^= v[i];

    std::cout << res * 2 + xor_A << "\n";
}