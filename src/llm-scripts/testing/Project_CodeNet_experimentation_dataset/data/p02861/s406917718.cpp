#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>

int main(void){
    int N;
    double ans=0;
    std::cin >> N;
    std::vector<int> P(N);
    std::vector<std::vector<int>> C(N, std::vector<int>(2));
    for (int i = 0; i < N; ++i){
        std::cin >> C[i][0] >> C[i][1];
        P.at(i) = i;
    }

    do {
        for (int i = 0; i < N - 1; ++i){
            ans += std::sqrt((C[P[i + 1]][0] - C[P[i]][0])*(C[P[i + 1]][0] - C[P[i]][0]) + (C[P[i + 1]][1] - C[P[i]][1])*(C[P[i + 1]][1] - C[P[i]][1]));
        }
    } while (std::next_permutation(P.begin(), P.end()));

    for(int i = 2; i <= N; ++i){
        ans /= i;
    }

    std::cout << std::fixed << std::setprecision(10) << ans << std::endl;

    return 0;
}