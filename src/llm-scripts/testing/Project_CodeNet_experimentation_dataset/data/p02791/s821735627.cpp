#include <iostream>

int main(void){
    int N, tmp=200001, ans=0;
    std::cin >> N;
    for (int i=0; i<N; ++i){
        int a;
        std::cin >> a;
        if (a < tmp){
            ++ans;
            tmp = a;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
