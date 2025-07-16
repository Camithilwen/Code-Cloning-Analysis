#include <bits/stdc++.h>
using namespace std;

int main()
{
    string N;
    cin >> N;
    bool flag = false;
    for (int i = 0; i < 3; i++)
    {
        if (N[i] == '7')
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }
    return 0;
}