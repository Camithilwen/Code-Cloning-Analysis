#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, string> P;

string s;

void dfs(int i, int end, const string& lTemp, const string& rTemp, vector<P> &x)
{
    if (i == end)
    {
        x.push_back(make_pair(lTemp, rTemp));
        return;
    }

    dfs(i + 1, end, lTemp + s[i], rTemp, x);
    dfs(i + 1, end, lTemp, s[i] + rTemp, x);
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
    auto ir_lower = vr.begin();
    for (auto il = vl.begin(); il < vl.end(); ++il)
    {
        ir_lower = lower_bound(ir_lower, vr.end(), *il);
        auto ir_upper = upper_bound(ir_lower, vr.end(), *il);

        score += ir_upper - ir_lower;
    }

    cout << score << endl;
    return 0;
}
