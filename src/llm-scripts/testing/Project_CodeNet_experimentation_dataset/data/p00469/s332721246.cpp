#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> v;
set<string> s;

void dfs(string str, int flag, int count) {
    if (count == k) {
        s.insert(str);
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (flag & (1 << i)) continue;
        dfs(str + v[i], flag | (1 << i), count + 1);
    }
}

int main() {
    while (cin >> n >> k, n || k) {
        v.resize(0);
        for (int i = 0; i < n; i++) {
            string str;
            cin  >> str;
            v.push_back(str);
        }

        s.clear();
        dfs("", 0, 0);
        cout << s.size() << endl;
    }

    return 0;
}