#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> as(n);
    int sum = 0;
    for (auto& a : as)
    {
        cin >> a;
        sum += a;
    }
    int min_diff = numeric_limits<int>::max();
    int min_index = -1;
    for (int i = 0; i < n; i++)
    {
        auto diff = abs(sum - as[i] * n);
        if (min_diff > diff)
        {
            min_diff = diff;
            min_index = i;
        }
    }
    cout << min_index << endl;
}
