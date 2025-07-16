#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    int cnt = 0;
    queue<pii> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                cnt++;
                q.push(pii(i,j));
            }
        }
    }
    if (cnt == h*w) {
        cout << 0 << endl;
        return 0;
    }

    auto f = [&] (int y, int x) {
        cnt++;
        s[y][x] = '#';
        q.push(pii(y, x));
    };
    for (int i = 1; 1; i++) {
        int j = q.size();
        for (int k = 0; k < j; k++) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            if (a>0)   if (s[a-1][b]=='.') f(a-1,b);
            if (a<h-1) if (s[a+1][b]=='.') f(a+1,b);
            if (b>0)   if (s[a][b-1]=='.') f(a,b-1);
            if (b<w-1) if (s[a][b+1]=='.') f(a,b+1);
        }
        if (cnt == h*w) {
            cout << i << endl;
            return 0;
        }
    }
}