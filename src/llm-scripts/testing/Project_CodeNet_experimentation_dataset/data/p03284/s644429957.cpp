#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int Solve(int N, int K) {
        if (N % K == 0)
            return 0;
        else
            return 1;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    Solution s;
    cout << s.Solve(n, k) << endl;

    return 0;
}
