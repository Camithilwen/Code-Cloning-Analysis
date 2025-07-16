#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    if (n % k == 0)
    {
        std::cout << 0 << endl;
        return 0;
    }
    std::cout << 1 << endl;

    return 0;
}