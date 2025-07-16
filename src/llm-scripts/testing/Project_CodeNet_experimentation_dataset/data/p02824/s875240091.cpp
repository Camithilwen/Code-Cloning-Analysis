#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, V, P;
    int64_t M;
    cin >> N >> M >> V >> P;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }

    sort(A.rbegin(), A.rend());
    int Ab = A.at(P - 1);

    int64_t acc = 0;
    vector<int64_t> diff(N);
    for (int i = P; i < N; i++)
    {
        acc += Ab - A.at(i);
        diff.at(i) = acc;
    }

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        if (i < P)
        {
            res++;
            continue;
        }
        int64_t Ai_mx = A.at(i) + M;
        if (Ai_mx >= Ab && V - P <= N - i - 1)
        {
            res++;
            continue;
        }
        int64_t v = M * (V - P - (N - i - 1));
        int64_t d = diff.at(i - 1);
        int Ab_mn = Ab;
        if (v > d)
        {
            v -= d;
            int n = i - (P - 1);
            Ab_mn += (v + n - 1) / n;
        }
        if (Ai_mx >= Ab_mn)
        {
            res++;
        }
    }
    cout << res << endl;
}