#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin >> S;
    int N = S.size();
    int count = 0;
    if (S[0] == 'A' && S[1] >= 'a' && S[1] <= 'z' && S[N - 1] >= 'a' && S[N - 1] <= 'z')
    {
        for (int i = 2; i < N; i++)
        {
            if (S[i] >= 'a' && S[i] <= 'z')
            {
                continue;
            }
            else if (S[i] == 'C')
            {
                count++;
            }
            else
            {
                cout << "WA" << endl;
                return 0;
            }
        }
    }
    else
    {
        cout << "WA" << endl;
        return 0;
    }
    if (count == 1)
    {
        cout << "AC" << endl;
    }
    else
    {
        cout << "WA" << endl;
    }
}