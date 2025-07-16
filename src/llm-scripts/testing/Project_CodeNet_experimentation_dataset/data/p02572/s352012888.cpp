#include <iostream>
#include <algorithm>
#include <cmath>

const int lens = 2e5 + 1;
const long long mod = 1e9 + 7;

long long a[lens],sum[lens];
int main()
{
    int n;
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    
    long long ans = 0;
    for(int i = 1;i <= n;i++)
    {
        ans = (ans + (((sum[n] - sum[i]) % mod) * (a[i] % mod)) % mod) % mod;
    }
    std::cout << ans;
    return 0;
}

