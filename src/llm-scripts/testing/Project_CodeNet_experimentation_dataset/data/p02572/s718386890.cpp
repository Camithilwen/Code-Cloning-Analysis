#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int N, i, div, result;
    cin >> N;
    vector<long long int> A_sum(N);
    vector<long long int> A(N);
    div = 1;
    for (i = 0; i < 9; i++)
    {
        div *= 10;
    }
    div += 7;
    for (i = 0; i < N; i++)
    {
        cin >> A[i];
        A[i] = A[i] % div;
    }
    A_sum[N - 1] = A[N - 1];
    for (i = N - 2; i > 0; i--)
    {
        A_sum[i] = A_sum[i + 1] + A[i];
        A_sum[i] = A_sum[i] % div;
    }
    result = 0;
    for (i = 0; i < N - 1; i++)
    {
        result += A[i] * A_sum[i + 1];
        result = result % div;
    }
    cout << result << endl;
    return 0;
}