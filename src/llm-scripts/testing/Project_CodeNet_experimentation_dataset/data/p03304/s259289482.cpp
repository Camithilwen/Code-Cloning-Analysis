#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;
#define MOD int(1e9 + 7)
#define INF (long long)(1e18)

int main()
{
    long double N, M, D;
    cin >> N >> M >> D;

    cout.precision(18);
    cout << ((D) ? 2 : 1) * (M - 1) * (N - D) / (N * N) << endl;
}