#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, x;
    std::cin >> n >> x;

    std::vector<int> arr;
    arr.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        arr.push_back(tmp);
    }

    int64_t count = 0;
    if (arr[0] + arr[1] > x)
    {
        const int d = arr[0] + arr[1] - x;
        count += d;
        arr[1] = std::max(arr[1] - d, 0);
        // arr[0]はもう参照しないので編集しない
    }
    for (int i = 2; i < n; ++i)
    {
        const int d = arr[i - 1] + arr[i] - x;
        if (d > 0)
        {
            arr[i] -= d;
            count += d;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
