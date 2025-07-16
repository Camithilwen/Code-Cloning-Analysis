#include <iostream>
#include <tuple>
#include <vector>

int main()
{
    int h, w; std::cin >> h >> w;
    std::vector<std::vector<int>> a(h, std::vector<int>(w, 0));
    std::vector<std::tuple<int, int, int, int>> t;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> a[i][j];
            a[i][j] %= 2;
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w-1; j++) {
            if (a[i][j] == 1) {
                t.push_back(std::make_tuple(i+1, j+1, i+1, j+2));
                a[i][j+1] = (a[i][j+1] + 1) % 2;
                a[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < h-1; i++) {
        if (a[i][w-1] == 1) {
            t.push_back(std::make_tuple(i+1, w, i+2, w));
            a[i+1][w-1] = (a[i+1][w-1] + 1) % 2;
            a[i][w-1] = 0;
        }
    }

    std::cout << t.size() << std::endl;
    for (const auto& tt: t) {
        std::cout
            << std::get<0>(tt) << " "
            << std::get<1>(tt) << " "
            << std::get<2>(tt) << " "
            << std::get<3>(tt) << std::endl;
    }

    return 0;
}
