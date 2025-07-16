// 問題の URL を書いておく
// 

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

//#define ENABLE_PRINT

#if defined(ENABLE_PRINT)

#define Print(v) \
do {\
    cout << #v << ": " << v << endl; \
}while(0)

#define PrintVec(v) \
do {\
    for(int __i = 0; __i < v.size(); ++__i) \
    { \
        cout << #v << "[" << __i << "]: " << v[__i] << endl; \
    }\
}while(0)

#else

#define Print(v) ((void)0)
#define PrintVec(v) ((void)0)

#endif

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

using ll = int64_t;

int main(int, const char**)
{
    int n, m;
    cin >> n >> m;
    auto b = m / n;
    int ans = 1;
    for(int i = 1; i * i <= m; ++i)
    {
        if(m % i == 0)
        {
            int dd[] = {i, m / i};
            for(auto d : dd)
            {
                if(d <= b)
                {
                    ans = max(ans, d);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
