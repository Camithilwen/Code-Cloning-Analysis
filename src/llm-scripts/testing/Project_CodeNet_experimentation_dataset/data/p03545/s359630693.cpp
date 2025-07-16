#include <bits/stdc++.h> 
using namespace std;

int s[5];
char op[5];

void solve(int index, int cur_sum) {
    if (index == 3) {
        if (cur_sum == 7) {
            for(int i = 0; i < 4; ++i) {
                if (i > 0) cout << op[i];
                cout << s[i];
            }
            cout << "=7";
            exit(0);
        }
        return;
    }
    // +
    op[index + 1] = '+';
    solve(index + 1, cur_sum+s[index + 1]);        

    //-
    op[index + 1] = '-';
    solve(index + 1, cur_sum-s[index + 1]);   
}

int main () {
    for(int i = 0; i < 4; ++i) {
        char ch; cin >> ch;
        s[i] = ch - '0';
    }
    solve(0, s[0]);
}
