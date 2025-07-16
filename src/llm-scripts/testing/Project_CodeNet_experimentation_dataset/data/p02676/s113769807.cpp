#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int k;
    string s, t = "...";
    cin >> k >> s;
    if(s.size() <= k)
        cout << s << '\n';
    else {
        for (int i = 0; i < k; ++i) {
            cout << s[i];

        }
        cout << t;
    }

}