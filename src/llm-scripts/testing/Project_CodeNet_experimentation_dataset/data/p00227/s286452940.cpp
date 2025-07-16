#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    while (cin >> N >> M, N) {
        vector<int> p(N);
        int sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> p[i];
            sum += p[i];
        }
        sort(p.begin(), p.end());
        for (int i = N - M; i >= 0; i -= M) {
            sum -= p[i];
        }
        cout << sum << endl;
    }
    return 0;
}