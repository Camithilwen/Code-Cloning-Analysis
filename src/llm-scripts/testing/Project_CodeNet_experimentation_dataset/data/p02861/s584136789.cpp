#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    double x[10], y[10], ans = 0.0, count = 0.0;
    cin >> n;
    vector<int> num(n);
    rep(i, n) cin >> x[i] >> y[i];
    rep(i, n) num[i] = i;
    do
    {
        for (int i = 1; i < n; i++)
        {
            ans += sqrt(pow(x[num[i]] - x[num[i - 1]], 2) + pow(y[num[i]] - y[num[i - 1]], 2));
        }
        count++;
    } while (next_permutation(num.begin(), num.end()));
    cout << fixed << setprecision(10) <<ans / count << endl;
    return 0;
}