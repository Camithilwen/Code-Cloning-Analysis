#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m, s, c;
    int ans = 0;
    vector<int> a(5, -1);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> s >> c;

        if (s == 1 && c == 0 && n != 1) ans = -1;
        
        if (a[s] == -1 || a[s] == c) a[s] = c;
        else ans = -1;
    }

    if (ans == -1) cout << ans << endl;
    else {
        if (a[1] == -1 && n != 1) a[1] = 1;
        for(int i = 1; i <= n; i++) {
            if (a[i] == -1) a[i] = 0;
            cout << a[i];
        }
        cout << endl;
    }
}