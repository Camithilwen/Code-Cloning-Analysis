#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int, bool> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(m[a]) m.erase(a);
        else m[a] = true;
    }
    cout << m.size() << "\n";
}
