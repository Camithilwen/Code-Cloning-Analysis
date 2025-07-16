#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end(), std::greater<int>());
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += a[i];
    }

    std::cout << ans << "\n";
}