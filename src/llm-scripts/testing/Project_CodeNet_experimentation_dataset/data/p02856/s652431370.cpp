#include <bits/stdc++.h>
using namespace std;

int	main()
{
    int M;
    cin >> M;
    vector<int64_t> d_vec(M), c_vec(M);
    for (int i = 0; i < M; ++i)
        cin >> d_vec.at(i) >> c_vec.at(i);
    int64_t sum_digit = 0;
    int64_t num_digit = 0;
    for (int i = 0; i < M; ++i) {
        sum_digit += d_vec.at(i) * c_vec.at(i);
        num_digit += c_vec.at(i);
    }
    cout << num_digit - 1 + (sum_digit - 1) / 9 << endl;
}
