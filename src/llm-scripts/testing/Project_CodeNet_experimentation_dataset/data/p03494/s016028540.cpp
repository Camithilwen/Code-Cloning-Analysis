#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, cnt = 0;
    cin >> N;
    vector<long long> vec(N);

    for (int i = 0; i < N; i++) {
        cin >> vec[i];
        if (vec[i] % 2 != 0) {
            cout << cnt << endl;
            return 0;
        }
    }

    while (true) {
        for (int i = 0; i < N; i++) {
            if (vec[i] % 2 != 0) {
                cout << cnt << endl;
                return 0;
            } else {
                vec[i] /= 2;
            }
        }
        cnt++;
    }
}