// AtCoder Beginner Contest 167 - Problem F: Bracketing Sequencing (https://atcoder.jp/contests/abc167/tasks/abc167_f)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

string solve(int N, const vector<string>& xs)
{
    vector<int> cs;
    vector<ii> ds, es;

    int open = 0, close = 0;

    for (int i = 0; i < N; ++i)
    {
        int a = 0, b = 0;

        for (auto c : xs[i])
        {
            open += (c == '(' ? 1 : 0);
            close += (c == ')' ? 1 : 0);

            b += (c == '(' ? 1 : -1);

            if (b < 0)
            {
                a--;
                b = 0;
            }
        }

        if (b + a >= 0)
            ds.push_back(ii(-a, i));
        else
            es.push_back(ii(b, i));
    }

    if (open != close)
        return "No";

    sort(ds.begin(), ds.end());
    sort(es.begin(), es.end(), greater<ii>());

    int s = 0;

    for (auto p : ds)
    {
        auto i = p.second;

        for (auto c : xs[i])
        {
            s += (c == '(' ? 1 : -1);

            if (s < 0)
                return "No";
        }
    }

    for (auto p : es)
    {
        auto i = p.second;

        for (auto c : xs[i])
        {
            s += (c == '(' ? 1 : -1);

            if (s < 0)
                return "No";
        }
    }


    return "Yes";
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<string> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, xs);

    cout << ans << '\n';

    return 0;
}
