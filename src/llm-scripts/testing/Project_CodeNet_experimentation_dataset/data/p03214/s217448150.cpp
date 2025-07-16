#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define int long long
const int N = 1e6;

int n;
int a[N], s;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i] * n - s) < abs(a[ans] * n - s)) ans = i;
    }
    cout << ans;
}
