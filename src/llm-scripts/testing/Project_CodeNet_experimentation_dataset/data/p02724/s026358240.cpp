#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
#include <iomanip>
#include <numeric>
#include <climits>
#include <algorithm>
#include <cstdint>
using namespace std;

int main()
{
    int x;
    cin >> x;

    int ans = 0;
    while (x > 4)
    {
        if (x - 500 >= 0)
        {
            x -= 500;
            ans += 1000;
        }
        else
        {
            if (x - 5 >= 0)
            {
                x -= 5;
                ans += 5;
            }
        }
    }

    cout << ans;
}