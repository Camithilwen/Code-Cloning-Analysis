#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int N; cin >> N;
    vector<double> as(N); for (auto &ai : as) cin >> ai;
    const double avg = accumulate(as.begin(), as.end(), 0.0) / static_cast<double>(N);
    map<double, int> diff2IndexMap;
    for (int i = N - 1; i >= 0; --i)
    {
        diff2IndexMap[abs(as[i] - avg)] = i;
    }
    cout << diff2IndexMap.begin()->second << endl;
}
