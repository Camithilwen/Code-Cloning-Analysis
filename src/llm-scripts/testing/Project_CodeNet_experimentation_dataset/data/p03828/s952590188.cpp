#include <bits/stdc++.h>
using namespace std;

long long MOD = pow(10, 9) + 7;

// O(sqrt(N))の素因数分解
int main(){
    int Q;
    cin >> Q;
    vector<int> bucket(Q+1, 1);

    if (Q == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 2; i <= Q; i++)
    {
        int target = i;
        for (int j = 2; j <= i; j++)
        {
            if (target % j != 0)
            {
                continue;
            }
            
            while (target % j == 0)
            {
                bucket[j]++;
                target /= j;
            }
        }
    }
    long long ans = 1;
    for (int j = 0; j <= Q; j++)
    {
        ans *= bucket[j];
        ans = ans % MOD;
    }
    cout << ans << endl;
    return 0;
}
