#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e6 + 10, MAX = 30;
int n;
string s, t;
vector <int> indx[MAX];
int nxt[MAXN];
bitset <MAXN> b;

int32_t main () {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    cin >> n >> s >> t;
    
    for (int i = 0; i < n; ++i)
        indx[s[i] - 'a'].push_back(i);
    
    int point = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        while (!indx[t[i] - 'a'].empty() && (indx[t[i] - 'a'].back() > point || indx[t[i] - 'a'].back() > i))
            indx[t[i] - 'a'].pop_back();
        if (indx[t[i] - 'a'].empty())
            return cout << -1, 0;
        int k = indx[t[i] - 'a'].back();
        point = k;
        if (!b[k])
            nxt[k] = i; 
        b[k] = true;
    }

    vector <pair <int, int>> vctr;
    for (int i = 0; i < n; ++i)
        if (b[i] && i != nxt[i])
            vctr.push_back({i, nxt[i]});
    // for (auto i : vctr)
    //     cout << i.first << ';' << i.second << ' ';
    int res = 0;
    int sz = vctr.size();
    point = sz - 1;
    for (int i = sz - 1; i >= 0; --i) {
        while (point > i && vctr[point].first - point + i >= vctr[i].second)
            --point;
        res = max(res, point - i + 1);
    }
    cout << res;
    return 0;
}