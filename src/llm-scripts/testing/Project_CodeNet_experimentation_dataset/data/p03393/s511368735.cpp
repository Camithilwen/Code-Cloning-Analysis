#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    string s;
    cin >> s;

    map<char, bool> a;
    REP(i, 26) a['a' + i] = false;
    int n = s.size();
    REP(i, n) a[s[i]] = true;

    int cnt = 0;
    for (auto i : a)
        if (i.second == true) cnt++;

    string ans;
    if (cnt != 26) {
        char c;
        for (auto i : a)
            if (i.second == false) { c = i.first; break ; }
        ans = s + c;
    } else if (cnt == 26) {
        int index = n - 1;
        for (int i = n - 1; i > 0; i--) {
            if (s[i - 1] - s[i] > 0) index = i - 1;
            else break ;
        }
        if (index == 0) ans = "-1";
        else {
            string tmp = s.substr(index);
            sort(tmp.begin(), tmp.end());
            char c;
            REP(i, tmp.size())
                if (tmp[i] > s[index - 1]) { c = tmp[i]; break ; }
            s.erase(index - 1);
            ans = s + c;
        }
    }

    cout << ans << '\n';
    return 0;
}
