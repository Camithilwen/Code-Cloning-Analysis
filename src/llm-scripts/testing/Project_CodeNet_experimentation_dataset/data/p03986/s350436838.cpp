#include <bits/stdc++.h>
using namespace std;

string s;
int sol, ans;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    sol = 0, ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'S') sol++;
        else {
            if(sol > 0) sol--;
            else ans++;
        }
    }
    cout << ans + sol << "\n";
}