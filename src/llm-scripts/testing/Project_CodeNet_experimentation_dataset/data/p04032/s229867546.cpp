#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;

    cin >> s;

    bool flag = false;
    for(int i = 0; i < s.size()-1; ++i)
    {
        if(s[i] == s[i+1])
        {
            cout << i+1 << " " << i+2 << endl;
            return 0;
        }

        if(i+2 < s.size() && s[i] == s[i+2])
        {
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;

    return 0;
}

