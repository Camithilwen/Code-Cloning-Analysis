#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int l, r, i, j, ans;

    scanf("%d%d", &l, &r);

    if (r - l >= 2019 || l % 2019 > r % 2019)
    {
        printf("0\n");
        return (0);
    }
    ans = 2019;
    i = l % 2019;
    while (i < r % 2019)
    {
        j = i + 1;
        while (j <= r % 2019)
        {
            if (ans > i * j % 2019)
                ans = i * j % 2019;
            j++;
        }
        i++;
    }

    printf("%d\n", ans);

    return 0;
}