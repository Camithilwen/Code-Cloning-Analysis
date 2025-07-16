#include <bits/stdc++.h>
using namespace std;
int getDivCount(int);

int main()
{
    int N, A, tmp = 0;
    int res = 1;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> A;
        tmp = getDivCount(A);
        if (tmp == 0)
        {
            cout << tmp << endl;
            return 0;
        }
        res = i == 0 ? tmp : res > tmp ? tmp : res;
    }
    cout << res << endl;
}
int getDivCount(int num)
{
    int count = 0;
    while (num % 2 == 0)
    {
        num /= 2;
        ++count;
    }
    return count;
}
