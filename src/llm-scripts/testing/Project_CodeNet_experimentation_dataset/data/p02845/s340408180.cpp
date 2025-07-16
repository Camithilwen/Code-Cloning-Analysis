#include <bits/stdc++.h>
using namespace std;

int main()
{
    const static int64_t mod = 1000000007;
    int N;
    cin >> N;
    vector<int> A_vec(N);
    for (int i = 0; i < N; ++i)
        cin >> A_vec.at(i);
    vector<int> x_vec(N + 1, 0), y_vec(N + 1, 0), z_vec(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        int A = A_vec.at(i);
        x_vec.at(i + 1) = x_vec.at(i);
        y_vec.at(i + 1) = y_vec.at(i);
        z_vec.at(i + 1) = z_vec.at(i);
        if (A == x_vec.at(i))
            ++x_vec.at(i + 1);
        else if (A == y_vec.at(i))
            ++y_vec.at(i + 1);
        else if (A == z_vec.at(i))
            ++z_vec.at(i + 1);
        else {
            cout << 0 << endl;
            return 0;
        }
    }
    int64_t cnt = 1;
    for (int i = 0; i < N; ++i) {
        int64_t tmp = 0;
        int A = A_vec.at(i);
        if (A == x_vec.at(i)) ++tmp;
        if (A == y_vec.at(i)) ++tmp;
        if (A == z_vec.at(i)) ++tmp;
        cnt = cnt * tmp % mod;
    }
    cout << cnt << endl;
}


