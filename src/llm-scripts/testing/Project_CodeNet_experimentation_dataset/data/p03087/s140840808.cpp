#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int a[N];
    a[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == 'C' && s[i - 1] == 'A')
        {
            a[i] = a[i - 1] + 1;
        }
        else
        {
            a[i] = a[i - 1];
        }
    }
    int l, r;
    rep(i, q)
    {
        cin >> l >> r;
        cout << a[r - 1] - a[l - 1] << endl;
    }
    return 0;
}