#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int N, x, ans=0;
    std::cin >> N >> x;
    std::vector<int> a(N);
    for (int i=0; i<N; ++i){
        std::cin >> a.at(i);
    }

    std::sort(a.begin(), a.end());

    for (int i: a) {
        x -= i;
        if (x < 0){
            break;
        } else {
            ++ans;
        }
    }

    if (x > 0 && ans > 0) {
        --ans;
    }

    std::cout << ans << std::endl;

    return 0;
}
