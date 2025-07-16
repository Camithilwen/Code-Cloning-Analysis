#include <iostream>

int main(void){
    int N, ans=40;
    std::cin >> N;

    for (int i=0; i<N; ++i){
        int a, cnt=0;
        std::cin >> a;
        while (a % 2 == 0){
            a /= 2;
            ++cnt;
        }
        if (cnt < ans) ans = cnt;
    }

    std::cout << ans << std::endl;

    return 0;
}
