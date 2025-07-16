#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, string> P;

string s;

void dfs(int i, int end, const string lTemp, const string rTemp, vector<P> &x)
{
    if (i == end)
    {
        x.push_back(make_pair(lTemp, rTemp));
        return;
    }

    dfs(i + 1, end, lTemp + s[i], rTemp, x);
    dfs(i + 1, end, lTemp, s[i] + rTemp, x);
}

bool compare(const P l, const P r)
{
    return l.first == r.first ? l.second < r.second : l.first < r.first;
}

int main(void)
{
    int n;
    cin >> n;
    cin >> s;
    reverse(s.begin() + n, s.end());

    vector<P> vl;
    vector<P> vr;
    dfs(0, n, "", "", vl);
    dfs(n, 2 * n, "", "", vr);
    sort(vl.begin(), vl.end());
    sort(vr.begin(), vr.end());

    long long score = 0;
    for (auto ia = vl.begin(); ia < vl.end(); ++ia)
    {
        auto ib_upper = upper_bound(vr.begin(), vr.end(), *ia);
        auto ib_lower = lower_bound(vr.begin(), vr.end(), *ia);
        score += ib_upper - ib_lower;
    }

    cout << score << endl;
    return 0;
}
