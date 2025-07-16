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

using P = pair<int, int>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector< pair<int, P> > st;
    rep (i, n)
    {
        int s, t, x;
        cin >> s >> t >> x;
        st.emplace_back(s - x, P{1, x});
        st.emplace_back(t - x, P{-1, x});
    }
    sort(st.begin(), st.end());

    multiset<int> ms;
    int idx = 0;
    rep (i, q)
    {
        int d;
        cin >> d;
        while (idx < st.size() && d >= st[idx].first)
        {
            if (st[idx].second.first == 1)
            {
                ms.insert(st[idx].second.second);
            }
            else
            {
                ms.erase(ms.find(st[idx].second.second));
            }
            ++idx;
        }

        if (ms.empty()) cout << "-1\n";
        else cout << *ms.begin() << "\n";
    }

    return 0;
}

