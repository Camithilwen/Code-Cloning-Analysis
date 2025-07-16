#include <bits/stdc++.h>
using namespace std;
using Int = long long;
array<Int, 18> POW10;
int main()
{
    POW10[0] = 1;
    for (int i = 1; i < POW10.size(); i++) POW10[i] = POW10[i-1] * 10;
    int D; cin >> D;
    int digits = 0;
    for (int val = 1; val <= D; val *= 10, digits++) {}
    Int ans = 0;
    for (int d = digits; d <= digits*2; d++) {
        vector<Int> A, S = {0};
        for (int k = d/2; k < d; k++) {
            A.push_back(POW10[k] - POW10[d-1-k]);
            S.push_back(S.back() + A.back());
        }
        function<void(int, Int, Int)> recur = [&](int idx, Int rest, Int acc) {
            int ten = (idx == A.size()-1 ? 9 : 10);
            if (idx == 0) {
                if (A[0] == 0) { if (rest == 0) ans += acc * ten; }
                else if (rest % A[0] == 0 && abs(rest / A[0]) <= 9) ans += acc * (ten - abs(rest / A[0]));
            } else {
                for (int i = -9; i <= 9; i++) {
                    Int r = rest - i * A[idx];
                    if (abs(r) <= abs(S[idx]*9)) recur(idx-1, r, acc * (ten - abs(i)));
                }
            }
        };
        recur(A.size()-1, D, 1);
    }
    cout << ans << '\n';
    return 0;
}