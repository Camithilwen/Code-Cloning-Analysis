#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> memo;
    while (n)
    {
        int r = n % (-2);
        if (r < 0)
            r *= -1;
        n = (n - r) / -2;
        memo.push_back(r);
        if (n == 0)
        {
            break;
        }
    }

    string ans;
    for (int i = memo.size() - 1; i >= 0; i--)
    {
        ans += to_string(memo[i]);
    }
    if (ans == "")
        ans = "0";
    cout << ans << endl;
    return 0;
}