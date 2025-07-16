#include <bits/stdc++.h>
using namespace std;
string str;
int main()
{
    cin >> str;
    int len = str.length();
    len = len - 8;
    for (int i = 0;i <= len-1;i++)
    {
        cout << str[i];
    }
    cout << endl;
    return 0;
}