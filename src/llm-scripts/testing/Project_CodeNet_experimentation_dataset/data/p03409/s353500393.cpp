/*
    飲んだ魔剤で家が建つ。
    created at: 2020-04-19 14:53:28
                2020-04-19 16:16:46 余計な部分を削った版
*/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define INF 1000000000

bool compare_by_b(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> red(n), blue(n);
    for (int i = 0; i < n; i++)
        cin >> red[i].first >> red[i].second;
    for (int i = 0; i < n; i++)
        cin >> blue[i].first >> blue[i].second;

    sort(all(red), compare_by_b);
    reverse(all(red));

    sort(all(blue));

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pair<int, int> r = red[j];
            pair<int, int> b = blue[i];

            if (r.first < b.first && r.second < b.second) {
                // cout << r.first << "," << r.second << " " << b.first << "," << b.second << endl;
                ans++;
                red[j].second = INF;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
