#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> sumW(n + 1, 0);
    REP(i, n) {
        if (s[i] == 'W') sumW[i + 1] = sumW[i] + 1;
        else sumW[i + 1] = sumW[i];
    }

    vector<int> sumE(n + 1, 0);
    REP(i, n) {
        if (s[i] == 'E') sumE[i + 1] = sumE[i] + 1;
        else sumE[i + 1] = sumE[i];
    }

    int mini = INT_MAX;
    REP(i, n + 1) {
        int toRight = sumW[i];
        int toLeft = sumE[n] - sumE[i];
        mini = min(mini, toRight + toLeft);
    }

    cout << mini << '\n';
    return 0;
}
