#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <numeric>
using lint = long long;

int main()
{

    lint h, w, a, b;

    scanf("%lld", &h);
    scanf("%lld", &w);
    scanf("%lld", &a);
    scanf("%lld", &b);

    for (int i = 0; i < h; ++i)
    {
        if (i < h - b)
            printf("%s\n", (std::string((w - a), '1') + std::string(a, '0')).c_str());
        else
            printf("%s\n", (std::string((w - a), '0') + std::string(a, '1')).c_str());
    }
    return 0;
}
