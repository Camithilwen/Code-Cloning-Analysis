#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <numeric>

using namespace std;

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;
typedef vector<s32> vs32;
typedef vector<u32> vu32;
typedef vector<s64> vs64;
typedef vector<u64> vu64;

const double PI=3.14159265358979323846;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 1000000007ULL

#define IN(l, r, x) ((l) <= (x) && (x) < (r))


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int cand[2] = {0, 1};
    rep (i, 2)
    {
        rep (j, 2)
        {
            bool ok = true;
            vs32 ans(n);
            ans[0] = cand[i];
            ans[1] = cand[j];
            for (int k = 2; k < n; ++ k)
            {
                ans[k] = ans[k - 1] ^ ans[k - 2] ^ (s[k - 1] == 'x');
            }
            if ((ans[0] == ans[n - 1] ^ ans[n - 2] ^ (s[n - 1] == 'x')) && (ans[n - 1] == ans[0] ^ ans[1] ^ (s[0] == 'x')))
            {
                rep (k, n)
                {
                    cout << (ans[k] ? 'W' : 'S');
                }
                cout << "\n";
                return 0;
            }
        }
    }

    cout << "-1\n";
    return 0;
}

