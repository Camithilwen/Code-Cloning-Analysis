#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

using namespace std;

typedef long long ll;

const int match[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    int N, M;
    cin >> N >> M;
    int A[M];
    REP(i, M)
    {
        cin >> A[i];
        A[i]--;
    }

    vector<array<int, 9>> dp(N + 1, {0});
    bool isMake[N + 1] = {false};
    isMake[0] = true;
    for (int i = 1; i <= N; ++i)
    {
        vector<array<int, 9>> candidate;
        REP(j, M)
        {
            if (i - match[A[j]] >= 0)
            {
                if (isMake[i - match[A[j]]])
                {
                    array<int, 9> current = dp[i - match[A[j]]];
                    current[A[j]]++;
                    candidate.push_back(current);
                    isMake[i] = true;
                }
            }
        }
        if (isMake[i])
        {
            array<int, 9> maxArray = {0};
            int countMaxSet = 0;
            for (auto iter = candidate.begin(); iter != candidate.end(); ++iter)
            {
                int count = 0;
                REP(j, 9) count += (*iter)[j];
                if (count != countMaxSet)
                {
                    if (count > countMaxSet)
                    {
                        countMaxSet = count;
                        maxArray = *iter;
                    }
                }
                else
                {
                    for (int j = 8; j >= 0; --j)
                    {
                        if (maxArray[j] > (*iter)[j]) 
                        {
                            break;
                        }
                        else if (maxArray[j] < (*iter)[j])
                        {
                            maxArray = *iter;
                            break;
                        }
                    }
                }
            }
            dp[i] = maxArray;
        }
    }

    for(int i = 8; i >= 0; --i) REP(j, dp[N][i]) cout << i + 1;
}
