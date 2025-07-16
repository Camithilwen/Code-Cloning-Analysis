#include <iostream>
#include <memory>
#include <cmath>

constexpr int max_size()
{
    return static_cast<int>(1e+6);
}

int insert(int* a, const int i, const int gear)
{
    if (i < gear) {
        return 0;
    }

    if (a[i - gear] <= a[i]) {
        return 0;
    }

    std::swap(a[i - gear], a[i]);
    return 1 + insert(a, i - gear, gear);
}

int insertion_sort(int* arr, const int n, const int gear)
{
    int insert_count = 0;
    for (int i = 0; i < n; i += gear) {
        insert_count += insert(arr, i, gear);
    }
    return insert_count;
}

int pow(const int a, const int x) {
    return x == 0 ? 1 : a * pow(a, x - 1);
}

void print(int* arr, const int n, char const delim) {
    int i = 0;
    for (; i < n - 1; ++i) {
        std::cout << arr[i] << delim;
    }
    std::cout << arr[i];
}

void shell_sort(int* arr, const int n) {
    static const double log3 = std::log(3);
    const int gear_index = static_cast<int>(std::log(2 * n + 1) / log3 - 1);
    int gear = (pow(3, gear_index + 1) - 1) >> 1;

    int gear_cache[100];
    int cache_idx = 0;
    int insert_count = 0;

    for (; gear > 0; gear = (gear - 1) / 3) {
        gear_cache[cache_idx] = gear;
        for (int i = 0; i < gear; ++i) {
            insert_count += insertion_sort(arr + i, n - i, gear);
        }
        ++cache_idx;
    }

    std::cout << cache_idx << std::endl;
    print(gear_cache, cache_idx, ' ');
    std::cout << std::endl;
    std::cout << insert_count << std::endl;

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    constexpr int N = max_size();
    const auto r = std::make_unique<int[]>(N);
    for (int i = 0; i < n; ++i) {
        std::cin >> r[i];
    }

    shell_sort(r.get(), n);
    print(r.get(), n, '\n');

    return 0;
}