#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

ll N, K;

ll solve(ll N);

int main()
{
    cin >> N >> K;
    cout << solve(N) << endl;
}

ll solve(ll N)
{
    if (N == 1)
    {
        return 2;
    }
    return min(solve(N - 1) * 2, solve(N - 1) + K);
}