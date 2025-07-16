#include <iostream>
#include <algorithm>
#include <map>

const int lens = 1e5 + 1;
long long n,m,a[lens],sum[lens];
std::map<long long,long long> map;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> a[i];
    }   

    long long ans = 0;
    map[0]++; 
    for(int i = 1;i <= n;i++)
    {
        sum[i] = (sum[i - 1] + a[i]) % m;
        ans += map[sum[i]];
        map[sum[i]]++;
    }
    std::cout << ans;
    return 0;
}