#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N+2, 0);
    for(int i=1;i<=N;i++){
        cin >> A[i];
    }
    int sum = 0;
    for(int i=0;i<N+1;i++){
        sum += abs(A[i+1] - A[i]);
    }
    for(int i=1;i<N+1;i++){
        auto res = sum;
        res -= abs(A[i+1] - A[i]);
        res -= abs(A[i] - A[i-1]);
        res += abs(A[i+1] - A[i-1]);
        cout << res << endl;
    }

    return 0;
}