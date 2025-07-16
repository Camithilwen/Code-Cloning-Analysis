#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m, a, b;
vector<int> g[N], ans(N + 1);

vector<int> minCircle(int s) {
    int d[N] = {0}, f[N] = {0};
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int p = q.front();q.pop();
        for(int c : g[p]) {
            if(!d[c]) {
                f[c] = p;
                d[c] = 1;
                q.push(c);
            }
        }
        if(d[s]) break;
    }
    int p = f[s];
    vector<int> ret;
    ret.push_back(s);
    while(p && p != s) {
        ret.push_back(p);
        p = f[p];
    }
    return ret;
}

int main() {
    cin >> n >> m;
    while(m--) {
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i = 1; i <= n; i++) {
        vector<int> t = minCircle(i);
        if(t.size() > 1 && t.size() < ans.size()) ans = t;
    }
    if(ans.size() == N + 1) cout << -1;
    else {
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
    }
}