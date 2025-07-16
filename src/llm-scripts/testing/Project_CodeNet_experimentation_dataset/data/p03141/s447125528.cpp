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
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <sstream>
#include <iomanip>
using lint = long long;

int main()
{

    lint n;
    scanf("%lld", &n);

    std::vector<lint> a(n);
    std::vector<lint> b(n);

    std::vector<std::pair<lint, lint>> ab(n);

    for (int i = 0; i < n; ++i)
    {
        lint a_e, b_e;
        scanf("%lld", &a_e);
        scanf("%lld", &b_e);

        a[i] = a_e;
        b[i] = b_e;
        ab[i] = std::make_pair(-a_e - b_e, i);
    }

    std::sort(ab.begin(), ab.end());

    lint ans_a = 0;
    lint ans_b = 0;
    for (int i = 0; i < n; ++i)
    {
        lint idx = ab[i].second;
        if (i % 2 == 0)
        {
            ans_a += a[idx];
        }
        else
        {
            ans_b += b[idx];
        }
    }

    printf("%lld", ans_a - ans_b);

    return 0;
}
