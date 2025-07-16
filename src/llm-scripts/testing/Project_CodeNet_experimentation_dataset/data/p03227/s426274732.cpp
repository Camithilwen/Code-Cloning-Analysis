#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    string s;
    cin >> s;
    if(s.size() == 2)
    {
        cout << s << "\n";
    }
    else
    {
        for(int i = s.size() - 1;i >= 0;i--)
        {
            cout << s[i];
        }
        cout << "\n";
    }
    
    return 0;
}